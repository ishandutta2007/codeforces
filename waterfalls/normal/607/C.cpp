#include <bits/stdc++.h>
using namespace std;

int n;
char s[2000013];
int z[2000013];
char rev[200];

int main() {
	rev['N'] = 'S', rev['S'] = 'N';
	rev['W'] = 'E', rev['E'] = 'W';
	scanf("%d",&n);
	n-=1;
	scanf(" %s %s",s+0,s+n);
	reverse(s,s+n);
	for (int i=n;i<2*n;i++) s[i] = rev[s[i]];
	int l = 0, r = 0;
	for (int i=1;i<2*n;i++) {
		z[i] = min(z[i-l],max(0,r-i));
		while (s[z[i]]==s[i+z[i]]) z[i]+=1;
		if (i+z[i]>r) l = i, r = i+z[i];
	}
	for (int i=n;i<2*n;i++) if (i+z[i]==2*n) return printf("NO\n"), 0;
	printf("YES\n");

	return 0;
}