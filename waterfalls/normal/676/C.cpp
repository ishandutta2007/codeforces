#include <bits/stdc++.h>
using namespace std;

int n,k;
char s[100013];

int solve() {
	int has = 0;
	int res = 0;
	for (int l=0, r=0;l<n;l++) {
		while (r<n && has+(s[r]=='b')<=k) has+=(s[r++]=='b');
		res = max(res,r-l);
		has-=(s[l]=='b');
	}
	return res;
}

int main() {
	scanf("%d%d %s",&n,&k,&s);
	int ans = solve();
	for (int i=0;i<n;i++) s[i] = 'a'+'b'-s[i];
	printf("%d\n",max(ans,solve()));

	return 0;
}