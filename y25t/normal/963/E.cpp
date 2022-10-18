#include<bits/stdc++.h>
#define P 1000000007
#define N 7846
#define M 105

inline int fmo(int x){
	return x+((x>>31)&P);
}
inline int fp(int x,int k=P-2){
	int res=1;
	for(;k;k>>=1,x=1ll*x*x%P)
		if(k&1)
			res=1ll*res*x%P;
	return res;
}

int R;

int p[4];
const int d[4][2]={{-1,0},{0,-1},{1,0},{0,1}};

int n,id[M][M];

int a[N][N],b[N];

int main(){
	scanf("%d",&R);
	int s=0;
	for(int i=0;i<4;i++)
		scanf("%d",&p[i]),s+=p[i];
	for(int i=0;i<4;i++)
		p[i]=1ll*p[i]*fp(s)%P;
	for(int i=-R;i<=R;i++) for(int j=-R;j<=R;j++) if(i*i+j*j<=R*R)
		id[i+R+1][j+R+1]=++n;
	for(int i=-R;i<=R;i++) for(int j=-R;j<=R;j++) if(i*i+j*j<=R*R){
		int x=id[i+R+1][j+R+1];
		a[x][x]=1,a[x][n+1]=1;
		for(int o=0;o<4;o++){
			int y=id[i+d[o][0]+R+1][j+d[o][1]+R+1];
			if(y)
				a[x][y]=fmo(-p[o]);
		}
	}
	for(int i=1;i<=n;i++){
		int inv=fp(a[i][i]);
		for(int j=i+1;j<=n&&j<=i+R+R;j++) if(a[j][i]){
			int tmp=1ll*a[j][i]*inv%P;
			for(int k=i;k<=n&&k<=i+R+R;k++)
				a[j][k]=fmo(a[j][k]-1ll*tmp*a[i][k]%P);
			a[j][n+1]=fmo(a[j][n+1]-1ll*tmp*a[i][n+1]%P);
		}
	}
	for(int i=n;i;i--){
		b[i]=a[i][n+1];
		for(int j=i+1;j<=n;j++)
			b[i]=fmo(b[i]-1ll*b[j]*a[i][j]%P);
		b[i]=1ll*b[i]*fp(a[i][i])%P;
	}
	printf("%d\n",b[id[R+1][R+1]]);
}