#include<bits/stdc++.h>
using namespace std;
char s[1100000];
int main(){
	int _;
	cin>>_;
	while(_--){
		scanf("%s",s+1);
		int n=strlen(s+1);
		int o=0,ok=1;
		for(int i=1;i<=n;i++){
			if(s[i]=='A')o++;
			if(s[i]=='B')o--;
			if(o<0)ok=0;
		}
		if(s[n]=='A')ok=0;
		cout<<(ok? "YES\n" : "NO\n");
	}
	return 0;
}