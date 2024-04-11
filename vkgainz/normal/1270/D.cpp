#include <bits/stdc++.h>
using namespace std;

int query(vector<int> &v) {
    cout << "? ";
    for(int x : v) cout << x + 1 << " ";
    cout << "\n";
    cout.flush();
    pair<int, int> ret;
    cin >> ret.first >> ret.second;
    return ret.second;
}

int main() {
    int n, k; cin >> n >> k;
    vector<int> in;
    vector<int> to_query;
    for(int i = 0; i <= k; i++) {
        to_query.clear();
        for(int j = 0; j <= k; j++)
            if(j != i)
                to_query.push_back(j);
        in.push_back(query(to_query));
    }
    sort(in.begin(), in.end());
    int m = 0;
    for(int i = (int) in.size() - 1; i >= 1; i--) {
        ++m;
        if(in[i] > in[i - 1]) break;
    }
    cout << "! " <<  m << "\n";
}