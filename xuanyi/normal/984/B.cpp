#include <cstdio>
#include <cctype>

const int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int n,m,cnt[105][105];
char mp[105][105];

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%s",mp[i]+1);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) if (mp[i][j]=='*')
			for (int k=0;k<8;k++)
				cnt[i+dir[k][0]][j+dir[k][1]]++;
	for (int i=1,x;i<=n;i++)
		for (int j=1;j<=m;j++){
			if (mp[i][j]=='.') x=0;
			else if (isdigit(mp[i][j])) x=(mp[i][j]&15);
			else continue;
			if (x!=cnt[i][j]) return puts("NO")&0;
		}
	return puts("YES")&0;
}