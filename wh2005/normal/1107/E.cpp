#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 1e2+9;
int n,a[N],b[N];
char s[N];
ll f[N][N],g[N][N][N][2];
//f[l][r] l,r 
//g[l][r][k][0/1]  l,r  k  0/1  

int main(){
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++) b[i]=s[i]-'0';
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(f,-0x3f,sizeof(f));
	memset(g,-0x3f,sizeof(g));
	for(int i=1;i<=n;i++){
		f[i][i]=a[1],f[i][i-1]=0;
		g[i][i][1][b[i]]=0;
	}	
	for(int len=2;len<=n;len++){
		for(int i=n-len+1;i>=1;i--){
			int j=i+len-1;
			f[i][j]=max(f[i][j],f[i+1][j]+a[1]);
			f[i][j]=max(f[i][j],f[i][j-1]+a[1]);
			for(int k=1;k<=len;k++){
				for(int t=0;t<2;t++){
					if(b[i]==t) g[i][j][k+1][t]=max(g[i][j][k+1][t],g[i+1][j][k][t]);
					if(b[j]==t) g[i][j][k+1][t]=max(g[i][j][k+1][t],g[i][j-1][k][t]);
				}
			}
			for(int k=1;k<=len;k++){
				for(int t=0;t<2;t++){
					for(int p=i;p<j;p++){
						g[i][j][k][t]=max(g[i][j][k][t],f[i][p]+g[p+1][j][k][t]);
						g[i][j][k][t]=max(g[i][j][k][t],g[i][p][k][t]+f[p+1][j]);
					}
				}
			}
			for(int k=1;k<=len;k++) 
				for(int t=0;t<2;t++) f[i][j]=max(f[i][j],g[i][j][k][t]+a[k]);	
		}
	}
	printf("%lld\n",f[1][n]);
	return 0;
}