#include <bits/stdc++.h>
using namespace std;

using namespace std;

char s[1111111];


main(void) {
	scanf("%s" , s + 1);
	int now = strlen(s + 1);
	for(int i = 1;i <= now;++ i) cout << s[i];
	for(int i = now;i >= 1;-- i) cout << s[i];
}