#include <bits/stdc++.h>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
	  int n;
	  cin >> n;
	  vector<int> a(n);
	  vector<pair<int, int>> pre(n);
	  vector<pair<int, int>> suf(n);
	  for (int i = 0; i < n; i++) {
	   	cin >> a[i];
	   	if (i == 0) {
	   	 	pre[i].first = a[i];
	   	 	pre[i].second = i;
	   	} else {
	   	 	pre[i].first = pre[i - 1].first;
	   	 	pre[i].second = pre[i - 1].second;
	   	 	if (pre[i].first > a[i]) {
	   	 	 	pre[i].first = a[i];
	   	 	 	pre[i].second = i;
	   	 	}
	   	}
	  }
	  for (int i = n - 1; i >= 0; i--) {
	   	if (i == n - 1) {
	   	 	suf[i].first = a[i];
	   	 	suf[i].second = i;
	   	} else {                    
	   		suf[i].first = suf[i + 1].first;
	   	 	suf[i].second = suf[i + 1].second;
	   	 	if (suf[i].first > a[i]) {
	   	 	 	suf[i].first = a[i];
	   	 	 	suf[i].second = i;
	   	 	}
	   	}
	  }
	  bool ok = false;
	  for (int i = 1; i < n - 1; i++) {
	   	if (a[i] > pre[i - 1].first && a[i] > suf[i + 1].first) {
	   	 	ok = true;
	   	 	cout << "YES" << endl << pre[i - 1].second + 1 << " " << i + 1 << " " << suf[i + 1].second + 1 << endl;
	   	 	break;
	   	}
	  }
	  if (ok == false) {
	   	cout << "NO" << endl;
	  }
  }	    
}