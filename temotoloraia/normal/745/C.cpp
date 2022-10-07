#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1005,M=100005;
ll n,m,k,parent[N];
int u,v;
ll c[N],ind[N];
ll x,y;
ll maxx,in;
ll zoma[N],ans;
vector<ll>g[N];
ll pp (ll k)
{
	if (parent[k]==k)return k;
	return parent[k]=pp(parent[k]);
}
int main(){
	cin>>n>>m>>k;
	for (int i=1;i<=k;i++){
	cin>>c[i];
	ind[c[i]]=1;
	}
	for (int i=1;i<=n;i++){
		parent[i]=i;
		zoma[i]=1;
	}
	for (int i=1;i<=m;i++){
		//cin>>u>>v;
		scanf("%d%d",&u,&v);
		x=pp(u);
		y=pp(v);
		if (ind[y])swap(x,y);
		if (x==y)continue;
		zoma[x]+=zoma[y];
		parent[y]=x;
	}
	x=0;
	for (int i=1;i<=k;i++)
	if  (zoma[c[i]]>maxx){
		maxx=zoma[c[i]];
		x=c[i];
	}
	for (int i=1;i<=n;i++)
	if (parent[i]==i && ind[i]==0){
		zoma[x]+=zoma[i];
		parent[i]=x;	
	}
	ans=-m;
	for (int i=1;i<=k;i++){
	ans+=zoma[c[i]]*(zoma[c[i]]-1)/2;
	//cout<<zoma[c[i]]<<endl;
	}
	cout<<ans<<endl;
	return 0;
}