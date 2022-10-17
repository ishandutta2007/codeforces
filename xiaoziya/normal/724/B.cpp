#include<bits/stdc++.h>
using namespace std;
const int maxn=205;
int n,m,T,ans,flg;
int a[maxn][maxn],b[maxn][maxn];
string s;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int u=1;u<=m;u++)
		for(int v=u+1;v<=m;v++){
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++)
					b[i][j]=a[i][j==u? v:(j==v? u:j)];
			int flg=0;
			for(int i=1;i<=n;i++){
				int tot=0;
				for(int j=1;j<=m;j++)
					tot+=b[i][j]!=j;
				if(tot!=0&&tot!=2){
					flg=1;
					break;
				}
			}
			if(flg==0){
				puts("YES");
				return 0;
			}
		}
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++)
					b[i][j]=a[i][j];
			int flg=0;
			for(int i=1;i<=n;i++){
				int tot=0;
				for(int j=1;j<=m;j++)
					tot+=b[i][j]!=j;
				if(tot!=0&&tot!=2){
					flg=1;
					break;
				}
			}
			if(flg==0){
				puts("YES");
				return 0;
			}
	puts("NO");
	return 0;
}