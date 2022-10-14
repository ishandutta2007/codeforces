#include <bits/stdc++.h>

using namespace std;

int main() {
 vector<int> a(4);
 int cnt = 0;
 for (int i = 0; i < 4; i++) {
 	 cin >> a[i];
 }
 sort(a.begin(), a.end());
 for (int i = 1; i < 4; i++) {
 	if (a[i] == a[i - 1]) {
 	 	cnt++;
 	}
 }
 cout << cnt;
}