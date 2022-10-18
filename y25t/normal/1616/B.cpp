#include<bits/stdc++.h>
#define N 100005

int T;

int n;
char s[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s+1);
		if(n>1&&s[1]==s[2]){
			printf("%c%c\n",s[1],s[1]);
			continue;
		}
		int o=1;
		while(o<n&&s[o+1]<=s[o])
			o++;
		for(int i=1;i<=o;i++)
			printf("%c",s[i]);
		for(int i=o;i;i--)
			printf("%c",s[i]);
		puts("");
	}
}