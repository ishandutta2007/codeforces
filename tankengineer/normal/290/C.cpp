#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int sum = 0, cnt = 0, sum2 = 0, cnt2 = 1;
	for (int i = 0; i < n; ++i) {
		int t;
	  scanf("%d", &t);
	  sum += t;
	  cnt ++;
	  if (sum * cnt2 > sum2 * cnt) {
	    sum2 = sum;
	    cnt2 = cnt;
		}
	}
	printf("%.12lf\n", (double)sum2 / cnt2);
	return 0;
}