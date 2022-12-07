#include<bits/stdc++.h>

using namespace std;

int n,m;
char s[55][55];
bool check(char c1,char c2){
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (s[i][j]!='.'){
				if ((i+j)%2==0&&s[i][j]!=c1) return 0;
				if ((i+j)%2==1&&s[i][j]!=c2) return 0;
			}
	puts("YES");
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if ((i+j)%2==0) putchar(c1);
			if ((i+j)%2==1) putchar(c2);
		}
		puts("");
	}
	return 1;
}
void solve(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%s",s[i]+1);
	if (check('R','W'));
	else if (check('W','R'));
	else puts("NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}