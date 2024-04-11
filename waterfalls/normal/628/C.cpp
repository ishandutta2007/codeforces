#include <bits/stdc++.h>
using namespace std;

int n,k;
char s[100013];

int main() {
	scanf("%d%d %s",&n,&k,&s);
	int high = 0;
	for (int i=0;i<n;i++) high+=max(s[i]-'a','z'-s[i]);
	if (k>high) return printf("-1\n"), 0;
	for (int i=0;i<n;i++) {
		if (s[i]-'a'>=k) {
			s[i]-=k;
			k = 0;
		} else if ('z'-s[i]>=k) {
			s[i]+=k;
			k = 0;
		} else {
			k-=max(s[i]-'a','z'-s[i]);
			s[i] = (s[i]<='m' ? 'z' : 'a');
		}
	}
	printf("%s\n",s);

    return 0;
}