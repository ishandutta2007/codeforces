#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n, sum, top, s1[5005], s2[5005], l, tmp, a, ord[5005];
char s[50005];

bool cmp(int i, int j) {return s1[i] < s1[j];}

int main() {
  scanf("%d", &a);
  getchar(); gets(s);
  l = strlen(s);
  for (int i = 0; i < l; ++i) {
	  if (s[i] == 'a') {
		  if (i > 1 && s[i - 1] == '+' && s[i - 2] == '+') {
			  s[i - 2] = '@';
			  s[i - 1] = s[i] = ' ';
			} else if (i < l - 2 && s[i + 1] == '+' && s[i + 2] == '+') {
			  s[i] = '#';
			  s[i + 1] = s[i + 2] = ' ';
			}
		}
	}
	s[l] = '+';
	//puts(s);
	int t1, t2;
	t1 = -1; t2 = 1;
	for (int i = 0; i <= l; ++i) {
	  if (s[i] == '+' || s[i] == '-') {
		  tmp = 0;
		  int j;
		  for (j = t1 + 1; s[j] >= '0' && s[j] <= '9'; ++j) tmp = tmp * 10 + s[j] - '0';
		  if (j != t1 + 1) t2 = t2 * tmp;
		  if (s[j] == '*') ++j;
		  ++top; s1[top] = t2;
			if (s[j] == '@') s2[top] = 1; else s2[top] = 0;
			ord[top] = top;
		  t1 = i; t2 = s[i] == '+' ? 1 : -1;
		}
	}
	sort(ord + 1, ord + 1 + top, cmp);
	for (int i = 1; i <= top; ++i) {
	  if (s2[ord[i]]) {
		  ++a;
		  sum += a * s1[ord[i]];
		} else {
			sum += a * s1[ord[i]];
			++a;
		}
	}
	printf("%d\n", sum);
	return 0;
}