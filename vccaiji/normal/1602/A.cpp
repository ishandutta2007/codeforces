#include<bits/stdc++.h>
using namespace std;
char s[1100000];
int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		scanf("%s",s+1);
		int n=strlen(s+1);
		int o=s[1]-'a',j=1;
		for(int i=1;i<=n;i++){
			if(s[i]-'a'<o){
				j=i;
				o=s[i]-'a';
			}
		}
		printf("%c ",s[j]);
		for(int i=1;i<j;i++) printf("%c",s[i]);
		for(int i=j+1;i<=n;i++) printf("%c",s[i]);
		printf("\n"); 
	}
	return 0;
}