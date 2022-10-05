#include<bits/stdc++.h>
using namespace std;
int n;
char s[2100000];
int main(){
	int _;
	cin>>_;
	while(_--){
		scanf("%s",s+1);
		n=strlen(s+1);
		int num=0;
		for(int i=1;i<=n;i++)if(s[i]=='1')num++;
		int now=0,ans=1000000;
		for(int i=1;i<=n;i++){
			now+='1'-s[i];
			if(i>=num+1)now-='1'-s[i-num];
			if(i>=num)ans=min(ans,now);
		}
		cout<<ans<<endl; 
	}
	return 0;
}