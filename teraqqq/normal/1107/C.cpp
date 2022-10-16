#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

const int N = 2e5+7;

int n, k, a[N], q;
char s[N];
ll total;
vector<int> p;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n; ++i)
    	cin >> a[i];
    cin >> s;

    for(int i = 0;; ++i) {
    	if(i < n) total += a[i];
    	if(i > 0 && s[i-1] != s[i] || i==n) {
    		sort(p.begin(), p.end());
    		for(int j = 0; p.size() - j > k; ++j)
    			total -= p[j];
    		p.clear();
    	}
    	if(i == n) break;

    	p.push_back(a[i]);
    }

    cout << total;
}