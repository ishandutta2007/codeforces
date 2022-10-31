#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using pii = pair<int,int>;
using lli = long long;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

int n;
pli arr[10000];

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lld",&arr[i].fi);
    for(int i=0;i<n;i++) scanf("%d",&arr[i].se);
    sort(arr,arr+n);

    lli s = 0;
    vector<lli> ta;
    for(int i=0,j=0;i<n;i=j){
        int cnt=0;
        for(j=i;j<n && arr[i].fi==arr[j].fi;j++) cnt++;
        if(cnt>1) ta.push_back(arr[i].fi);
    }

    for(int i=0;i<n;i++) {
        int f=0;
        for(auto &it:ta) if((it & arr[i].fi) == arr[i].fi) f=1;
        if(f) s += arr[i].se;
    }
    printf("%lld\n",s);

    return 0;
}