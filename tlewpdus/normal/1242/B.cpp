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

int n, m;
vector<int> lis[100100];
vector<int> avail;
int chk[100100];
int mc[100100];

void dfs(int here) {
    chk[here] = 1;
    for (int &there : lis[here]) {
        mc[there] = 1;
    }
    vector<int> nxt;
    for (int i=0;i<avail.size();i++) {
        if (mc[avail[i]]) continue;
        nxt.push_back(avail[i]);
        swap(avail[i],avail.back());
        avail.pop_back();
        i--;
    }
    for (int &there : lis[here]) {
        mc[there] = 0;
    }
    for (int &there : nxt) {
        dfs(there);
    }
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++) {
        int a, b;
        scanf("%d%d",&a,&b);
        --a; --b;
        lis[a].push_back(b);
        lis[b].push_back(a);
    }
    for (int i=0;i<n;i++) avail.push_back(i);
    int c = -1;
    for (int i=0;i<avail.size();i++) {
        int t = avail[i];
        swap(avail[i],avail.back());
        avail.pop_back();
        i--;
        dfs(t);
        c++;
    }
    printf("%d\n",c);

	return 0;
}