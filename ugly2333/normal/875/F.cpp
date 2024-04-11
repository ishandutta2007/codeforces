//CF 875F
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
const int N = 222222;
int f[N],g[N];
pair<int,pair<int,int> > a[N];
int fnd(int x){
	if(f[x]==x)
		return x;
	f[x]=fnd(f[x]);
	g[x]=g[f[x]];
	return f[x];
}
int main()
{
	int n,m,i,x,y,z,j,p;
	LL ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i=i+1){
		scanf("%d%d%d",&x,&y,&z);
		a[i]=make_pair(z,make_pair(x,y));
	}
	for(i=0;i<N-222;i=i+1)
		f[i]=i,g[i]=0;
	sort(a+1,a+m+1);
	reverse(a+1,a+m+1);
	j=0;
	p=0;
	ans=0;
	for(i=1;i<=m&&j+p<=n;i=i+1){
		z=a[i].first;
		x=a[i].second.first;
		y=a[i].second.second;
		//cout<<z<<endl;
		if(fnd(x)!=fnd(y)){
			if(g[f[x]]&&g[f[y]])
				continue;
			g[f[y]]=g[f[x]]|g[f[y]];
			f[f[x]]=f[y];
			j++;
			ans+=(LL)z;
		}
		else{
			if(!g[fnd(x)]){
				p++;
				g[f[x]]=1;
				ans+=(LL)z;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}