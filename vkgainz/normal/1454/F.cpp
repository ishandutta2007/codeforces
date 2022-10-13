#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
const int MX = 2e5+5;
struct cmp {
    bool operator() (const pair<int, int> &x, const pair<int, int> &y) {
        if(x.f!=y.f) return x.f>y.f;
        return x.s<y.s;
    }
};
struct cmp2 {
    bool operator() (const pair<int, int> &x, const pair<int, int> &y) {
        if(x.f!=y.f) return x.f>y.f;
        return x.s>y.s;
    }
};
int seg[2*MX];
int n;
void build() {
    for(int i=n-1;i>=1;i--)
        seg[i] = min(seg[2*i], seg[2*i+1]);
}
int query(int l, int r) {
    l+=n, r+=n;
    int ret = 1000000000;
    while(l<r) {
        if(l%2) ret = min(ret, seg[l++]);
        if(r%2) ret = min(ret, seg[--r]);
        l/=2, r/=2;
    }
    return ret;
}
int main() {
    int t; cin >> t;
    while(t--) {
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++) cin >> a[i];
        map<int, vector<int>> p;
        set<pair<int, int>, cmp> s;
        set<pair<int, int>, cmp2> t;
        for(int i=0;i<n;i++) {
            seg[i+n] = a[i];
            p[a[i]].push_back(i);
            s.insert({a[i], i});
            t.insert({a[i], i});
        }
        build();
        int pref[n], suf[n];
        pref[0] = a[0];
        for(int i=1;i<n;i++) pref[i] = max(pref[i-1], a[i]);
        suf[n-1] = a[n-1];
        for(int i=n-2;i>=0;i--) suf[i] = max(suf[i+1], a[i]);
        int nxtGreater[n];
        int lstGreater[n];
        memset(nxtGreater, -1, sizeof(nxtGreater));
        memset(lstGreater, -1, sizeof(lstGreater));
        set<int> idx;
        for(auto &it : s) {
            auto x = idx.upper_bound(it.s);
            if(x==idx.end())
                nxtGreater[it.s] = -1;
            else
                nxtGreater[it.s] = (*x);
            idx.insert(it.s);
        }
        idx.clear();
        for(auto &it : t) {
            auto x = idx.upper_bound(it.s);
            if(x==idx.begin())
                lstGreater[it.s] = -1;
            else {
                --x;
                lstGreater[it.s] = (*x);
            }
            idx.insert(it.s);
        }
        bool w = 0;
        for(auto &it : p) {
            if(w) continue;
            if(it.s.size()<3) continue;
            int fir = it.s[0];
            int las = it.s[it.s.size()-1];
            if(pref[fir]>it.f || suf[las]>it.f) continue;
            for(int i=1;i<it.s.size()-1 && !w;i++) {
                int mid = it.s[i];
                int markFir = 0, markLast = 0;
                if(nxtGreater[fir]==-1) markFir = mid-1;
                else
                    markFir = min(mid-1, nxtGreater[fir]-1);
                if(lstGreater[las]==-1)
                    markLast = mid+1;
                else
                    markLast = max(mid+1, lstGreater[las]+1);
                int mn = query(markFir+1, markLast);
                if(mn==it.f) {
                //[1, markFir+1], [markFir+2, markLast], [markLast+1, n]
                    w = 1;
                    cout << "YES" << "\n";
                    int x = markFir+1, y= markLast-x, z = n-markLast;
                    cout << x << " " << y << " " << z << "\n";
                }
            }
        }
        if(!w) cout << "NO" << "\n";
    }
}