#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 50005

int T;

int n,m;
char s[N];

bool a[400005];

int cnt[2][N];

int main(){
	scanf("%d",&T);
	while(T--){
		memset(cnt,0,sizeof(cnt));
		memset(a,0,sizeof(a));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%s",s+1);
			for(int j=1;j<=m;j++)
				if(s[j]=='*'){
					cnt[0][i]++;
					cnt[1][j]++;
					a[(i-1)*m+j]=1;
				}
		}
		int ans=1e9;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				if(a[(i-1)*m+j])
					ans=min(ans,n+m-cnt[0][i]-cnt[1][j]);
				else
					ans=min(ans,n+m-cnt[0][i]-cnt[1][j]-1);
			}
		printf("%d\n",ans);
	}
}