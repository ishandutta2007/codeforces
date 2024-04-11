#include <bits/stdc++.h>

using namespace std;

int main() {
 	int n;
 	cin >> n;
 	vector<int> a(n);
 	vector<int> b(n);
 	for (int i = 0; i < n; i++) {
 	  cin >> a[i];
 	  b[i] = a[i];
 	}
 	sort(b.begin(), b.end());
 	int pos = 0;
 	for (int i = 0; i < n; i++) {
 	 	if (a[i] == b[n - 1]) {
 	 	 	pos = i;
 	 	 	break;
 	 	}
 	}
 	//cout << pos << endl;
 	int cnt = 0;
 	while (pos > 0) {
 	 	swap(a[pos], a[pos - 1]);
 	 	pos--;
 	 	cnt++;
 	}
 	/*for (int i = 0; i < n; i++) {
 	 	cout << a[i] << " ";
 	}
 	cout << endl;*/
 	for (int i = n - 1; i >= 0; i--) {
 		if (a[i] == b[0]) {
 		 	pos = i;
 		 	break;
 	 	}
 	}
 	//cout << pos << endl;
 	cnt += n - pos - 1;
 	cout << cnt;
}