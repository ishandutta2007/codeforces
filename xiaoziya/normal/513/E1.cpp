#include<stdio.h>
#include<string.h>
#define inf 0x3f3f3f3f
const int maxn=30005,maxk=205;
int n,k;
int a[maxn],f[maxn][maxk][4];
inline int max(int a,int b){
	return a>b? a:b;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	memset(f,-0x3f,sizeof(f));
	for(int i=0;i<=n;i++)
		for(int j=0;j<=3;j++)
			f[i][0][j]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k;j++){
			f[i][j][0]=max(f[i-1][j][0],f[i-1][j-1][3])-(1<j&&j<k? (2*a[i]):a[i]);
			f[i][j][1]=max(max(f[i-1][j][1],f[i][j][0]),1<j&&j<k? f[i-1][j-1][1]:-inf);
			f[i][j][2]=max(f[i-1][j][2],f[i-1][j-1][1])+(1<j&&j<k? (2*a[i]):a[i]);
			f[i][j][3]=max(max(f[i-1][j][3],f[i][j][2]),1<j&&j<k? f[i-1][j-1][3]:-inf);
		}
	printf("%d\n",max(f[n][k][1],f[n][k][3]));
	return 0;
}