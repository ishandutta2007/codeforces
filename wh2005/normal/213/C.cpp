#include<bits/stdc++.h>
using namespace std;
const int N = 309;
int n,a[N][N],f[N][N][N];
int main(){
	memset(f,-0x3f,sizeof(f));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<i+j;k++){
                int l=i+j-k;
                if(i==1&&j==1){f[i][j][k]=a[i][j];continue;}
                if(i==k&&j==l) 
                    f[i][j][k]=max(max(f[i-1][j][k-1],f[i-1][j][k]),max(f[i][j-1][k-1],f[i][j-1][k]))+a[i][j];
                else 
                    f[i][j][k]=max(max(f[i-1][j][k-1],f[i-1][j][k]),max(f[i][j-1][k-1],f[i][j-1][k]))+a[i][j]+a[k][l];
			}
		}
	}
	printf("%d\n",f[n][n][n]);
	return 0;
}