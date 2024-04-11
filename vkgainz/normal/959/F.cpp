#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
int basis[21];
int sz;
int t[100001];
int mod = 1000000007;
void insert(int msk) {
    int temp = msk;
    for(int i=0;i<21;i++) {
        if((msk&(1<<i))==0) continue;
        if(!basis[i]) {
            basis[i] = msk;
            ++sz;
            return;
        }
        msk^=basis[i];
    }
}
bool query(int num) {
    for(int i=0;i<20;i++) {
        if(num&(1<<i)) {
            if(!basis[i]) return 0;
            num^=basis[i];
        }
    }
    return 1;
}
int main() {
    int n; cin >> n;
    int q; cin >> q;
    int a[n];
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    vector<pair<int,int>> queries[n];
    for(int i=0;i<q;i++) {
        int l,x;
        cin >> l >> x;
        --l;
        queries[l].push_back({x,i});
    }
    t[0] = 1;
    for(int i=1;i<=n;i++) {
        t[i] = t[i-1]*2;
        if(t[i]>mod) t[i]-=mod;
    }
    int ans[q];
    for(int i=0;i<n;i++) {
        insert(a[i]);
        for(auto &it : queries[i]) {
            if(!query(it.f)) ans[it.s] = 0;
            else ans[it.s] = t[i+1-sz];
        }
    }
    for(int i=0;i<q;i++) cout << ans[i] << endl;
}