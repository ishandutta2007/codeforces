#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool work(ll x, vector<int> &a, vector<int> &b) {
    ll r = 0;
    for(int i=0;i<a.size();i++) {
        if(a[i]>x) r+=b[i];
    }
    return r<=x;
}
ll binarySearch(ll lo,ll hi,vector<int> &a, vector<int> &b) {
    ll mid = (lo+hi)/2;
    if(work(mid,a,b)) {
        if(mid-1<1 || !work(mid-1,a,b)) return mid;
        return binarySearch(lo,mid-1,a,b);
    }
    return binarySearch(mid+1,hi,a,b);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];
        cout << binarySearch(0,1e15,a,b) << endl;
    }
}