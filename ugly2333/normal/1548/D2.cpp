//CF1548D2
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
const int N = 6666;
int gcd(int x,int y){
	if(!y)
		return x;
	return gcd(y,x%y);
}
LL c3(LL x){
	return x*(x-1)*(x-2)/6;
}
LL c2(LL x){
	return x*(x-1)/2;
}
int n,m,x[N],y[N],f[N],g[N],a[N][N],b[11],c[11][11];
int main()
{
	int i,j,k,l,o;
	LL s;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",x+i,y+i);
		if(x[i]&1)
			f[i]|=2;
		if(y[i]&1)
			f[i]|=1;
		if(x[i]&2)
			g[i]|=2;
		if(y[i]&2)
			g[i]|=1;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<i;j++)
			a[i][j]=gcd(abs(x[i]-x[j]),abs(y[i]-y[j]))%4,a[j][i]=a[i][j];
	s=0;
	for(l=0;l<4;l++){
		memset(b,0,sizeof(b));
		m=0;
		for(i=1;i<=n;i++)
			if(f[i]==l)
				b[g[i]]++,m++;
		for(i=0;i<4;i++)
			s+=c3(b[i]);
		for(i=0;i<4;i++)
			s+=c2(b[i])*(m-b[i]);
		for(i=1;i<=n;i++){
			if(f[i]==l)
				continue;
			memset(c,0,sizeof(c));
			for(j=1;j<=n;j++)
				if(f[j]==l)
					c[g[j]][a[i][j]]++;
			if(f[i]==(l^1)){
				for(k=0;k<4;k++){
					for(o=k;o<4;o++){
						if(k==o)
							s+=c[k][1]*c[k][3];
						else
							if((k^o)&2)
								s+=c[k][1]*c[o][3]+c[k][3]*c[o][1];
							else
								s+=c[k][1]*c[o][1]+c[k][3]*c[o][3];
					}
				}
			}
			if(f[i]==(l^2)){
				for(k=0;k<4;k++){
					for(o=k;o<4;o++){
						if(k==o)
							s+=c[k][1]*c[k][3];
						else
							if((k^o)&1)
								s+=c[k][1]*c[o][3]+c[k][3]*c[o][1];
							else
								s+=c[k][1]*c[o][1]+c[k][3]*c[o][3];
					}
				}
			}
			if(f[i]==(l^3)){
				for(k=0;k<4;k++){
					for(o=k;o<4;o++){
						if(k==o)
							s+=c[k][1]*c[k][3];
						else
							if((k^o)==3)
								s+=c[k][1]*c[o][1]+c[k][3]*c[o][3];
							else
								s+=c[k][1]*c[o][3]+c[k][3]*c[o][1];
					}
				}
			}
		}
	}
	printf("%lld\n",s);
	return 0;
}