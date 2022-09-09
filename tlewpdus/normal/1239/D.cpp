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
vector<int> lis[1000100];
vector<int> ris[1000100];
int vis[1000100];
vector<int>ord;

void idfs(int here) {
    vis[here] = 1;
    for (int &there : lis[here]){
        if (vis[there]) continue;
        idfs(there);
    }
    ord.push_back(here);
}

vector<int> scc[1000100];
void rdfs(int here, int sn) {
    scc[sn].push_back(here);
    vis[here] = 2;
    for (int &there : ris[here]) {
        if (vis[there]==2) continue;
        rdfs(there,sn);
    }
}

int main() {
    int tt;

    scanf("%d",&tt);
    while(tt--) {
        scanf("%d%d",&n,&m);
        for (int i=0;i<n;i++) vis[i] = 0;
        for (int i=0;i<m;i++) {
            int a, b;
            scanf("%d%d",&a,&b); --a; --b;
            if (a!=b) {
                lis[a].push_back(b);
                ris[b].push_back(a);
            }
        }
        for (int i=0;i<n;i++) {
            if (vis[i]) continue;
            idfs(i);
        }
        int p = 0;
        for (int idx=n-1;idx>=0;idx--) {
            int i = ord[idx];
            if (vis[i]==2) continue;
            rdfs(i,p);
            p++;
        }
        if (p==1) {
            puts("No");
        }
        else {
            puts("Yes");
            printf("%d %d\n",scc[p-1].size(),n-(int)scc[p-1].size());
            for (int &v : scc[p-1]) printf("%d ",v+1);
            printf("\n");
            for (int i=0;i+1<p;i++) {
                for (int &v :scc[i]) printf("%d ",v+1);
            }
            printf("\n");
        }
        for (int i=0;i<n;i++) {
            lis[i].clear();
            ris[i].clear();
            scc[i].clear();
        }
        ord.clear();
    }

	return 0;
}