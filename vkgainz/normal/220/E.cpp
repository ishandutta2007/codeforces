#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
int sz = 1;
ll segL[400005];
ll segR[400005];
void add(int i, ll v, bool b) {
    i+=sz;
    if(b) segL[i]+=v;
    else segR[i]+=v;
    while(i>1) {
        i/=2;
        if(b) segL[i] = segL[2*i]+segL[2*i+1];
        else segR[i] = segR[2*i]+segR[2*i+1];
    }
}
ll query(int l,int r,bool b) {
    l+=sz, r+=sz;
    ll ret = 0;
    while(l<r) {
        if(l%2) {
            if(b) ret+=segL[l++];
            else ret+=segR[l++];
        }
        if(r%2) {
            if(b) ret+=segL[--r];
            else ret+=segR[--r];
        }
        l/=2, r/=2;
    }
    return ret;
}
void compress(vector<int> &n) {
    set<int> s;
    for(int i=0;i<n.size();i++) s.insert(n[i]);
    map<int,int> m;
    int v = 0;
    for(auto &it : s) m[it] = v++;
    for(int i=0;i<n.size();i++) n[i] = m[n[i]];
}
int main() {
    int n; cin >> n;
    while(sz<n) sz*=2;
    ll k; cin >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    compress(a);
    int l = 0, r = 1;
    ll num = 0;
    ll ans = 0;
    for(int i=n-1;i>=1;i--) {
        add(a[i],1,0);
        num+=query(0,a[i],0);
    }
    while(l<n) {
        add(a[l], 1, 1);
        num+=query(a[l]+1,n,1);
        num+=query(0,a[l],0);
        while(num>k && r<n) {
            add(a[r], -1, 0);
            num-=query(0,a[r],0);
            num-=query(a[r]+1,n,1);
            ++r;
        }
        while(r<=l && r<n) {
            add(a[r], -1, 0);
            num-=query(0,a[r],0);
            num-=query(a[r]+1,n,1);
            ++r;
        }
        ans+=n-r;
        ++l;
    }
    cout << ans << endl;
}