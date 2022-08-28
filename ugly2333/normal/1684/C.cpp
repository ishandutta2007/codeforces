//CF1684C
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
const int inf = 1e9+N;
int n,m,a[N],b[N],e[N];
vector<int> v,c[N];
int main()
{
	int T,i,j,f,l,r;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		f=1;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++)
				scanf("%d",a+j),b[j]=a[j];
			c[i].clear();
			for(j=0;j<=m;j++)
				c[i].push_back(a[j]);
			sort(b+1,b+m+1);
			v.clear();
			for(j=1;j<=m;j++)
				if(a[j]!=b[j])
					v.push_back(j);
			if(v.size()>2)
				f=0;
			if(v.size()==2){
				if(f==0||(f==2&&(l!=v[0]||r!=v[1])))
					f=0;
				else
					f=2,l=v[0],r=v[1];
			}
			if(v.size()==0)
				e[i]=1;
			else
				e[i]=0;
		}
		if(f==2){
			for(i=1;i<=n;i++)
				if(e[i]&&c[i][l]!=c[i][r])
					f=0;
		}
		if(f==0)
			printf("-1\n");
		if(f==1)
			printf("1 1\n");
		if(f==2)
			printf("%d %d\n",l,r);
	}
	return 0;
}