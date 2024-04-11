#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n;
int arr[400100];
vector<int> comp;
int cnt[400100];
int ord[400100];

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
        comp.push_back(arr[i]);
    }
    sort(comp.begin(),comp.end());
    comp.erase(unique(comp.begin(),comp.end()),comp.end());
    for (int i=0;i<n;i++) {
        arr[i] = lower_bound(comp.begin(),comp.end(),arr[i])-comp.begin();
        cnt[arr[i]]++;
    }
    iota(ord,ord+comp.size(),0);
    sort(ord,ord+comp.size(),[](int a, int b){return cnt[a]<cnt[b];});
    int p = 0;
    ll maxi = -1;
    int maxp, maxq;
    ll sum = 0;
    for (int i=1;i<=n;i++) {
        while(p<comp.size()&&cnt[ord[p]]<=i) {
            sum += cnt[ord[p]];
            p++;
        }
        if (i<=(sum+1LL*((int)comp.size()-p)*i)/i&&maxi<(sum+1LL*((int)comp.size()-p)*i)/i*i) {
            maxi=(sum+1LL*((int)comp.size()-p)*i)/i*i;
            maxp=i;
            maxq=(sum+1LL*((int)comp.size()-p)*i)/i;
        }
    }
    printf("%lld\n",1LL*maxp*maxq);
    printf("%d %d\n",maxp,maxq);
    for (int i=0;i<comp.size();i++) {
        cnt[i] = min(cnt[i],maxp);
    }
    sort(ord,ord+comp.size(),[](int a, int b){return cnt[a]>cnt[b];});
    vector<vector<int>> grid;
    grid.assign(maxp,vector<int>());
    for (int i=0;i<maxp;i++) grid[i].assign(maxq,0);
    p = 0;
    for (int i=0;i<maxq;i++) {
        for (int j=0;j<maxp;j++) {
            if (cnt[ord[p]]==0) p++;
            cnt[ord[p]]--;
            grid[j][(i+j)%maxq] = comp[ord[p]];
        }
    }
    for (int i=0;i<maxp;i++) {
        for (int j=0;j<maxq;j++) printf("%d ",grid[i][j]);
        puts("");
    }

	return 0;
}