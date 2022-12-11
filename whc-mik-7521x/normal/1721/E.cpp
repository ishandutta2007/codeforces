#include<bits/stdc++.h>
const int N=1e6+50;
int q,n,m,p[N],to[N][26];
char s[N];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	to[0][s[1]-'a']=1;
	for(int i=1;i<n;++i){
		for(int c=0;c<26;++c){
			if(c==s[i+1]-'a')to[i][c]=i+1,p[i+1]=to[p[i]][c];
			else to[i][c]=to[p[i]][c];
		}
	}
	scanf("%d",&q);
	while(q--){
		scanf("%s",s+n+1);
		m=strlen(s+n+1);
		for(int i=0;i<m;++i){
			int o=n+i;
			for(int c=0;c<26;++c){
				if(c==s[o+1]-'a')to[o][c]=o+1,p[o+1]=to[p[o]][c];
				else to[o][c]=to[p[o]][c];
			}
		}
		for(int i=1;i<=m;++i)printf("%d ",p[n+i]);
		puts("");
	}
	return 0;
}