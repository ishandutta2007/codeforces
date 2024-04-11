#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int mult(int a, int b) { return (1LL*a*b)%MOD; }

char s[100013];

int main() {
	scanf(" %s",&s);
	int ans = 1;
	for (int i=0;s[i]!='\0';i++) {
		int x;
		if (s[i]=='-') x = 62;
		else if (s[i]=='_') x = 63;
		else if (s[i]<='9') x = s[i]-'0';
		else if (s[i]<='Z') x = s[i]-'A'+10;
		else if (s[i]<='z') x = s[i]-'a'+36;
		int cur = 1;
		for (int j=0;j<6;j++) {
			if (!(x&(1<<j))) cur*=3;
		}
		ans = mult(ans,cur);
	}
	printf("%d\n",ans);

	return 0;
}