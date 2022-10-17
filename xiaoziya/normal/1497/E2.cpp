#include<stdio.h>
#include<string.h>
#include<vector>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=200005,maxk=25,maxv=10000005;
int T,n,k,cnt,ans,cc;
int a[maxn],f[maxn][maxk],g[maxn][maxk],tot[maxv];
int main(){
	scanf("%d",&T);
	memset(f,0x3f,sizeof(f));
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			int tmp=1;
			for(int j=2;j*j<=a[i];j++)
				if(a[i]%j==0){
					int r=0;
					while(a[i]%j==0)
						a[i]/=j,r^=1;
					if(r)
						tmp*=j;
				}
			a[i]*=tmp;
		}
		for(int i=0;i<=k;i++){
			cc=0;
			for(int j=1,p=1;j<=n;j++){
				tot[a[j]]++;
				if(tot[a[j]]>1)
					cc++;
				while(cc>i){
					if(tot[a[p]]>1)
						cc--;
					tot[a[p]]--,p++;
				}
				g[j][i]=p;
			}
			for(int i=1;i<=n;i++)
				tot[a[i]]=0;
		}
		f[0][0]=0;
		for(int i=1;i<=n;i++)
			for(int j=0;j<=k;j++)
				for(int p=0;p<=j;p++)
					f[i][j]=min(f[i][j],f[g[i][p]-1][j-p]+1);
		ans=inf;
		for(int i=0;i<=k;i++)
			ans=min(ans,f[n][i]);
		for(int i=0;i<=n;i++)
			for(int j=0;j<=k;j++)
				f[i][j]=inf;
		printf("%d\n",ans);
	}
	return 0;
}