#include<bits/stdc++.h>
#define N 1000005

int T;

int n,k;

int cnt[26];

char s[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%s",&n,&k,s+1);
		for(int i=0;i<26;i++)
			cnt[i]=0;
		for(int i=1;i<=n;i++)
			cnt[s[i]-'a']++;
		for(int i=1;i<=k;i++){
			int t=n/k;
			for(int j=0;j<26;j++){
				if(!cnt[j]||!t){
					putchar('a'+j);
					break;
				}
				cnt[j]--,t--;
			}
		}
		puts("");
	}
}