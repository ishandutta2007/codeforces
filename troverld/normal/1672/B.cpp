#include<bits/stdc++.h>
using namespace std;
int T,n;
char s[200100];
void mina(){
	scanf("%s",s),n=strlen(s);
	if(s[n-1]!='B'){puts("No");return;}
	bool ok=true;
	int sum=0;
	for(int i=0;i+1<n;i++){
		if(s[i]=='A')sum++;
		else sum--;
		if(sum<0){puts("No");return;}
	}
	if(sum==0){puts("No");return;}
	puts("Yes");
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}