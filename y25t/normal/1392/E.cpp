#include<cstdio>
#include<algorithm>
#define ll long long
#define N 30

int n,q;

ll a[N][N],mx[N][N],mn[N][N];

int ans[N];

int main(){
	scanf("%d",&n);
	for(int k=2;k<=2*n;k++)
		for(int i=std::min(k-1,n),j=k-i,flg=0;i&&i<=n&&j&&j<=n;i--,j++){
			if(!flg){
				flg=1;
				a[i][j]=0;
			}
			else
				a[i][j]=a[i+1][j-1]+mx[i][j-1]-mn[i][j-1]+1;
			mx[i][j]=(i==1?mx[i][j-1]:mx[i-1][j])+a[i][j];
			mn[i][j]=(j==1?mn[i-1][j]:mn[i][j-1])+a[i][j];
		}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%I64d ",a[i][j]);
		puts("");
	}
	fflush(stdout);
	scanf("%d",&q);
	while(q--){
		ll dis;
		scanf("%I64d",&dis);
		for(int k=2*n;k>=2;k--)
			for(int i=std::min(k-1,n),j=k-i;i&&i<=n&&j&&j<=n;i--,j++)
				if(dis>=mn[i][j]&&dis<=mx[i][j]){
					ans[k]=i;
					dis-=a[i][j];
					break;
				}
		for(int k=2;k<=2*n;k++)
			printf("%d %d\n",ans[k],k-ans[k]);
		fflush(stdout);
	}
}