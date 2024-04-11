#include<bits/stdc++.h>
#define N 200005

int T;

int n;
char s[N];

int cnt[26];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i=0;i<26;i++)
			cnt[i]=0;
		for(int i=1;i<=n;i++)
			cnt[s[i]-'a']++;
		for(int i=1;i<=n;i++){
			if(cnt[s[i]-'a']==1){
				for(int j=i;j<=n;j++)
					putchar(s[j]);
				break;
			}
			cnt[s[i]-'a']--;
		}
		puts("");
	}
}