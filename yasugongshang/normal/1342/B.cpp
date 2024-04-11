
#include <bits/stdc++.h>
using namespace std;
char s[200100];
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		scanf("%s",s+1);
		int n=strlen(s+1);
		bool a=0,b=0;
		for (int i=1; i<=n; i++) {
			if(s[i]=='0') a=1;
			if(s[i]=='1') b=1;
		}
		if(!a||!b) {
			for (int i=1; i<=n; i++)
			                printf("%c",s[1]);
		} else {
			for (int i=1; i<=n; i++)
			                printf("10");
		}
		puts("");
	}
	return 0;
}