#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e6 + 13;
int n, match[maxN], cnt, ans;
char s[maxN];
stack<int> stk;
vector<int> vec;
int main () {
    cin >> n;
    for (int i = 1; i <= n; i++)
	cin >> s[i];
    for (int i = 1; i <= n; i++) {
	if (s[i] == '(') {
	    stk.push(i);
	}
	else if (stk.size()) {
	    int u = stk.top();
	    stk.pop();
	    match[i] = u;
	    match[u] = i;
	}
    }
    for (int i = 1; i <= n; i++) {
	if (match[i] == 0) {
	    cnt++;
	    vec.push_back(i);
	}
    }
    if (cnt != 2)
	return cout << 0 << endl, 0;
    
    if (s[vec[0]] != s[vec[1]])
	return cout << 0 << endl, 0;
    if (s[vec[0]] == '(') {
    for (int i = vec[1]; i <= n; i++)
	if (s[i] == s[vec[1]])
	    ans++;
    }
    else {
	for (int i = 1; i <= vec[0]; i++)
	    if (s[i] == s[vec[0]])
		ans++;
    }
    cout << ans << endl;
}