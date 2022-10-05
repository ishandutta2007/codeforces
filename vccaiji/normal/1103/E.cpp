#include<bits/stdc++.h>
using namespace std;
int a[100000][5];
long long f[100000][5]={};
long long g[100000][5];
int p10[5]={1,10,100,1000,10000};
int main(){
	for(int j=0;j<100000;j++){
		a[j][0]=j%10;
		a[j][1]=(j/10)%10;
		a[j][2]=(j/100)%10;
		a[j][3]=(j/1000)%10;
		a[j][4]=j/10000;
	} 
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		f[a][0]++;
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<100000;j++){
			if(a[j][i]==0){
			    long long ff[10][5]={};
				for(int ii=0;ii<10;ii++){
					for(int jj=0;jj<5;jj++){
						for(int k=0;k<10;k++){
							if((ii*k)&1) ff[k][(jj+ii*k)%5]-=f[j+ii*p10[i]][jj];
							else ff[k][(jj+ii*k)%5]+=f[j+ii*p10[i]][jj];
						} 
					}
				}
				for(int ii=0;ii<10;ii++){
					for(int jj=0;jj<5;jj++) f[j+ii*p10[i]][jj]=ff[ii][jj];
				}
			}
		}
	}
	for(int j=0;j<100000;j++){
		for(int i=0;i<5;i++){
			if(i) g[j][i]=0;
			else g[j][i]=1;
		}
	}
	for(int m=n;m;m>>=1){
		if(m&1){
			for(int i=0;i<100000;i++){
				long long t[5]={};
				for(int j=0;j<5;j++){
					for(int k=0;k<5;k++) t[(j+k)%5]+=f[i][j]*g[i][k];
				}
				for(int j=0;j<5;j++) g[i][j]=t[j];
			}
		}
		for(int i=0;i<100000;i++){
			long long t[5]={};
			for(int j=0;j<5;j++){
				for(int k=0;k<5;k++) t[(j+k)%5]+=f[i][j]*f[i][k];
			}
			for(int j=0;j<5;j++) f[i][j]=t[j];
		}
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<100000;j++){
			if(a[j][i]==0){
			    long long gg[10][5]={};
				for(int ii=0;ii<10;ii++){
					for(int jj=0;jj<5;jj++){
						for(int k=0;k<10;k++){
							if((ii*k)&1) gg[k][(jj+(10-ii)*k)%5]-=g[j+ii*p10[i]][jj];
							else gg[k][(jj+(10-ii)*k)%5]+=g[j+ii*p10[i]][jj];
						} 
					}
				}
				for(int ii=0;ii<10;ii++){
					for(int jj=0;jj<5;jj++) g[j+ii*p10[i]][jj]=gg[ii][jj];
				}
			}
		}
	}
	long long u=5*5*5*5*5;
	long long p=1;
	long long y=0;
	for(int i=1;i<=63;i++){
		y=2*y+1;
		p*=u;
		u*=u;
	}
	for(int i=0;i<n;i++){
		long long t=g[i][0]-g[i][1];
		printf("%lld\n",((p*t)&y)>>5);
	}
	return 0;
}