#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
int cho(vector<string> &a, char c) {
    vector<int> dif(n);
    vector<vector<int>> cnt(n, vector<int>(5));

    for(int i = 0; i < n; ++i) {
//        cout << "PRINTING VAL\n";
  //      cout << a[i] << endl;
    //    cout << "DONE PRINTING VAL\n";
        for(char ch : a[i]) {
            ++cnt[i][ch - 'a'];
        }
        int res = cnt[i][c - 'a'] - (cnt[i][0] + cnt[i][1] + cnt[i][2] + cnt[i][3] + cnt[i][4] - cnt[i][c - 'a']); 
        dif[i] = res; 
    }
    // now its just find max diff

    sort(dif.begin(), dif.end());
    reverse(dif.begin(), dif.end());
    //cout << "Dif: " << "\n";
    if(dif[0] <= 0) {
        return 0;
    }
    int ans=1;
    int cur=dif[0];
    for(int i = 1; i < n; ++i) {
       if(cur + dif[i] > 0) {
           cur += dif[i];
            ans=i + 1;
       } 
    }
    return ans;
}

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        cin >> n;
        vector<string> g(n);
        for(auto &i : g)
            cin >> i;

        int ans=0;
        for(int i = 0; i < 5; ++i)
            ans = max(ans, cho(g, 'a' + i));
        cout << ans << "\n";
    }
}