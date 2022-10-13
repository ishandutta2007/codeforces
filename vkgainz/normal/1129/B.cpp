#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
int main() {
    int k; cin >> k;
    vector<int> ans(2000);
    int n = 2000;
    for(int s=1;s<3000;s++) {
        if((k-n*-s)%(n-1)==0) {
            ans[n-1] = (k-n*-s)/(n-1);
            ans[n-2] = -s;
            cout << 2000 << endl;
            for(int i=0;i<2000;i++) cout << ans[i] << "\n";
            return 0;
        }
    }
    return 0;
}