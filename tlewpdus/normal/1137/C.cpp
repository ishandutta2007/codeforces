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

int n, m, d;
vector<int> lis[100100];
vector<int> ris[100100];
char str[5000100];
int vis[5000100];
int st[5000100];
int vt, tt;
void idfs(int here) {
    vis[here] = vt;
    for (int &thp : lis[here/d]) {
        int there = thp*d+(here%d+1)%d;
        if (vis[there]!=vt) idfs(there);
    }
}
void rdfs(int here) {
    vis[here] = vt;
    for (int &thp : ris[here/d]) {
        int there = thp*d+(here%d+d-1)%d;
        if (!vis[there]) continue;
        if (vis[there]!=vt) rdfs(there);
    }
    st[tt++] = here;
}
int cp;
int D[5000100];
int cnum[5000100];
int chk[100100];
int maxi, cnt;
vector<int> tmp;
void dfs(int here) {
    vis[here] = vt;
    if (str[here]=='1'&&chk[here/d]==0) {
        chk[here/d]=1;
        tmp.push_back(here/d);
        cnt++;
    }
    cnum[here] = cp;
    for (int &thp : lis[here/d]) {
        int there = thp*d+(here%d+1)%d;
        if (!vis[there]) continue;
        if (vis[there]!=vt) dfs(there);
        else if (cnum[there]!=cp) {
            maxi = max(maxi,D[cnum[there]]);
        }
    }
}

    char buf[60];
int main() {
    int i, j;

    scanf("%d%d%d",&n,&m,&d);
    for (i=0;i<m;i++) {
        int a, b;
        scanf("%d%d",&a,&b); --a; --b;
        lis[a].push_back(b);
        ris[b].push_back(a);
    }
    for (i=0;i<n;i++) {
        scanf("%s",buf);
        for (j=i*d;j<(i+1)*d;j++) str[j]=buf[j-i*d];
    }
    vt=1;
    idfs(0);
    vt=2;
    for (i=0;i<n*d;i++) {
        if (vis[i]==0||vis[i]==2) continue;
        rdfs(i);
    }
    vt = 3;
    int ans = 0;
    for (i=tt-1;~i;i--) {
        if (vis[st[i]]==vt) continue;
        maxi = cnt = 0;
        dfs(st[i]);
        while(!tmp.empty()) {
            chk[tmp.back()]=0;
            tmp.pop_back();
        }
        D[cp] = cnt+maxi;
        cp++;
    }
    printf("%d\n",D[cp-1]);

    return 0;
}