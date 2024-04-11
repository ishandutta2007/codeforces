#include <bits/stdc++.h>
using namespace std;

int t, n, k, i, j, c[200][4];
char ch; int q[3];

int main(){
	for(scanf("%d",&t);t>0;t--){
		for(scanf("%d%d",&n,&k),i=0;i<3;i++){
			for(getchar(),j=0;j<n;j++){
				ch = getchar();
				if(ch == 's') q[i]=1;
				if(ch == '.') c[j][i] = 0;
				else c[j][i] = -1;
			}
		}
		for(i=0;i<=ceil(n/3.0);i++){
			for(j=0;j<3;j++){
				if(!q[j]) continue;
				if(c[3*i+1][j]==-1) q[j]=0;
			}
			int a[3] = {0,0,0};
			for(j=0;j<3;j++){
				if(!q[j]) continue;
				if(j!=2&&c[3*i+1][j+1]!=-1) a[j+1]=1;
				if(j!=0&&c[3*i+1][j-1]!=-1) a[j-1]=1;
			}
			for(j=0;j<3;j++) q[j]|=a[j];
			for(j=0;j<3;j++){
				if(!q[j]) continue;
				if(c[3*i+2][j]!=-1&&c[3*i+3][j]!=-1) q[j]=1;
				else q[j] = 0;
			}
		}
		int ans = 0;
		for(i=0;i<3;i++) ans=max(ans,q[i]);
		printf("%s\n",(ans)?"YES":"NO");
		memset(c, 0, sizeof(c));
		memset(q, 0, sizeof(q));
	}
	return 0;
}