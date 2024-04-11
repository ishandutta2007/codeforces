//CF1394D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 222222;
void cmax(LL&x,LL y){
	if(x<y)
		x=y;
}
int n,t[N],h[N],vis[N];
vector<int> v[N];
LL ss,f[N],g[N],b[N];
void dfs(int x){
	vis[x]=1;
	int sz=v[x].size(),i,j,y,p=0,q=0,e=0;
	vector<LL> r;
	LL w=0;
	for(i=0;i<sz;i=i+1){
		y=v[x][i];
		if(h[x]==h[y]){
			if(vis[y])
				continue;
			dfs(y);
			w+=f[y];
			r.push_back(g[y]-f[y]);
			e++;
		}
		else{
			if(h[x]<h[y])
				p++;
			else
				q++;
		}
	}
	sort(r.begin(),r.end()); 
	f[x]=0,g[x]=0,b[x]=0;
	i=e,j=0;
	while(1){
		cmax(f[x],w+(LL)t[x]*min(p+i,q+j+1));
		cmax(g[x],w+(LL)t[x]*min(p+i+1,q+j));
		cmax(b[x],w+(LL)t[x]*min(p+i,q+j));
		i--;
		j++;
		if(i<0)
			break;
		w+=r[i];
	}//cout<<x<<' '<<f[x]<<' '<<g[x]<<' '<<b[x]<<' '<<p<<q<<endl;
}
int main()
{
	int i,x,y;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)
		scanf("%d",t+i);
	for(i=1;i<=n;i=i+1)
		scanf("%d",h+i);
	for(i=1;i<n;i=i+1){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
		ss+=t[x]+t[y];
	}
	for(i=1;i<=n;i=i+1)
		if(!vis[i])
			dfs(i),ss-=b[i];//,cout<<i<<b[i]<<endl;
	cout<<ss<<endl;
	return 0;
}