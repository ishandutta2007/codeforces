//CF1672F
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
int n,a[N],b[N],c[N],p[N];
vector<int> v[N];
bool cmp(int i,int j){
	return c[a[i]]>c[a[j]]||(c[a[i]]==c[a[j]]&&a[i]<a[j]);
}
int main()
{
	int T,i,j;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			c[i]=0,v[i].clear();
		for(i=1;i<=n;i++){
			scanf("%d",a+i);
			b[i]=++c[a[i]];
			v[b[i]].push_back(i);
		}
		for(i=1;i<=n;i++){
			sort(v[i].begin(),v[i].end(),cmp);
			for(j=0;j<v[i].size();j++)
				p[v[i][j]]=a[v[i][(j+1)%v[i].size()]];
		}
		for(i=1;i<=n;i++)
			printf("%d ",p[i]);
		printf("\n");
		for(i=0;i<=n+1;i++)
			v[i].clear(),a[i]=0,b[i]=0,c[i]=0,p[i]=0;
	}
	return 0;
}