#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
using namespace std;

int q[55],n,tg[55][55];
char s[55];
void solve(){
	*q=0;
	scanf("%d%s",&n,s+1);
	memset(tg,0,sizeof(tg));
	for (int i=1;i<=n;i++)
		if (s[i]=='2') q[++*q]=i;
	if ((*q)==1||(*q)==2)
		return puts("NO"),void(0);
	for (int i=1;i<=*q;i++){
		tg[q[i]][q[i%(*q)+1]]=1;
		tg[q[i%(*q)+1]][q[i]]=-1;
	}
	puts("YES");
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)
			if (i==j) putchar('X');
			else if (!tg[i][j]) putchar('=');
			else putchar(tg[i][j]==1?'+':'-');
		puts("");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}