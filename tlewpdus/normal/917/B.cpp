#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n, m;
vector<pii> lis[110];
int D[101][101][2][27];

int calc(int u, int v, int t, int c) {
    if (~D[u][v][t][c]) return D[u][v][t][c];
    bool good = false;
    if (t) {
        for (pii &e : lis[v]) {
            if (e.second<c) continue;
            if (calc(u,e.first,1-t,e.second)) good = true;
        }
    }
    else {
        for (pii &e : lis[u]) {
            if (e.second<c) continue;
            if (!calc(e.first,v,1-t,e.second)) good = true;
        }
    }
    return D[u][v][t][c] = (good==t);
}

int main() {
    int i, j;

    memset(D,-1,sizeof(D));
    scanf("%d%d",&n,&m);
    for (i=0;i<m;i++) {
        int a, b; char c;
        scanf("%d%d %c",&a,&b,&c); a--; b--;
        lis[a].push_back(pii(b,c-'a'));
    }
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++){
            printf("%c",calc(i,j,0,0)?'B':'A');
        }
        printf("\n");
    }

    return 0;
}