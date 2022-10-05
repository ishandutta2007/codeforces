#include<bits/stdc++.h>
using namespace std;
int mx[26];
char s[210000];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",s+1);
		int n=strlen(s+1);
		for(int i=0;i<26;i++) mx[i]=0;
		for(int i=1;i<=n;i++) mx[s[i]-'a']=i;
		int u=n+100;
		for(int i=0;i<26;i++) if(mx[i]) u=min(u,mx[i]);
		for(int i=u;i<=n;i++) printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}