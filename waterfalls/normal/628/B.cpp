#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char s[300013];

int main() {
	scanf(" %s",&s);
	ll ans = 0;
	for (int i=0;s[i]!='\0';i++) {
		if ((s[i]-'0')%4==0) ans+=1;
		if (i) {
			if ((10*(s[i-1]-'0')+(s[i]-'0'))%4==0) {
				ans+=i;
			}
		}
	}
	printf("%lld\n",ans);

    return 0;
}