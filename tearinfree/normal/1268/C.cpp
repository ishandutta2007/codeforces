#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pii = pair<int,int>;

struct seg_tr {
    const static int MAX = 1<<18;
    int tr[MAX<<1];
    lli ls[MAX<<1], rs[MAX<<1];
    
    int upd(int cur,int s,int f,int idx) {
        if(f<idx || s>idx) return tr[cur];
        else if(s==f) return ++tr[cur];
        else {
            int nx=cur<<1,md=(s+f)>>1;
            tr[cur] = upd(nx,s,md,idx) + upd(nx+1,md+1,f,idx);
            ls[cur] = ls[nx] + ls[nx+1] + 1ll*tr[nx+1]*(f-md);
            rs[cur] = rs[nx+1] + rs[nx] + 1ll*tr[nx]*(f-md);
            return tr[cur];
        }
    }
    void upd(int idx) {
        upd(1,0,MAX-1,idx);
    }
    int sum(int cur,int s,int f,int l,int r) {
        if(f<l || s>r) return 0;
        else if(l<=s && f<=r) return tr[cur];
        else {
            int nx=cur<<1,md=(s+f)>>1;
            return sum(nx,s,md,l,r) + sum(nx+1,md+1,f,l,r);
        }
    }
    int sum(int l,int r) {
        return sum(1,0,MAX-1,l,r);
    }
    pair<lli,int> kth(int cur,int s,int f,int k) {
        if(s==f) return {0, s};
        else {
            int nx=cur<<1,md=(s+f)>>1;
            pair<lli,int> tmp;
            if(tr[nx] >= k) {
                tmp = kth(nx,s,md,k);
                tmp.first += ls[nx+1] + 1ll*tr[nx+1]*(md+1-tmp.second);
            } else {
                tmp = kth(nx+1, md+1, f, k - tr[nx]);
                tmp.first += rs[nx] + 1ll*tr[nx]*(tmp.second - md);
            }
            return tmp;
        }
    }
    lli kth(int k) {
        return kth(1,0,MAX-1,k).first;
    }
}st;

int n,arr[200000];

int main() {
    scanf("%d",&n);
    vector<pii> a;
    for(int i=0;i<n;i++) {
        scanf("%d",arr+i);
        a.push_back({arr[i],i});
    }
    sort(a.begin(),a.end());

    lli inv = 0;
    for(int i=0;i<n;i++) {
        auto &v = a[i];
        inv += st.sum(v.second, n-1);
        st.upd(v.second);

        lli ad = st.kth(i/2 + 1);
        int c = (i+1)/2;
        ad -= 1ll*c*(c+1)/2;
        c = i/2;
        ad -= 1ll*c*(c+1)/2;
        printf("%lld ", inv + ad);
    }
    return 0;
}