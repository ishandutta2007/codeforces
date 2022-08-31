//CF1396C
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
const int N = 1e6+16;
int n,r1,r2,r3,d,a[N];
LL d2,d3,b[N],c[N],f[N][4];
int main()
{
	int i;
	scanf("%d%d%d%d%d",&n,&r1,&r2,&r3,&d);
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		b[i]=(LL)a[i]*r1+r3;
		c[i]=min((LL)(a[i]+1)*r1,(LL)r2)+r1;
		c[i]=min(c[i],b[i]);//cout<<b[i]<<c[i]<<endl;
	}
	d2=d+d,d3=d2+d;
	f[1][1]=b[1]+d,f[1][2]=c[1]+d2,f[1][3]=c[1]+d3;
	for(i=2;i<n;i=i+1){
		f[i][1]=min(f[i-1][1]+b[i],f[i-1][3]+c[i])+d;
		f[i][2]=min(min(f[i-1][1]+c[i],f[i-1][3]+c[i]),f[i-1][2]+c[i])+d2;
		f[i][3]=min(f[i-1][1]+c[i],f[i-1][3]+c[i])+d3;//cout<<f[i][1]<<' '<<f[i][2]<<' '<<f[i][3]<<endl;
	}
	cout<<min(min(f[n-1][1]+b[n],f[n-1][2]+b[n]),f[n-1][3]+c[n])<<endl;
	return 0;
}