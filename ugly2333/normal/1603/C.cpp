//CF1603C
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
const int N = 1<<18;
const int M = 444;
const int MO = 998244353;
void ad(int&x,int y){
	x+=y;
	if(x>=MO)
		x-=MO;
}
int mul(int x,int y){
	return (LL)x*y%MO;
}
int di(int x,int y){
	return (x+y-1)/y;
}
int n,a[N];
int m=333,f[M],g[M],sf[M],sg[M],f2[M],g2[M],sf2[M],sg2[M];
int main()
{
	int T,i,j,x,y,z,ans;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		a[0]=N;
		ans=0;
		for(i=1;i<=m;i++){
			sf[i]=di(a[1],i)-1;
			sg[i]=di(a[1],di(a[1],i))-1;
		}
		for(i=2;i<=n;i++){
			if(a[i]<=m)
				ad(ans,sf[a[i]]);
			else
				ad(ans,sg[di(a[i-1],a[i])]);
			for(j=1;j<=m;j++){
				x=di(a[i],j);
				y=a[i]/x;
				sf2[j]=sf[y]+mul(x-1,i);
				x=di(a[i],di(a[i],j));
				//cout<<j<<' '<<x<<endl;
				y=a[i]/x;
				if(y<=m){
					sg2[j]=sf[y]+mul(x-1,i);
				}
				else{
					z=di(a[i-1],y);
					sg2[j]=sg[z]+mul(x-1,i);
				}
			}
			for(j=1;j<=m;j++){
				sf[j]=sf2[j]%MO;
				sg[j]=sg2[j]%MO;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}