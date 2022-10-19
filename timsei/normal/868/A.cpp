#include<bits/stdc++.h>
using namespace std;

char s[5];
char now[5];
int flag1 , flag2 , ans;

main(void) {
	ans = 0;
	scanf("%s",s);
	int n; cin>>n;
	for(int i = 1;i <= n;i ++) {
		scanf("%s",now);
		if(now[0] == s[0] && now[1] == s[1]) {
			puts("YES");
			return 0;
		}
		if(now[1] == s[0]) flag1 =1 ;
		if(now[0] == s[1]) flag2 = 1;
	}
	if(flag1 && flag2) {
		puts("YES");
	}
	else puts("NO");
}