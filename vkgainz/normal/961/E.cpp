#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
const int MX = 2e5+5;
int seg[2*MX];
int n;
void upd(int i, int v) {
    seg[i+=n]+=v;
    while(i>1) {
        i/=2;
        seg[i] = seg[2*i]+seg[2*i+1];
    }
}
int query(int l, int r) {
    l+=n, r+=n;
    int ret = 0;
    while(l<r) {
        if(l%2) ret+=seg[l++];
        if(r%2) ret+=seg[--r];
        l/=2, r/=2;
    }
    return ret;
}
int main() {
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    map<int, vector<int>> freq;
    for(int i=0;i<n;i++)
        freq[a[i]].push_back(i);
    long long ans = 0LL;
    for(int i=0;i<n;i++) upd(i, 1);
    for(int x=1;x<=n;x++) {
        if(a[x-1]>=x) {
            //query
            ans += query(x, min(a[x-1],n));
        }
        for(auto &it : freq[x])
            upd(it, -1);
    }
    cout << ans << "\n";
}