#include<bits/stdc++.h>
#define N 100005

int T;

char s[N],t[N];
int n,m;

int nxt[N][26][2],lst[26][2];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s%s",s+1,t+1);
		n=strlen(s+1),m=strlen(t+1);
		for(int i=0;i<26;i++)
			lst[i][0]=lst[i][1]=nxt[n+1][i][0]=nxt[n+1][i][1]=n+1;
		for(int i=n;~i;i--){
			for(int j=0;j<26;j++){
				nxt[i][j][0]=lst[j][0];
				nxt[i][j][1]=lst[j][1];
			}
			if(i)
				lst[s[i]-'a'][i&1]=i;
		}
		int p=0,q=0;;
		for(int i=1;i<=m;i++){
			p=nxt[p][t[i]-'a'][i&1];
			q=nxt[q][t[i]-'a'][(i&1)^1];
		}
		if(p<=n&&!((p^n)&1))
			puts("YES");
		else if(q<=n&&!((q^n)&1))
			puts("YES");
		else
			puts("NO");
	}
}