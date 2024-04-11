#include <cstdio>
#include <cstring>

bool has[256];
int main() {
	int k, i, j;
	char str[103];
	int cuts[30]; int c_n = 0;
	scanf("%d %s", &k, str);
	cuts[c_n++] = 0;
	has[str[0]] = true;
	for(i = 1; str[i] && c_n < k; i++) {
		if(!has[str[i]]) {
			has[str[i]] = true;
			cuts[c_n++] = i;
		}
	}
	if(c_n < k) { puts("NO"); return 0; }
	puts("YES");
	cuts[k] = strlen(str);
	for(i = 0; i < k; i++) {
		for(j = cuts[i]; j < cuts[i + 1]; j++)
			putchar(str[j]);
		putchar('\n');
	}
	return 0;
}