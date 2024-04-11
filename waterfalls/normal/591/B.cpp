#include <bits/stdc++.h>
using namespace std;

int n,m;
char s[200013];
char res[200];

int main() {
	for (int i=0;i<200;i++) res[i] = i;
	scanf("%d%d %s",&n,&m,&s);
	for (int i=0;i<m;i++) {
		char a,b;
		scanf(" %c %c",&a,&b);
		for (int j=0;j<200;j++) {
			if (res[j]==a) res[j] = b;
			else if (res[j]==b) res[j] = a;
		}
	}
	for (int i=0;i<n;i++) s[i] = res[s[i]];
	printf("%s\n",s);

	return 0;
}