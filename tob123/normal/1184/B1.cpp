#include <bits/stdc++.h>
using namespace std;

#define Debug(x) x
typedef int regular_int;
// #define int ll
typedef long long ll;


pair<int, int > A[200000], B[200000];
ll res[200000];


regular_int main() {
	ios_base::sync_with_stdio(false);
	cout << setprecision(12) << fixed;

	int s, b;
	cin >> s >> b;
	for (int i = 0; i < s; ++i) {
        cin >> A[i].first;
        A[i].second = i;
	}
	sort(A, A + s);
	for (int i = 0; i < b; ++i) {
        cin >> B[i].first >> B[i].second;
	}
	sort(B, B + b);
	int pos = 0;
	ll sum = 0;
	for (int i = 0; i < s; ++i) {
        while (pos < b && B[pos].first <= A[i].first){
            sum += B[pos].second;
            ++pos;
        }
        res[A[i].second] = sum;
	}
	for (int i = 0; i < s; ++i) {
        if (i)cout << " ";
        cout << res[i];
	}
	cout << endl;
	return 0;
}