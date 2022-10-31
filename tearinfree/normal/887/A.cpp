#include <bits/stdc++.h>
using namespace std;

char str[101];
int n;

int main() {
	scanf("%s",str);
	n=strlen(str);
	int cnt=0;
	int i=0;
	while(i<n && str[i]=='0') i++;
	for(;i<n;i++) if(str[i]=='0') cnt++;
	puts(cnt>=6 ? "yes" : "no");
	return 0;
}