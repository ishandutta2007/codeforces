#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using pii = pair<int,int>;
using lli = long long;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;
using pdd = pair<double,double>;

struct seg_tr{
    const static int MAX = 1<<18;
    lli tr[MAX<<1];
    lli upd(int cur,int s,int f,int idx,int val) {
        if(s==idx && f==idx) return tr[cur]=val;
        else if(idx<s || idx>f) return tr[cur];
        else {
            int nx=cur<<1,md=(s+f)>>1;
            return tr[cur]=upd(nx,s,md,idx,val)+upd(nx+1,md+1,f,idx,val);
        }
    }
    void upd(int idx,int val) {
        upd(1,0,MAX-1,idx,val);
    }
    int kth(int cur,int s,int f,lli k) {
        if(s==f) return s;
        else {
            int nx=cur<<1,md=(s+f)>>1;
            if(tr[nx] >= k) return kth(nx,s,md,k);
            else return kth(nx+1,md+1,f,k-tr[nx]);
        }
    }
    int kth(lli k) {
        return kth(1,0,MAX-1,k);
    }
}st;

int n;
lli arr[200001];
int ans[200002];
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lld",arr+i);
    for(int i=1;i<=n;i++) st.upd(i,i);
    for(int i=n-1;i>=0;i--) {
        int val = st.kth(arr[i]+1);
        ans[i]=val;
        st.upd(val, 0);
    }
    for(int i=0;i<n;i++) printf("%d ",ans[i]);
    return 0;
}