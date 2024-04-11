#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MX = 2e5;

int main() {
    int n, q; cin >> n >> q;
    int a[n];
    for(int i=0;i<n;i++) 
        cin >> a[i];
    int f[200001], l[200001];
    memset(f, 0, sizeof(f));
    memset(l, 0, sizeof(l));
    for(int i=0;i<n;i++) 
        l[a[i]] = i;
    for(int i=n-1;i>=0;i--)
        f[a[i]] = i;
    set<int> in;
    multiset<int, greater<int>> inFreq;
    int left = 0;
    int ans = 0;
    int freq[200001];
    memset(freq, 0, sizeof(freq));
    for(int i=0;i<n;i++) {
        if(f[a[i]]==i) {
            in.insert(a[i]);
        }
        else inFreq.erase(inFreq.lower_bound(freq[a[i]]));
        ++freq[a[i]];
        inFreq.insert(freq[a[i]]);
        if(l[a[i]]==i) {
            in.erase(a[i]);
            if(in.empty()) {
                ans+=(i-left+1)-*inFreq.begin();
                inFreq.clear();
                left = i+1;
            }
        }
    }
    cout << ans;
}