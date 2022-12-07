#include<bits/stdc++.h>

using namespace std;

const int N=100005;
int n;
char s[N][5];
int tg2[2][26][26];
int tg3[26][26][26],T;
void solve(){
	++T;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for (int i=1;i<=n;i++){
		int l=strlen(s[i]+1);
		if (s[i][1]==s[i][l])
			return puts("YES"),void(0);
		for (int j=1;j<=l;j++) s[i][j]-='a';
		tg2[l==2][s[i][1]][s[i][2]]=T;
		if (tg2[1][s[i][l]][s[i][l-1]]==T)
			return puts("YES"),void(0);
		if (l==2&&tg2[0][s[i][l]][s[i][l-1]]==T)
			return puts("YES"),void(0);
		if (l==3){
			tg3[s[i][1]][s[i][2]][s[i][3]]=T;
			if (tg3[s[i][3]][s[i][2]][s[i][1]]==T)
				return puts("YES"),void(0);
		}
	}
	puts("NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
if  

***** 
*/