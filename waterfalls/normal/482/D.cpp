#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Way { int ee,eo,oe,oo; };

int n;
int p[100013];
vector<int> child[100013];
Way ways[100013];

const int MOD = 1000000007;

void solve(int x) {
    if (child[x].size()==0) ways[x] = {0,1,1,0};
    else {
        Way prevl = {1,0,0,1};
        Way nextl;
        for (int i=0;i<child[x].size();i++) {
            nextl.ee = (prevl.ee+(long long) prevl.ee*ways[child[x][i]].ee+(long long) prevl.eo*ways[child[x][i]].oe)%MOD;
            nextl.eo = (prevl.eo+(long long) prevl.ee*ways[child[x][i]].eo+(long long) prevl.eo*ways[child[x][i]].oo)%MOD;
            nextl.oe = (prevl.oe+(long long) prevl.oe*ways[child[x][i]].ee+(long long) prevl.oo*ways[child[x][i]].oe)%MOD;
            nextl.oo = (prevl.oo+(long long) prevl.oe*ways[child[x][i]].eo+(long long) prevl.oo*ways[child[x][i]].oo)%MOD;
            swap(nextl,prevl);
        }
        Way prevr = {1,0,0,1};
        Way nextr;
        for (int i=0;i<child[x].size();i++) {
            nextr.ee = (prevr.ee+(long long) prevr.oe*ways[child[x][i]].eo+(long long) prevr.ee*ways[child[x][i]].ee)%MOD;
            nextr.eo = (prevr.eo+(long long) prevr.oo*ways[child[x][i]].eo+(long long) prevr.eo*ways[child[x][i]].ee)%MOD;
            nextr.oe = (prevr.oe+(long long) prevr.oe*ways[child[x][i]].oo+(long long) prevr.ee*ways[child[x][i]].oe)%MOD;
            nextr.oo = (prevr.oo+(long long) prevr.oo*ways[child[x][i]].oo+(long long) prevr.eo*ways[child[x][i]].oe)%MOD;
            swap(prevr,nextr);
        }
        ways[x].ee = (prevl.oe+prevr.oe)%MOD;
        ways[x].eo = (prevl.oo+prevr.oo)%MOD;
        ways[x].oe = (prevl.ee+prevr.ee)%MOD;
        ways[x].oo = (prevl.eo+prevr.eo)%MOD;
        Way prevb[2] = {{1,1,1,1},{0,0,0,0}};
        Way nextb[2] = {{0,0,0,0},{0,0,0,0}};
        for (int i=0;i<child[x].size();i++) {
            nextb[0].ee = (prevb[0].ee+(long long) prevb[0].ee*ways[child[x][i]].ee)%MOD;
            nextb[0].oo = (prevb[0].oo+(long long) prevb[0].oo*ways[child[x][i]].oo)%MOD;
            nextb[1].eo = (prevb[1].eo+(long long) prevb[0].oe*ways[child[x][i]].eo)%MOD;
            nextb[1].oe = (prevb[1].oe+(long long) prevb[0].eo*ways[child[x][i]].oe)%MOD;
            nextb[0].eo = (prevb[0].eo+(long long) prevb[1].oe*ways[child[x][i]].eo)%MOD;
            nextb[0].oe = (prevb[0].oe+(long long) prevb[1].eo*ways[child[x][i]].oe)%MOD;
            swap(prevb,nextb);
        }
        ways[x].ee = (ways[x].ee-prevb[1].oe+MOD)%MOD;
        ways[x].eo = (ways[x].eo-prevb[0].oo+MOD)%MOD;
        ways[x].oe = (ways[x].oe-prevb[0].ee+MOD)%MOD;
        ways[x].oo = (ways[x].oo-prevb[1].eo+MOD)%MOD;
    }
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<n;i++) scanf("%d",&p[i]), p[i]-=1, child[p[i]].push_back(i);
    for (int i=n-1;i>=0;i--) solve(i);
    printf("%d\n",(ways[0].ee+ways[0].eo)%MOD);

    return 0;
}