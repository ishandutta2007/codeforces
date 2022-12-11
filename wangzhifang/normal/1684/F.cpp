#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int mod=998244353;
template<int mod=::mod>ll quickpow(ll x,int k,ll ret=1){
	for(; k; k>>=1,x=x*x%mod)
		(k&1)&&(ret=ret*x%mod);
	return ret;
}
constexpr int max_n=200000;
int a[max_n+1],pr[max_n+1];
vector<int> pos[max_n];
int top[max_n];
void test(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		scanf("%d",a+i);
	memcpy(pr,a+1,n<<2);
	sort(pr,pr+n);
	int*const ed=unique(pr,pr+n);
	for(int i=1; i<=n; ++i)
		a[i]=lower_bound(pr,ed,a[i])-pr;
	for(int i=1; i<=n; ++i)
		pr[i]=i;
	for(int i=1,l,r; i<=m; ++i){
		scanf("%d%d",&l,&r);
		if(l<pr[r])
			pr[r]=l;
	}
	for(int i=n; i>1; --i)
		if(pr[i]<pr[i-1])
			pr[i-1]=pr[i];
	for(int i=0; i<n; ++i)
		pos[i].clear(),top[i]=0;
	vector<array<int,4> >f;
	for(int i=1; i<=n; ++i){
		const int v=a[i];
		pos[v].emplace_back(i);
		while(pos[v][top[v]]<pr[i])
			++top[v];
		const int p=pos[v].size()-1;
		if(top[v]!=p)
			f.emplace_back(array<int,4>{pos[v][top[v]],pos[v][p-1],pos[v][top[v]+1],pos[v][p]});
	}
	if(f.empty()){
		puts("0");
		return;
	}
	sort(f.begin(),f.end());
	int r=1,ans=n;
	for(const array<int,4>&it:f)
		if(it[1]>r)
			r=it[1];
	vector<array<int,4> >::iterator it=f.begin();
	for(int l=1,ed=n; l<=ed; ++l){
		while(it!=f.end()&&(*it)[0]<l){
			if((*it)[3]>r)
				r=(*it)[3];
			if((*it)[2]<ed)
				ed=(*it)[2];
			++it;
		}
//		fprintf(stderr,"%d: %d\n",l,r);
		if(r-l+1<ans)
			ans=r-l+1;
	}
	printf("%d\n",ans);
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}