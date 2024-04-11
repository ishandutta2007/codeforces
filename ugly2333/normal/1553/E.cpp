//CF1553E
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
const int N = 333333;
int n,m,a[N],b[N],c[N],d[N];
vector<int> v;
int solve(){
	int i,j,x,s=0;
	for(i=1;i<=n;i++)
		d[i]=0;
	for(i=1;i<=n;i++){
		if(!d[i]){
			d[i]=1;
			for(j=c[i],x=1;j!=i;j=c[j])
				d[j]=1,x++;
			s+=x-1;
		}
	}
	return s;
}
int main()
{
	int T,i,j,x,o;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		for(i=1;i<=n;i++)
			b[(i-a[i]+n)%n]++;
		for(i=0;i<n;i++){
			if(b[i]>=n-m*2){
				x=0;
				for(j=i+1;j<=n;j++)
					c[++x]=a[j];
				for(j=1;j<=i;j++)
					c[++x]=a[j];
				if(solve()<=m)
					v.push_back(i);
			}
		}
		printf("%d",v.size());
		for(i=0;i<v.size();i++)
			printf(" %d",v[i]);
		printf("\n");
		v.clear();
		for(i=0;i<n;i++)
			b[i]=0;
	}
	return 0;
}