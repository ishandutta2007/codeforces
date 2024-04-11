#include <bits/stdc++.h>
using namespace std;
#define int long long
int secret;
pair<int, int> Ask(vector<int> q, int l, int r) {
int a;
//debug(q, l, r);
#ifndef LOCAL
  cout<<q.size()<<endl;
  for (auto x : q) {
    cout<<x<<" ";
  }
  cout<<endl;
  
  cin>>a;
#else
  if (secret < q[0]) {
    a = 0;
  }
  if (secret > q.back()) {
    a = q.size();
  }
  for (int i = 1; i <= q.size() - 1; i++) {
    if (q[i - 1] == secret) {
      a = -1;
    }
    if (q[i - 1] < secret && secret < q[i]) {
      a = i;
    }
  }
  if (secret == q.back()) {
    a = -1;
  }
#endif
  if (a == -2) {
    exit(1);
  }
  if (a == -1) {
    exit(0);
  }
  if (a == 0) {
    return {l, q[0] - 1};
  }
  if (a == q.size()) {
    return {q.back() + 1, r};
  }
  return {q[a - 1] + 1, q[a] - 1};
  
}
int f(int l, int q) {
	int use = min(l, 10000ll);
	if (q == 1) { return l + use - 1; }
	if (q == 2 && l >= 10000) { return l + (int)1e8 + (int)2e4 - 1; }
	int nxt = l;
	for (int lol = 1; lol <= use + 1; lol++) {
		nxt = f(nxt, q - 1) + 1;
		if (lol != use + 1) {
			nxt++;
		}
	}
	return nxt - 1;
}
void Rec(int l, int r, int q) {
	int use = min(l, 10000ll);
	vector<int> pytaj;
	if (q == 1) { for (int x = l; x <= l + use - 1; x++) { pytaj.push_back(x); }}
	else if (q == 2 && l >= 10000) {
		int R = 1e4;
		int ziom=1;
		for (int x = l + R; ziom <= R; x += R + 1, ziom++) {
			pytaj.push_back(x);
		}
	} else {
		int nxt = l;
		for (int lol = 1; lol <= use; lol++) {
			nxt = f(nxt, q - 1) + 1;
			pytaj.push_back(nxt);
                        nxt++;
		}
	}
	pair<int, int> dupa = Ask(pytaj, l, r);
	l = dupa.first;
	r = dupa.second;
	Rec(l, r, q - 1);
}
int32_t main() {
#ifdef LOCAL
    cin>>secret;
#endif
	//cout<<f(1, 2)<<" "<<f(1, 3)<<" "<<f(1, 4)<<" "<<f(1, 5)<<endl;
	Rec(1, 10004205361450474ll, 5);
	return 0;
}