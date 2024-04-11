#include<bits/stdc++.h>
using namespace std;
int t,cnt[30];
int main(){
	scanf("%d\n",&t);
	while(t--){
		memset(cnt,0,sizeof cnt);
		char s[1005];
		cin.getline(s,1005);
		int len=strlen(s),ans=0;
		for(int i=0;i<len;i++)cnt[s[i]-'a']++;
		for(int i=0;i<26;i++){
			if(cnt[i]>=2)ans+=2;
			if(cnt[i]==1)ans++;
		}
		printf("%d\n",ans/2);
	} 
	return 0;
}