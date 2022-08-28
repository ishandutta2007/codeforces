//CF 506D_2
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5+15;
const int W = 400;
int n,m,q,d[N],f[N*2];
vector<int> v[N];
unordered_map<LL,int> M,ans;
int fnd(int x){
	if(f[x]==x)
		return x;
	return f[x]=fnd(f[x]);
}
int main()
{
	int i,x,y,z,s;
	LL xx,yy,t;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m+m;i=i+1)
		f[i]=i;
	s=0;
	for(i=1;i<=m;i=i+1){
		scanf("%d%d%d",&x,&y,&z);
		v[x].push_back(z);
		v[y].push_back(z);
		xx=(LL)x*N+z;
		yy=(LL)y*N+z;
		if(M.find(xx)==M.end())
			M[xx]=++s;
		if(M.find(yy)==M.end())
			M[yy]=++s;
		f[fnd(M[xx])]=fnd(M[yy]);
	}
	for(i=1;i<=n;i=i+1){
		sort(v[i].begin(),v[i].end());
		d[i]=unique(v[i].begin(),v[i].end())-v[i].begin();
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&x,&y);
		if(d[x]>d[y]||(d[x]==d[y]&&x>y))
			swap(x,y);
		//if(m==99681&&x==1)
		//	cout<<d[x]<<'0'<<y<<'0'<<d[y]<<endl,exit(0);
		t=(LL)x*N+y;
		if(ans.find(t)!=ans.end())
			cout<<ans[t]<<endl;
		else{
			s=0;
			for(i=0;i<d[x];i=i+1){
				z=v[x][i];
				if(!z)
					break;
				xx=(LL)x*N+z;
				yy=(LL)y*N+z;
				if(M.find(yy)!=M.end()&&fnd(M[xx])==fnd(M[yy]))
					s++;
			}
			cout<<s<<endl;
			ans[t]=s;
		}
	}
	return 0;
}