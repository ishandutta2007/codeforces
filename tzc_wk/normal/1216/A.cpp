#include <bits/stdc++.h>
using namespace std;
int n,cnt=0;
char s[200005];
int main(){
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i+=2){
		if(s[i]==s[i+1]){
			if(s[i]=='a')	s[i]='b';
			else			s[i]='a';
			cnt++;
		}
	}
	printf("%d\n",cnt);
	for(int i=1;i<=n;i++)	putchar(s[i]);
	return 0;
}