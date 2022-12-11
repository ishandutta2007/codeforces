#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d\n",&t);
	while(t--){
		char s[1000000];
		int ans[1000000];
		cin.getline(s,(int)1e9);
		int n=strlen(s),pd=0;
		for(int i=0;i<n;i++)ans[i]=-1;
		for(int i=n-2;i>=0;i--){
			int now=s[i]+s[i+1]-2*'0';
			if(now>9&&!pd){
				ans[i]=now/10;
				ans[i+1]=now%10;
				pd=1;
			}
			if(ans[i]==-1)ans[i]=s[i]-'0';
		}
		if(ans[n-1]==-1)ans[n-1]=s[n-1]-'0';
		if(!pd){
			printf("%d",s[0]+s[1]-'0'*2);
			for(int i=2;i<n;i++)cout<<s[i];
			puts("");
			continue;
		}
		else{
			for(int i=0;i<n;i++)cout<<ans[i];
			puts(""); 
		}
	}
	return 0;
}