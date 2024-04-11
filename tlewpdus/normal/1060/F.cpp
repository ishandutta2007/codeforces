#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

int n;
ld D[52][52][52];
ll comb[52][52];
vector<int> lis[52];
int sz[52];

void init() {
    int i, j;
    for (i=0;i<=51;i++) {
        for (j=0;j<=i;j++) {
            if (j==0||j==i) comb[i][j] = 1;
            else comb[i][j] = comb[i-1][j-1]+comb[i-1][j];
        }
    }
}

ld prob(int a, int b, int c, int d) {
    if (a<b||c<d) return 0;
    return (ld)comb[a][b]*comb[c][d]/comb[a+c][b+d];
}

ld tmp[52][52];
void dfs(int here, int p) {
    sz[here] = 1;
    for (int &there :lis[here]) {
        if (there==p) continue;
        dfs(there,here);
        sz[here] += sz[there];
    }
    if (sz[here]==1) {
        D[here][0][0] = 1;
        D[here][1][1] = 1;
        return;
    }
    int son = lis[here].size()-(p!=-1);
    int a, b, cursz = 0, c, d;
    D[here][0][0] = 1;
    for (int &there : lis[here]){
        if (there==p) continue;
        for (a=0;a<=cursz+sz[there];a++) {
            for (b=0;b<=cursz+sz[there];b++) {
                tmp[a][b] = 0.0;
                for (c=0;c<=a;c++) {
                    for (d=0;d<=b;d++) {
                        tmp[a][b]+=D[here][c][d]*D[there][a-c][b-d]*prob(cursz,c,sz[there],a-c);
                    }
                }
            }
        }
        for (a=0;a<=cursz+sz[there];a++) {
            for (b=0;b<=cursz+sz[there];b++) {
                D[here][a][b] = tmp[a][b];
            }
        }
        cursz+=sz[there];
    }
    if (p<0) return;
    for (a=1;a<=sz[here];a++){
        for (b=1;b<=sz[here];b++) {
            tmp[a][b] = 0;
            for (c=1;c<=a;c++) tmp[a][b]+=D[here][c-1][b-1]/sz[here];
            tmp[a][b] += (1-1.0*a/sz[here])*D[here][a][b];
        }
    }
    for (a=1;a<=sz[here];a++) {for (b=1;b<=sz[here];b++) D[here][a][b] = tmp[a][b];}
}

void cl() {
    int i, j, k;
    for (i=0;i<n;i++){
        for (j=0;j<=n;j++)for(k=0;k<=n;k++)D[i][j][k] = 0;
    }
}

int main() {
    init();
    int i;
    scanf("%d",&n);
    for (i=0;i<n-1;i++) {
        int a, b;
        scanf("%d%d",&a,&b); --a; --b;
        lis[a].push_back(b);
        lis[b].push_back(a);
    }
    for (i=0;i<n;i++) {
        cl();
        dfs(i,-1);
        ld p = 1.0, ans = 0;
        for (int t=0;t<=n-1;t++){
            ans += p*D[i][n-1][t];
            p*=0.5;
        }
        printf("%.12Lf\n",ans);
    }

    return 0;
}