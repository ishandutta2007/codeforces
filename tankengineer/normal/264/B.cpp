#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1000005;

int n, num[N], ans, at[N];

int main() {
	ans = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
	  scanf("%d", &num[i]);
	  if(num[i] == 1) continue;
	  at[num[i]] = 1;
	  int tmp = num[i];
	  for (int j = 2; j * j <= tmp; ++j) {
	    if (tmp % j == 0) {
	      at[num[i]] = max(at[num[i]], at[j] + 1);
				if (tmp / j != j) {
	        at[num[i]] = max(at[num[i]], at[tmp / j] + 1);
				}
			}
		}
		ans = max(ans, at[num[i]]);
	  for (int j = 2; j * j <= tmp; ++j) {
	    if (tmp % j == 0) {
	    	at[j] = max(at[j], at[num[i]]);
				if (tmp / j != j) {
					at[num[i] / j] = max(at[num[i] / j], at[num[i]]);
				}
			}
		}
		//printf("%d\n", at[num[i]]);
	}
	printf("%d\n", ans);
	return 0;
}