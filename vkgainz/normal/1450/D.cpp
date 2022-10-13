#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define f first
#define s second
const int MX = 3e5+5;
int seg[2*MX];
int sum[2*MX];
int n;
void upd(int i, int v, bool b) {
    seg[i+=n] = v;
    while(i>1) {
        i/=2;
        if(b) seg[i] = max(seg[2*i], seg[2*i+1]);
        else seg[i] = min(seg[2*i], seg[2*i+1]);
    }
}
int query(int l, int r) {
    int ret = -1;
    l+=n, r+=n;
    //cout << l << " " << r << "\n";
    while(l<r) {
        if(l%2) ret = max(ret, seg[l++]);
        if(r%2) ret = max(ret, seg[--r]);
        l/=2, r/=2;
    }
    return ret;
}
int query2(int l, int r) {
    int ret = n;
    l+=n, r+=n;
    while(l<r) {
        if(l%2) ret = min(ret, seg[l++]);
        if(r%2) ret = min(ret, seg[--r]);
        l/=2, r/=2;
    }
    return ret;
}
void updSum(int i, int v) {
    sum[i+=n] = 1;
    while(i>1) {
        i/=2;
        sum[i] = sum[2*i]+sum[2*i+1];
    }
}
int get(int l, int r) {
    l+=n, r+=n;
    int ans = 0;
    while(l<r) {
        if(l%2) ans+=sum[l++];
        if(r%2) ans+=sum[--r];
        l/=2, r/=2;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> n;
        for(int i=0;i<=2*n;i++)
            seg[i] = -1, sum[i] = 0;
        int a[n];
        set<int> pos[n];
        for(int i=0;i<n;i++) {
            cin >> a[i];
            --a[i];
            pos[a[i]].insert(i);
        }
        //find ranges
        int st[n], en[n];
        memset(st, 0, sizeof(st));
        memset(en, 0, sizeof(en));
        for(int i=0;i<n;i++) {
            int x = query(0, a[i])+1;
            st[i] = x;
            upd(a[i], i, true);
        }
        for(int i=0;i<=2*n;i++)
            seg[i] = n;
        for(int i=n-1;i>=0;i--) {
            int x = query2(0, a[i])-1;
            en[i] = x;
            upd(a[i], i, false);
        }
        vector<int> in[n+1];
        for(int i=0;i<n;i++) {
            in[en[i]-st[i]+1].push_back(a[i]);
        }
        bool work[n+1];
        memset(work, false, sizeof(work));
        for(int i=n;i>0;i--) {
            for(int x : in[i]) {
                updSum(x, 1);
                if(get(0, n-i+1)==n-i+1) {
                    work[i] = true;
                }
            }
        }
        string ans = "";
        for(int i=1;i<=n;i++) {
            if(work[i]) ans+="1";
            else ans+="0";
        }
        cout << ans << "\n";
    }
}