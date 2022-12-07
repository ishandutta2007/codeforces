#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=500005;
int n,m,a[N],p[N],b[N];
int id[N];
map<int,int> mp;
vector<int> lv[N];
ll f[N],t[N];
bool cmp(int x,int y){
	return a[x]<a[y];
}
void change(int k,int v){
	for (;k<=n;k+=k&(-k)) t[k]+=v;
}
ll ask(int k){
	ll s=0;
	for (;k;k-=k&(-k)) s+=t[k];
	return s;
}
void solve(){
	memset(f,233,sizeof(f));
	for (auto i:lv[1]) f[i]=p[i];
	int t=1;
	For(i,1,m){
		for (;t<=n&&a[id[t]]<=b[i];++t)
			if (p[id[t]]>0) change(id[t],p[id[t]]);
		int pos=0,x;
		ll val=-(1ll<<60);
		for (auto j:lv[i+1]){
			for (;pos<lv[i].size()&&(x=lv[i][pos])<j;++pos)
				val=max(val,f[x]-ask(x));
			f[j]=val+ask(j)+p[j];
			//cout<<"Func "<<j<<' '<<f[j]<<endl;
		}
	}
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) scanf("%d",&p[i]);
	scanf("%d",&m);
	For(i,1,m) scanf("%d",&b[i]);
	a[++n]=b[++m]=1<<30;
	For(i,1,m) mp[b[i]]=i;
	For(i,1,n) if (mp[a[i]]) lv[mp[a[i]]].PB(i);
	For(i,1,n) id[i]=i;
	sort(id+1,id+n+1,cmp);
	solve();
	if (f[n]<-1e15)
		puts("NO");
	else{
		puts("YES");
		ll ans=-f[n];
		For(i,1,n) ans+=p[i];
		printf("%lld\n",ans);
	}
}
/*
11
4 1 3 3 7 8 7 9 10 7 11
3 5 0 -2 5 3 6 7 8 2 4
3
3 7 10
*/