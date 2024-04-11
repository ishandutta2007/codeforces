#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int n, m, s, k;
int D[1600][1600];
int E[1600][1600];
vector<pii> vec;
deque<int> q[1600];

int solve() {
    sort(vec.begin(),vec.end(),[](pii a, pii b){return a.first<b.first||(a.first==b.first&&
                                                                         a.second>b.second);});
    int i, j, maxi = -1;
    for (i=0;i<vec.size();i++) {
        if (vec[i].second<vec[i].first) {
            vec[i] = pii(INF,INF);
            continue;
        }
        if (maxi>=vec[i].second) {
            vec[i] = pii(INF,INF);
            continue;
        }
        maxi = max(maxi,vec[i].second);
    }
    vec.push_back(pii(-1,-1));
    sort(vec.begin(),vec.end());
    while(!vec.empty()&&vec.back()==pii(INF,INF)) vec.pop_back();
    int p = 0;
    for (i=1;i<vec.size();i++) {
        while(p<i&&vec[p+1].second<vec[i].first) p++;
        for (j=0;j<i;j++) {
            while(!q[j].empty()&&q[j].front()<=p) q[j].pop_front();
        }
        for (j=1;j<=i;j++) {
            D[i][j] = max(E[p][j-1]+vec[i].second-vec[i].first+1,
                          q[j-1].empty()?-INF:(D[q[j-1].front()][j-1]+vec[i].second-vec[q[j-1].front()].second));
            E[i][j] = max(D[i][j],E[i-1][j]);
        }
        for (j=1;j<=i;j++) {
            while(!q[j].empty()&&D[q[j].back()][j]-vec[q[j].back()].second<
                  D[i][j]-vec[i].second) q[j].pop_back();
            q[j].push_back(i);
        }
    }
    for (i=1;i<vec.size();i++) q[i].clear();
    int ans = 0;
    for (i=0;i<=m;i++) ans = max(ans,E[(int)vec.size()-1][i]);
    return ans;
}

int arr[1600];
int ord[1600];

vector<pii> rrr;
vector<int> liv;
bool ok(int t) {
    int i;
    liv.clear();
    for (i=0;i<t;i++) {
        liv.push_back(ord[i]);
    }
    sort(liv.begin(),liv.end());
    vec.clear();
    for (i=0;i<rrr.size();i++) {
        vec.push_back(pii(lower_bound(liv.begin(),liv.end(),rrr[i].first)-liv.begin(),
                          upper_bound(liv.begin(),liv.end(),rrr[i].second)-liv.begin()-1));
    }
    return solve()>=k;
}

int main() {
    int i, j;
    scanf("%d%d%d%d",&n,&s,&m,&k);
    for (i=0;i<n;i++) scanf("%d",&arr[i]);
    for (i=0;i<s;i++) {
        int a, b;
        scanf("%d%d",&a,&b); --a; --b;
        rrr.push_back(pii(a,b));
    }
    for (i=0;i<n;i++) ord[i] = i;
    sort(ord,ord+n,[](int a, int b){return arr[a]<arr[b];});
    int st = 1, en = n;
    while(st<=en) {
        int mid = (st+en)/2;
        if (ok(mid)) en = mid-1;
        else st = mid+1;
    }
    if (st>n) printf("-1\n");
    else printf("%d\n",arr[ord[st-1]]);

    return 0;
}