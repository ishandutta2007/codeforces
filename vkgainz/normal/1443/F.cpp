#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
struct seg {
    vector<int> t;
    int sz = 1;
    void init(int n) {
        while(sz<n) sz*=2;
        t.assign(2*sz,0);
    }
    void upd(int i) {
        ++t[i+=sz];
        while(i>1) {
            i/=2;
            t[i] = t[2*i]+t[2*i+1];
        }
    }
    int query(int l,int r) {
        l+=sz, r+=sz;
        int ret = 0;
        while(l<r) {
            if(l%2) ret+=t[l++];
            else ret+=t[--r];
            l/=2, r/=2;
        }
        return ret;
    }
};
ll mod = 998244353;
int main() {
    int t; cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        int a[n], b[k];
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<k;i++) cin >> b[i];
        int pos[n];
        for(int i=0;i<n;i++) {
            --a[i];
            pos[a[i]] = i;
        }
        for(int i=0;i<k;i++) --b[i];
        set<int> curr;
        seg tree;
        tree.init(n);
        ll ans = 1;
        for(int i=0;i<k;i++) curr.insert(pos[b[i]]);
        for(int i=0;i<k;i++) {
            bool left = 0, right = 0;
            auto it = curr.lower_bound(pos[b[i]]);
            int sum;
            if(it==curr.begin()) {
                sum = tree.query(0,pos[b[i]]);
                if(sum<pos[b[i]]) left = true;
            }
            else {
                --it;
                sum = tree.query((*it),pos[b[i]]);
                if(sum<pos[b[i]]-(*it)-1) left = true;
            }
            it = curr.upper_bound(pos[b[i]]);
            if(it==curr.end()) {
                sum = tree.query(pos[b[i]],n);
                if(sum<n-pos[b[i]]-1) right = true;
            }
            else {
                sum = tree.query(pos[b[i]],(*it));
                if(sum<(*it)-pos[b[i]]-1) right = true;
            }
            if(left && right) {
                tree.upd(pos[b[i]]);
                ans*=1LL*2;
            }
            else if(!left && !right) {
                ans*=0;
            }
            else {
                tree.upd(pos[b[i]]); //check this
            }
            ans%=mod;
            curr.erase(pos[b[i]]);
        }
        cout << ans << endl;
    }
}