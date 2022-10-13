#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define f first
#define s second
int seg[2000005];
int sz = 1000000; //check this?
void add(int i,int v) {
    seg[i+=sz]+=v;
    while(i>1) {
        i/=2;
        seg[i] =seg[2*i]+seg[2*i+1];
    }
}
int query(int l,int r) {
    l+=sz, r+=sz;
    int ret = 0;
    while(l<r) {
        if(l%2) ret+=seg[l++];
        if(r%2) ret+=seg[--r];
        l/=2, r/=2;
    }
    return ret;
}
vector<pair<int,int>> v[1000001], h[1000001];
int main() {
    int n,m;
    cin >> n >> m;
    ll ans = 0;
    for(int i=0;i<n;i++) {
        int y,l,r;
        cin >> y >> l >> r;
        h[l].push_back({r,y});
        if(l==0 && r==1000000) ++ans;
    }
    for(int i=0;i<m;i++) {
        int x,l,r;
        cin >> x >> l >> r;
        v[x].push_back({l,r});
        if(l==0 && r==1000000) ++ans;
    }
    multiset<pair<int,int>> in;
    for(int i=0;i<=1000000;i++) {
        for(auto &it : h[i]) {
            in.insert(it);
            add(it.s,1);
        }
        auto x = in.begin();
        while(x!=in.end()) {
            if(x->f<i) {
                add(x->s,-1);
                in.erase(x++);
            }
            else break;
        }
        for(auto &it : v[i]) ans+=query(it.f,it.s+1);
    }
    cout << ans+1 << endl;
}