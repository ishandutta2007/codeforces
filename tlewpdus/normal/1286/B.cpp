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
vector<int> lis[2010];
vector<int> ord;
vector<int> erd;
int st[2010], en[2010], sz[2010];
int arr[2010];
int etoi[2010];
int ans[2010];

int tim;
void dfs(int here) {
    ord.push_back(here);
    st[here] = tim++;
    sz[here] = 1;
    for (int &there : lis[here]) {
        dfs(there);
        sz[here] += sz[there];
    }
    en[here] = tim-1;
    erd.push_back(here);
    etoi[(int)erd.size()-1] = here;
}

int main() {
    scanf("%d",&n);
    int rt = -1;
    for (int i=0;i<n;i++) {
        int p, c;
        scanf("%d%d",&p,&c); p--;
        if (p>=0) lis[p].push_back(i);
        else rt = i;
        arr[i] = c;
    }
    dfs(rt);
    for (int id=0;id<n;id++) {
        int here = erd[id], sum = 0;
        for (int i=0;i<lis[here].size();i++) {
            int there = lis[here][i];
            for (int j=st[there];j<=en[there];j++) {
                ans[ord[j]]+=sum;
            }
            sum+=sz[there];
        }
        if (arr[here]>=sz[here]) {
            puts("NO");
            return 0;
        }
        ans[here] = arr[here];
        for (int j=st[here]+1;j<=en[here];j++) {
            if (ans[ord[j]]>=ans[here]) {
                ans[ord[j]]++;
            }
        }
    }
    puts("YES");
    for (int i=0;i<n;i++) {
        printf("%d ",ans[i]+1);
    }

	return 0;
}