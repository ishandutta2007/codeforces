#include<cstdio>
#include<cstring>
const int MAXN = 1000;
char s[MAXN + 5], t[MAXN + 5];
int a[256];
int main() {
	scanf("%s%s", s, t);
	int lens = strlen(s), lent = strlen(t);
	a['a'] = a['u'] = a['o'] = a['i'] = a['e'] = 1;
	if( lens != lent ) {
		puts("No");
		return 0;
	}
	else {
		for(int i=0;i<lens;i++) {
			if( a[s[i]] != a[t[i]] ) {
				puts("No");
				return 0;
			}
		}
		puts("Yes");
		return 0;
	}
}