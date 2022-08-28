// CF 846D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int N = 555;
const int inf = 1e9+N;
int a[N][N],b[N];
set<pair<int,int> > S[N],P;
int main()
{
	int n,m,k,q,i,j,x,y,t,ans;
	cin>>n>>m>>k>>q;
	for(i=1;i<=n;i=i+1)
		for(j=1;j<=m;j=j+1)
			a[i][j]=inf;
	while(q--){
		cin>>x>>y>>t;
		a[x][y]=min(a[x][y],t);
	}
	for(i=1;i<=n;i=i+1){
		for(j=1;j<=k;j=j+1)
			S[i].insert(make_pair(a[i][j],j));
		b[i]=(*S[i].rbegin()).first;
	}
	ans=inf;
	for(j=1;j+k-1<=m;j=j+1){
		P.clear();
		for(i=1;i<=n;i=i+1){
			P.insert(make_pair(b[i],i));
			if(i>k)
				P.erase(make_pair(b[i-k],i-k));
			if(i>=k)
				ans=min(ans,(*P.rbegin()).first);
		}
		if(j+k>m)
			break;
		for(i=1;i<=n;i=i+1){
			S[i].erase(make_pair(a[i][j],j));
			S[i].insert(make_pair(a[i][j+k],j+k));
			b[i]=(*S[i].rbegin()).first;
		}
	}
	if(ans==inf)
		ans=-1;
	cout<<ans<<endl;
	return 0;
}