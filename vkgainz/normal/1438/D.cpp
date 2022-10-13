#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define f first
#define s second
vector<int> a(100001);
vector<vector<int>> ans;
void upd(int i, int j, int k ){
    vector<int> t(3);
    t[0] = i, t[1] = j, t[2] = k;
    ans.push_back(t);
    int x = a[i]^a[j]^a[k];
    a[i] = x, a[j] = x, a[k] = x;
}
int main() {
    int n; cin >> n;
    int x = 0;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        x^=a[i];
    }
    if(n%2) {
        cout << "YES" << endl;
        for(int i=0;i+2<n;i+=2) upd(i, i+1, i+2);
        for(int i=n-4;i>=0;i-=2) {
            upd(i,i-1,n-1);
        }
        cout << ans.size() << endl;
        for(auto &it : ans) cout << it[0]+1 << " " << it[1]+1 << " " << it[2]+1 << endl;
    }
    else {
        if(x) cout << "NO" << endl;
        else {
            cout << "YES" << endl;

            for(int i=0;i+2<n-1;i+=2) {
                upd(i, i+1, i+2);
            }
            for(int i=n-5;i>=0;i-=2) {
                upd(i, i-1, n-2);
            }
            cout << ans.size() << endl;
            for(auto &it : ans) cout << it[0]+1 << " " << it[1]+1 << " " << it[2]+1 << endl;

        }
    }

}