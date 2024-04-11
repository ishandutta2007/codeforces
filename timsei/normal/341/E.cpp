#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int A[N], n, m, x, y, tot;

vector <int> S;

struct Node {
	int x, y;
};

vector < Node > ans;

void d(int x, int y) {
	ans.push_back((Node){x, y});
	A[y] -= A[x];
	A[x] *= 2;
}

void getS() {
	S.clear();
	for(int i = 1; i <= n; ++ i) if(A[i]) S.push_back(i);
}

void work(int a, int b, int c) {
	if(A[a] > A[b]) swap(a, b);
	if(A[a] > A[c]) swap(a, c);
	if(A[b] > A[c]) swap(b, c);
	int t = A[b] / A[a];
	for(int i = 0; i < 20; ++ i) {
		if(A[b] < A[a]) break;
		if((t >> i) & 1) d(a, b);
		else d(a, c);
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]);
	for(int i = 1; i <= n; ++ i) if(A[i]) S.push_back(i);
	if(S.size() <= 1) {
		puts("-1");
		return  0;
	}
	while(S.size() > 2) {
		int a = S.back(); S.pop_back();
		int b = S.back(); S.pop_back();
		int c = S.back(); S.pop_back();
		work(a, b, c);
		getS();
	}
	cout << ans.size() << endl;
	for(int i = 0; i < (int) ans.size(); ++ i)
	printf("%d %d\n", ans[i].x, ans[i].y);
}