#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

vector<int> d[500005];
int main() {
    int n,q;
    cin >> n >> q;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    for(int p=2;p<=500000;p++) {
        if(d[p].size()==0) {
            for(ll j=p;j<=500000;j+=p) {
                d[j].push_back(p);
            }
        }
    }
    ll ans = 0;
    bool in[n];
    memset(in,0,sizeof(in));
    int cnt[500005];
    memset(cnt,0,sizeof(cnt));
    while(q--) {
        int x; cin >> x;
        --x;
        for(int msk=0;msk<1<<d[a[x]].size();msk++) {
            int bit = 0;
            int prod = 1;
            for(int j=0;j<d[a[x]].size();j++) {
                if(msk&(1<<j)) {
                    ++bit;
                    prod*=d[a[x]][j];
                }
            }
            if(in[x]) {
                --cnt[prod];
                if(bit%2) ans+=cnt[prod];
                else ans-=cnt[prod];
            }
            else {
                if(bit%2) ans-=cnt[prod];
                else ans+=cnt[prod];
                ++cnt[prod];
            }
        }
        if(in[x]) in[x] = 0;
        else in[x] = 1;
        cout << ans << endl;
    }
}