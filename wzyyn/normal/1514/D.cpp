#include<bits/stdc++.h>
using namespace std;

const int N=300005;
int n,Q,a[N],nn;
pair<int,int> t[N*4];
vector<int> v[N];
pair<int,int> add(pair<int,int> a,pair<int,int> b){
	if (a.second<b.second)
		swap(a,b);
	if (a.first==b.first){
		a.second+=b.second;
		return a;
	}
	a.second-=b.second;
	return a;
}
void build(){
	for (nn=1;nn<=n;nn<<=1);
	for (int i=1;i<=n;i++)
		t[i+nn]=pair<int,int>(a[i],1);
	for (int i=nn-1;i;i--)
		t[i]=add(t[i*2],t[i*2+1]);
}
pair<int,int> ask(int l,int r){
	pair<int,int> ans(0,0);
	l+=nn-1; r+=nn+1;
	for (;l^r^1;l>>=1,r>>=1){
		if (!(l&1)) ans=add(ans,t[l^1]);
		if (r&1)	ans=add(ans,t[r^1]);
	}
	return ans;
}
int main(){
	srand(time(NULL));
	scanf("%d%d",&n,&Q);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		v[a[i]].push_back(i);
	build();
	while (Q--){
		int l,r;
		scanf("%d%d",&l,&r);
		int m=ask(l,r).first;
		int pl=lower_bound(v[m].begin(),v[m].end(),l  )-v[m].begin();
		int pr=lower_bound(v[m].begin(),v[m].end(),r+1)-v[m].begin();
		if (2*(pr-pl)>=(r-l+1)+1) printf("%d\n",2*(pr-pl)-(r-l+1));
		else puts("1");
	}
}