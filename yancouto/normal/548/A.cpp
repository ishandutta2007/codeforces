#include <cstdio>
#include <cstring>
#ifndef ONLINE_JUDGE
#define debug(...) fprintf(stderr, "%d: ", __LINE__); fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) //
#endif

bool pal(char s[], int st, int fi) {
	int i = st, j = fi;
	while(j > i) {
		if(s[i] != s[j])
			return false;
		i++; j--;
	}
	return true;
}

int main() {
	char s[1004];
	scanf(" %s", s);
	int k;
	scanf("%d", &k);
	int size = strlen(s);
	if(size % k) {
		puts("NO");
		return 0;
	}
	size /= k;
	for(int i = 0; i < k; i++)
		if(!pal(s, i * size, (i + 1) * size - 1)) {
			puts("NO");
			return 0;
		}
	puts("YES");
	return 0;
}