#include<bits/stdc++.h>
using namespace std;
char s[110000];
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	bool r=0,rr=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='(') r=1;
		if(r&(s[i]==')')) rr=1;
	}
	if(rr){
		int cnt=0;
		for(int i=1;i<=n;i++)if(s[i]==')')cnt++;
		int o=0;
		for(int i=1;i<=cnt;i++)if(s[i]=='(')o++;
		for(int i=cnt+1;i<=n;i++)if(s[i]==')')o++;
		printf("1\n");
		printf("%d\n",o);
		for(int i=1;i<=cnt;i++)if(s[i]=='(')printf("%d ",i);
		for(int i=cnt+1;i<=n;i++)if(s[i]==')')printf("%d ",i);
	}
	else{
		cout<<0;
	}
	return 0;
}