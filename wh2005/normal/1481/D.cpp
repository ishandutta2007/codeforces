#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+9;
const int M = 2e5+9;
int T,n,m,g[N][N],ans[M];
char s[N];


int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%s",s);
			for(int j=1;j<=n;j++){
				if(s[j-1]=='a') g[i][j]=1;
				else if(s[j-1]=='b') g[i][j]=2;
				else g[i][j]=0;
			}
		}
		if(m%2==1){
			printf("YES\n");
			for(int i=0;i<=m;i++) printf("%d ",(i%2)+1);puts("");
			continue;
		}
		int flag=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(!flag&&g[i][j]==g[j][i]){
					flag=1;printf("YES\n");
					for(int t=1;t<=m+1;t++) printf("%d ",(t&1)?i:j);puts("");
				}
				if(flag) break;
			}
			if(flag) break;
		}
		if(flag) continue;
		for(int i=1;i<=n;i++){
			int a=0,b=0,c,d;
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				if(g[j][i]==1) a++,c=j;
				else b++,d=j;
			}
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				if(!flag&&g[i][j]==1&&a){
					flag=1;printf("YES\n");
					for(int t=m/2;t>=1;t--)
						ans[t]=((t-(m/2))&1?i:c);
					ans[m/2+1]=i;
					for(int t=m/2+2;t<=m+1;t++)
						ans[t]=((t-(m/2))&1?i:j);
					for(int t=1;t<=m+1;t++) printf("%d ",ans[t]);puts("");
				}
				if(!flag&&g[i][j]==2&&b){
					flag=1;printf("YES\n");
					for(int t=m/2;t>=1;t--)
						ans[t]=((t-(m/2))&1?i:d);
					ans[m/2+1]=i;
					for(int t=m/2+2;t<=m+1;t++)
						ans[t]=((t-(m/2))&1?i:j);
					for(int t=1;t<=m+1;t++) printf("%d ",ans[t]);puts("");
				}
				if(flag) break;
			}
			if(flag) break;
		}
		if(!flag) printf("NO\n");
	}
	return 0;
}