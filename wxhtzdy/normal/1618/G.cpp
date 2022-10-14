#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second
const int N=200050;
int n,m,q,a[N],b[N],p[2*N],f[2*N],L[2*N],R[2*N];
ll s[2*N],ans[N];
map<int,vector<int>> Qs;
int find(int i){
	return f[i]==i?i:f[i]=find(f[i]);
}
int main(){
	scanf("%i%i%i",&n,&m,&q);
	vector<pair<int,int>> vec;
	for(int i=1;i<=n;i++)scanf("%i",&a[i]),vec.pb({a[i],0});
	for(int i=1;i<=m;i++)scanf("%i",&b[i]),vec.pb({b[i],1});
	sort(vec.begin(),vec.end());
	for(int i=0;i<n+m;i++){
		if(i>0)p[i]=p[i-1],s[i]=s[i-1];
		if(vec[i].se==0)p[i]++;
		s[i]+=vec[i].fi;
	}
	auto Calc=[&](int l,int r){
		int x=p[r]-(l==0?0:p[l-1]);
		return s[r]-(r-x<0?0LL:s[r-x]);
	};
	for(int i=1;i<=q;i++){
		int k;
		scanf("%i",&k);
		Qs[k].pb(i);
	}
	long long curr=0;
	for(int i=0;i<n+m;i++)curr+=Calc(i,i);
	for(int i=0;i<n+m;i++)f[i]=L[i]=R[i]=i;
	vector<pair<int,int>> diff;
	for(int i=0;i+1<n+m;i++)diff.pb({vec[i+1].fi-vec[i].fi,i});
	sort(diff.begin(),diff.end());
	int ptr=0;
	for(auto v:Qs){
		int k=v.fi;
		while(ptr<diff.size()&&diff[ptr].fi<=k){
			int x=diff[ptr].se;
			int y=diff[ptr].se+1;
			x=find(x);
			y=find(y);
			if(x!=y){
				curr-=Calc(L[x],R[x]);
				curr-=Calc(L[y],R[y]);
				L[x]=min(L[x],L[y]);
				R[x]=max(R[x],R[y]);
				curr+=Calc(L[x],R[x]);
				f[y]=x;
			}
			ptr++;
		}
		for(int j:v.se)ans[j]=curr;
	}
	for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
	return 0;
}