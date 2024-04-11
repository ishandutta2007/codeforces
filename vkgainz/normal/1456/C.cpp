#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f first
#define s second
typedef long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;
const int MX = 5e5+5;
long long sum[MX];
long long val[MX];
int c[MX];
struct cmp {
    bool operator() (const int &x, const int &y) const {
        if(sum[x]==sum[y]) return x<y;
        return sum[x]>sum[y];
    }
};
int main() {
    //use fast io
    int n, k; cin >> n >> k;
    vector<int> neg, pos;
    for(int i=0;i<n;i++) {
        cin >> c[i];
        if(c[i]>=0) pos.push_back(c[i]);
        else neg.push_back(c[i]);
    }
    sort(c, c+n, greater<int>());
    cout << "\n";
    long long curr = 0LL;
    long long ans = 0LL;
    int st = -1;
    for(int i=0;i<n;i++) {
        if(c[i]>=0) {
            ans+=curr;
            curr+=c[i];
        }
        else {
            st = i;
            break;
        }
    }
    if(st==-1) {
        cout << ans << "\n";
        return 0;
    }
    //k+1 subarrays
    sum[0] = curr;
    //greedily ad
    set<int, cmp> in;
    for(int i=0;i<=k;i++) in.insert(i);
    //find the correct order to iterate in...
    for(int i=st;i<n;i++) {
        auto x = in.begin();
        int curr = (*x);
        val[curr]+=sum[curr];
        sum[curr]+=c[i];
        in.erase(x);
        in.insert(curr);
        //cout << sum[(*x)] << "\n";
    }
    for(int i=0;i<=k;i++) ans+=val[i];
    cout << ans << "\n";
}