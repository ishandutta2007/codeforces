//CF1710C
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
const int MO = 998244353;
void ad(int&x,int y){
	x+=y;
	if(x>=MO)
		x-=MO;
}
int mul(int x,int y){
	return (LL)x*y%MO;
}
int n,a[N],f[N][8][8],g[4]={6,3,3,1};
char c[N];
int main()
{
	int i,j,k,l,x,y,z,s,t;
	scanf("%s",c+1);
	n=strlen(c+1);
	for(i=1;i<=n;i++)
		a[i]=c[i]-'0';
	f[1][7][0]=1;
	for(i=1;i<=n;i++)
		for(j=0;j<8;j++)
			for(k=0;k<8;k++){
				if(!f[i][j][k])
					continue;
				for(l=0;l<8;l++){
					x=(bool)(l&4),y=(bool)(l&2),z=(bool)(l&1);
					s=j;
					if(j&4){
						if(x>y)
							continue;
						if(x<y)
							s^=4;
					}
					if(j&2){
						if(y>z)
							continue;
						if(y<z)
							s^=2;
					}
					if(j&1){
						if(z>a[i])
							continue;
						if(z<a[i])
							s^=1;
					}
					t=k;
					if(l==1||l==6)
						t|=1;
					if(l==2||l==5)
						t|=2;
					if(l==4||l==3)
						t|=4;
					ad(f[i+1][s][t],f[i][j][k]);//cout<<i<<j<<k<<s<<t<<endl;
				}
			}
	x=0;
	for(j=0;j<8;j++)
		ad(x,mul(f[n+1][j][7],g[j>>1]));
	printf("%d\n",x);
	return 0;
}