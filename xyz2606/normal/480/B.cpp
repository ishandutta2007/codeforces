#include<cstring>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
int a[111111], n;
int check(int x) {
	set<int> st;
	for(int i(1); i <= n; i++) {
		if(st.count(a[i] - x)) {
			return a[i];
		}
		st.insert(a[i]);
	}
	return 0;
}
int check1(int x) {
	set<int> st;
	int res(0);
	for(int i(1); i <= n; i++) {
		if(st.count(a[i] - x)) {
			res = a[i];
		}
		st.insert(a[i]);
	}
	return res;
}
int main() {
	int l, x, y;
	scanf("%d%d%d%d", &n, &l, &x, &y);
	for(int i(1); i <= n; i++) {
		scanf("%d", &a[i]);
	}
	bool flag1(check(x)), flag2(check(y));
	if(flag1 and flag2) {
		printf("0\n");
	}else {
		if(flag1) {
			printf("1\n%d\n", y);
		}else if(flag2) {
			printf("1\n%d\n", x);
		}else {
			int tmp(check(x + y));
			if(tmp) {
				printf("1\n%d\n", tmp - y);
			}else {
				int tmp(check(y - x));
				if(tmp and tmp + x <= a[n]) {
					printf("1\n%d\n", tmp + x);
				}else {
					int tmp(check1(y - x));
					if(tmp and tmp - y >= 0) {
						printf("1\n%d\n", tmp - y);
					}else {
						printf("2\n%d %d\n", x, y);
					}
				}
			}
		}
	}
}