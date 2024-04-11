#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using lli = long long;
using pii = pair<int,int>;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

int n;
pii arr[200001];
vector<int> xp;
struct seg_tr{
    int tr[200001],cnt[200001];
    void upd(int cur,int val) {
        cnt[cur] += val;
        if((val==1 && cnt[cur]==1) || (val==-1 && cnt[cur]==0)) {
            while(cur<=n) {
                tr[cur]+=val;
                cur+=cur & -cur;
            }
        }
    }
    int get(int cur) {
        int ret=0;
        while(cur) {
            ret += tr[cur];
            cur-=cur&-cur;
        }
        return ret;
    }
    int sum(int l,int r) {
        if(l>r) return 0;
        return get(r) - get(l-1);
    }
}st;

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&arr[i].fi,&arr[i].se),xp.push_back(arr[i].fi);

    sort(arr+1,arr+n+1,[](const pii &a,const pii &b) {
        return a.se!=b.se ? a.se < b.se : a.fi < b.fi;
    });

    sort(xp.begin(),xp.end());
    xp.erase(unique(xp.begin(),xp.end()),xp.end());
    for(int i=1;i<=n;i++) {
        arr[i].fi = lower_bound(xp.begin(),xp.end(),arr[i].fi)-xp.begin() + 1;
        st.upd(arr[i].fi,1);
    }

    lli ans=0;
    for(int i=1,j=1;i<=n;i=j) {
        lli v = st.sum(1,sz(xp));
        ans += 1ll*v*(v+1)/2;

        int pr=1;
        for(j=i;j<=n && arr[i].se==arr[j].se;j++) {
            lli v=st.sum(pr,arr[j].fi-1);
            ans -= 1ll*v*(v+1)/2;
            pr = arr[j].fi+1;
            st.upd(arr[j].fi,-1);
        }
        v=st.sum(pr,sz(xp));
        ans -= 1ll*v*(v+1)/2;
    }
    printf("%lld\n",ans);
    
    return 0;
}