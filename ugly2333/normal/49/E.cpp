//CF 
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
typedef double DB;
const int N = 55;
const int M = 26;
char a[N],b[N],c[N];
bool dpa[M][N][N],dpb[M][N][N];
int qx[N],ql[N],qr[N];
int f[N][N];
int main()
{
	int na,nb,n,i,j,k,l,r;
	scanf("%s%s",a+1,b+1);
	a[0]='_',b[0]='_';
	na=strlen(a)-1,nb=strlen(b)-1;
	for(i=1;i<=na;i=i+1)
		a[i]-='a';
	for(i=1;i<=nb;i=i+1)
		b[i]-='a';
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%s",c+1);
		qx[i]=c[1]-'a';
		ql[i]=c[4]-'a';
		qr[i]=c[5]-'a';
	}
	for(i=1;i<=na;i=i+1){
		for(l=1,r=i;r<=na;l=l+1,r=r+1){
			if(i==1){
				dpa[a[l]][l][r]=1;
				continue;
			}
			for(j=1;j<=n;j=j+1)
				for(k=l;k<r;k=k+1)
					dpa[qx[j]][l][r]|=dpa[ql[j]][l][k]&dpa[qr[j]][k+1][r];
		}
	}
	for(i=1;i<=nb;i=i+1){
		for(l=1,r=i;r<=nb;l=l+1,r=r+1){
			if(i==1){
				dpb[b[l]][l][r]=1;
				continue;
			}
			for(j=1;j<=n;j=j+1)
				for(k=l;k<r;k=k+1)
					dpb[qx[j]][l][r]|=dpb[ql[j]][l][k]&dpb[qr[j]][k+1][r];
		}
	}
	f[0][0]=-1000;
	for(i=1;i<=na;i=i+1){
		for(j=1;j<=nb;j=j+1){
			for(k=0;k<M;k=k+1)
				for(l=1;l<=i;l=l+1)
					if(dpa[k][l][i])
						for(r=1;r<=j;r=r+1)
							if(dpb[k][r][j])
								f[i][j]=min(f[i][j],f[l-1][r-1]+1);
			//cout<<f[i][j]<<' ';
		}
		//cout<<endl;
	}
	i=na,j=nb;
	if(f[i][j]<0)
		f[i][j]+=1000;
	else
		f[i][j]=-1;
	cout<<f[i][j];
	return 0;
}