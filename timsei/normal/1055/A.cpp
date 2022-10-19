#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 +5;

int n, s;
vector <int> A, B;
bool a[N], b[N];

#define OK return 0 * puts("YES") 

int main(void) {
	cin >> n >> s;
	for(int i = 1, x; i <= n; ++ i) {
		scanf("%d", &x);
		if(x) A.push_back(i);
		a[i] = x;
	}
	for(int i = 1, x; i <= n; ++ i) {
		scanf("%d", &x);
		if(x) B.push_back(i);
		b[i] = x;
	}
	if(s == 1) OK;
	else {
		if(!A.size() || A[0] != 1);
		else {
			if(a[s]) OK;
			if(b[s]) {
				for(int i = s; i <= n; ++ i) {
					if(a[i] & b[i]) OK;
				}
			}
		}
	}
	puts("NO");
}