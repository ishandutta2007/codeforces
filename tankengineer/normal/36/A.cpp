#include<cstdio>
#include<algorithm>
using namespace std;

int n, t1, t2, t3;
char ch;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
  scanf("%d", &n);
  getchar();
  int t1 = 0;
	for (int i = 1; i <= n; ++i) {
	  scanf("%c", &ch);
	  if (ch == '1') {
		  if (t1 != 0) {
			  t3 = i - t1;
			  if (t2 != 0) {
				  if (t3 != t2) {
				    puts("NO");
				    return 0;
					}
				}
				t2 = t3;
			}
			t1 = i;
		}
	}
	puts("YES");
	return 0;
}