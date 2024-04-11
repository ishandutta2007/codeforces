#include<cassert>
#include<cstdio>
#include<cstring>

const int N = 1000005;

int n;

char s[N];

int top, a[N];

int main() {
	scanf("%s", s);
	n = strlen(s);
	bool solution = true;
	int ans = 0;

	top = -1;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '<' || s[i] == '{') {
			top += 1;
			a[top] = s[i];
		} else {
			if (top == -1) {
				solution = false;
				break;
			}
			int sl = a[top];
			top -= 1;
			if (!((sl == '(' && s[i] == ')') 
			   || (sl == '[' && s[i] == ']')
			   || (sl == '<' && s[i] == '>')
			   || (sl == '{' && s[i] == '}'))) {
				++ans;
			}
		}
	}

	if (top != -1) {
		solution = false;
	}

	if (solution) {
		printf("%d\n", ans);
	} else {
		printf("Impossible\n");
	}
	return 0;
}