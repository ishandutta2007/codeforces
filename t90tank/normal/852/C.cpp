#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const int mxn = 50006;

int n;
int a[mxn];
pair<int,int> b[mxn];

int c[mxn];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	
	for (int i = 0; i < n; ++i)
		b[i] = {a[(i + 1) % n] + a[i], i};
	sort(b, b + n);
	
	for (int i = 0; i < n; ++i)
		c[b[i].sec] = i;
	
	for (int i = 0; i < n; ++i)
		printf("%d ", c[i]);
	puts("");
		
	return 0;
}