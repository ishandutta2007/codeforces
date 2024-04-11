//CF 891C
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
const int N = 500005;
int f[N],g[N];
int h[N*5],sh;
int fndf(int x){
	h[++sh]=x;
	if(f[x]==x)
		return x;
	return f[x]=fndf(f[x]);
}
int fndg(int x){
	if(g[x]==x)
		return x;
	return g[x]=fndg(g[x]);
}
int n,m,q;
int x[N],y[N],z[N];
vector<int> p[N];
vector<pair<int,int> > v[N];
int ans[N];
int main()
{
	int i,j,sp,sv,t,r,o;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i=i+1){
		scanf("%d%d%d",x+i,y+i,z+i);
		p[z[i]].push_back(i);
	}
	scanf("%d",&q);
	for(i=1;i<=q;i=i+1){
		scanf("%d",&o);
		for(j=1;j<=o;j=j+1){
			scanf("%d",&t);
			v[z[t]].push_back(make_pair(i,t));
			//cout<<z[t]<<' '<<i<<' '<<t<<endl;
		}
	}
	for(i=1;i<=n;i=i+1)
		f[i]=i,g[i]=i;
	for(i=1;i<=5e5;i=i+1){
		sv=v[i].size();
		sort(v[i].begin(),v[i].end());
		for(j=0;j<sv;){
			r=v[i][j].first;
			sh=0;
			while(j<sv&&v[i][j].first==r){
				t=v[i][j].second;
				//cout<<t<<' ';
				if(fndf(x[t])==fndf(y[t]))
					ans[r]=1;
				else
					f[f[x[t]]]=f[y[t]];
				/*h[++sh]=(f[x[t]]);
				h[++sh]=(f[y[t]]);
				h[++sh]=(x[t]);
				h[++sh]=(y[t]);*/
				j++;
			}
			//cout<<r<<endl;
			for(t=0;t<sh;t=t+1)
				f[h[t]]=g[h[t]];
		}
		sp=p[i].size();
		for(j=0;j<sp;j=j+1){
			t=p[i][j];
			//cout<<t<<endl;
			g[fndg(x[t])]=fndg(y[t]);
			f[fndf(x[t])]=fndf(y[t]);
		}
	}
	for(i=1;i<=q;i=i+1){
		if(ans[i])
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
	return 0;
}