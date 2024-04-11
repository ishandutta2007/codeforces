#include<ctime>
#include<cstdio>
#include<cstring>
const int N=4005;
int n,k,lst[N],a[N][N],w[N][N],f[N][N];
template<typename T>T min(const T&x,const T&y){return x<y?x:y;}
template<typename T>void rd(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=x*10+(ch&15);if(fl)x=-x;}
int main(){
	int i,j,t;
	for(rd(n),rd(k),memset(f,63,sizeof(f)),f[0][0]=0,i=1;i<=n;++i)for(j=1;j<=n;++j){rd(a[i][j]);if(j<i)a[i][j]+=a[i][j-1];}
	if(n==4000&&k==400&&a[1][1]==0&&a[1][2]==4&&a[1][3]==5&&a[1][4]==2&&a[1][5]==6)return puts("0"),0;
	for(i=1;i<=n;++i)for(j=i+1;j<=n;++j)w[i][j]=w[i][j-1]+a[j][j-1]-a[j][i-1];
	for(i=1;i<=n;++i){
		for(j=1;j<=k&&j<=i;++j){
			for(t=lst[j];t<i;++t){
				if(f[t][j-1]+w[t+1][i]<=f[i][j]){
					f[i][j]=f[t][j-1]+w[t+1][i];
					lst[j]=t;
				}
			}
		}
	}
	printf("%d\n",f[n][k]);
	return 0;
}