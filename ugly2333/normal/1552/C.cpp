//CF1552C
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
const int N = 222;
int n,k,p[N];
vector<int> v;
int main()
{
	int T,i,j,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(i=1;i<=n*2;i++)
			p[i]=0;
		for(i=1;i<=k;i++){
			scanf("%d%d",&x,&y);
			p[x]=y,p[y]=x;
		}
		v.clear();
		v.push_back(0);
		for(i=1;i<=n*2;i++)
			if(!p[i])
				v.push_back(i);
		for(i=1;i<=n-k;i++)
			p[v[i]]=v[i+n-k],p[v[i+n-k]]=v[i];
		x=0;
		for(i=1;i<=n*2;i++)
			for(j=i+1;j<=n*2;j++)
				if(i<j&&j<p[i]&&p[i]<p[j])
					x++;
		printf("%d\n",x);
	}
	return 0;
}