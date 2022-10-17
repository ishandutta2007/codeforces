#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
    ll a, b;
    bool operator < (const node & n) const {
        return b < n.b;
    }
};
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<node> a(n);
    for(int i=0;i<n;++i) cin>>a[i].a>>a[i].b;
    sort(a.begin(),a.end());
    ll ans=0,cur=0;
    int j=a.size()-1;
    for(int i=0;i<a.size();++i) {
        if(cur<a[i].b) {
            ll need=a[i].b-cur;
            while(j>=i && need) {
                ll p=min(need,a[j].a);
                need-=p;
                a[j].a-=p;
                cur+=p;
                ans+=2*p;
                if(!a[j].a) --j;
            }
            if(j<i) break;
            assert(cur==a[i].b);
        }
        if(!a[i].a) break;
        ans+=a[i].a;
        cur+=a[i].a;
        a[i].a=0;
    }
    cout<<ans<<endl;
}