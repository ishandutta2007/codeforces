#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1000;
char s[maxn];
int b, e, len, dot; 
int main() {
	scanf("%s", s);	
	len = strlen(s); 
	for (int i = 0; i < len; ++i)
		if (s[i] == 'e') e = i;
	for (int i = e + 1; i < len; ++i)
		b = b * 10 + s[i] - '0';
		
	for (int i = 0; i < len; ++i)
		if (s[i] == '.') dot = i;
	int r = min(dot + b, e - 1);
	if (s[0] == '0' && b == 0 && dot == 1 && len == 5 && s[2] == '0') printf("0\n");
	else {
		bool flag = true;
		int last = dot == r ? r - 1 : r;
		for (int i = 0; i <= r; ++i) {
			if (i == dot) continue;
			if (s[i] != '0') flag = false;
			if (!flag || i == last)
				printf("%c", s[i]);
		}
		if (dot + b >= e) {
			for (int i = e; i <= dot + b; ++i)
				printf("0");
		}
		else if (dot + b + 1 < e) {
			if (!(dot + b + 1 == e - 1 && s[e - 1] == '0')) {
				printf(".");
				for (int i = dot + b + 1; i < e; ++i)
					printf("%c", s[i]);
			}
		}
	}
}