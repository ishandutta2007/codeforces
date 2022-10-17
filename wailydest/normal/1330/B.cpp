#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;

void solve()
{
    int n;
    int arr[200000];
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    
    vector<int> p1, p2, ans;
    
    set<int> m;
    int dif_amt = 0;
    
    int val;
    for (int i = 0; i < n - 1; ++i) {
        val = arr[i];
        if (m.count(val)) break;
        m.insert(val);
        dif_amt++;
        if (dif_amt == *prev(m.end())) p1.push_back(i);
    }
    
    m.clear();
    
    dif_amt = 0;
    for (int i = n - 1; i > 0; --i) {
        val = arr[i];
        if (m.count(val)) break;
        m.insert(val);
        dif_amt++;
        if (dif_amt == *prev(m.end())) p2.push_back(i - 1);
    }
    
    m.clear();
    for (int i : p1) m.insert(i);
    
    int amt = 0;
    for (int i : p2) if (m.count(i)) {
        ++amt;
        ans.push_back(i);
    }
    
    cout << amt << '\n';
    
    for (int i : ans) cout << i + 1 << ' ' << n - i - 1 << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}