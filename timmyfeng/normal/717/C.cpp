#include "bits/stdc++.h"
using namespace std;

#define pb push_back

const int N=100001;
int n;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    vector<int> a;
    long long ans=0;
    for(int i=0; i<n ;i++){
        int x; cin >> x;
        a.pb(x);
    }
    sort(a.begin(), a.end());
    for(int i=0; i<n; i++){
        ans+=(long long)a[i]*a[n-1-i];
        ans%=10007;
    }
    cout << ans;
}