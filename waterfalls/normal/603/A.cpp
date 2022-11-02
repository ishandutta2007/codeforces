#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
	int n;
	cin >> n >> s;
	int ans = 0;
	for (int i=0;i<n;i++) if (s[i]!=s[i+1]) ans+=1;
	printf("%d\n",min(ans+2,n));

	return 0;
}