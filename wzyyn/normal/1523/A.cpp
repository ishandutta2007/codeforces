#include<bits/stdc++.h>
using namespace std;

int n,m;
char s[1005];
int dl[1005],dr[1005];
void solve(){
	scanf("%d%d%s",&n,&m,s+1);
	dl[1]=(s[1]=='1'?0:1<<30);
	dr[n]=(s[n]=='1'?0:1<<30);
	for (int i=2;i<=n;i++)
		dl[i]=(s[i]=='1'?0:dl[i-1]+1);
	for (int i=n-1;i>=1;i--)
		dr[i]=(s[i]=='1'?0:dr[i+1]+1);
	for (int i=1;i<=n;i++)
		if (dl[i]!=dr[i]&&min(dl[i],dr[i])<=m)
			s[i]='1';
	printf("%s\n",s+1);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}