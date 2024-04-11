#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int MOD = 998244353;

int main()
{
    int n, k;
    cin >> n >> k;
    if (n == k) {
        cout << (long long)n * (n + 1) / 2 << ' ' << 1 << '\n';
        return 0;
    }
    map<int, int> val_index;
    int val;
    for (int i = 0; i < n; ++i) {
        cin >> val;
        val_index[val] = i;
    }
    vector<int> indexes;
    map<int, int>::iterator last = prev(val_index.end());
    //cout << last->first;
    for (int i = 0; i < k; ++i) {
        indexes.push_back(last->second);
        --last;
    }
    sort(indexes.begin(), indexes.end());
    
    long long result = 1;
    for (int i = 1; i < k; ++i) {
        result *= ((long long)indexes[i] - indexes[i - 1]);
        result %= MOD;
    }
    cout << (long long)k * (2 * n - k + 1) / 2 << ' ' << result << '\n';
    return 0;
}