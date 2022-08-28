//CF1609D
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
const int N = 1111;
int n,m,f[N],g[N];
int fnd(int x){
	if(f[x]==x)
		return x;
	return f[x]=fnd(f[x]);
}
vector<int> v;
int main()
{
	int i,j,s,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		f[i]=i,g[i]=1;
	s=0;
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		x=fnd(x),y=fnd(y);
		if(x!=y){
			g[x]+=g[y];
			f[y]=x;
		}
		else
			s++;
		v.clear();
		for(j=1;j<=n;j++)
			if(fnd(j)==j)
				v.push_back(g[j]);
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		x=0;
		for(j=0;j<=s&&j<v.size();j++)
			x+=v[j];
		printf("%d\n",x-1);
	}
	return 0;
}