#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d\n",&t);
	while(t--){
		char s[100005];
		int kk[100],kkk[100];
		memset(kk,0,sizeof kk);
		memset(kkk,0,sizeof kkk);
		cin.getline(s,(int)1e9);
		int n=strlen(s);
		for(int i=0;i<n;i++){
			if(kk[s[i]-'a'])kkk[s[i]-'a']++,kk[s[i]-'a']=0;
			else kk[s[i]-'a']++;
		} 
		for(int i=0;i<26;i++)if(kkk[i])putchar(i+'a');
		for(int i=0;i<26;i++)if(kkk[i])putchar(i+'a');
		for(int i=0;i<26;i++)if(kk[i])putchar(i+'a');
		puts("");
	} 
	return 0;
}