#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Upgrade { int index, value, type, to; long long top, bot; };
bool comp(Upgrade a, Upgrade b) { return a.top*b.bot>b.top*a.bot; }
bool comp2(Upgrade a, Upgrade b) { return a.value>b.value; }

int k,n,m;
int a[100013];
vector<Upgrade> upgrades[100013][3];
vector<Upgrade> allSort;

int main() {
    scanf("%d%d%d",&k,&n,&m);
    for (int i=0;i<k;i++) scanf("%d",&a[i]);
    for (int i=0;i<n;i++) {
        int t,w,b;
        scanf("%d%d%d",&t,&w,&b);
        Upgrade next;
        next.index = i+1; next.value = b; next.type = t-1; next.to = w-1;
        upgrades[w-1][t-1].push_back(next);
    }
    for (int i=0;i<k;i++) {
        sort(upgrades[i][0].begin(),upgrades[i][0].end(),comp2);
        if (upgrades[i][0].size()>0 && upgrades[i][0][0].value>a[i]) {
            upgrades[i][0][0].value-=a[i];
            upgrades[i][1].push_back(upgrades[i][0][0]);
        }
        sort(upgrades[i][1].begin(),upgrades[i][1].end(),comp2);
        sort(upgrades[i][2].begin(),upgrades[i][2].end(),comp2);
    }
    for (int i=0;i<k;i++) {
        long long cur = a[i];
        for (int j=0;j<upgrades[i][1].size();j++) {
            upgrades[i][1][j].top = upgrades[i][1][j].value;
            upgrades[i][1][j].bot = cur;
            allSort.push_back(upgrades[i][1][j]);
            cur+=upgrades[i][1][j].value;
        }
        for (int j=0;j<upgrades[i][2].size();j++) {
            upgrades[i][2][j].top = upgrades[i][2][j].value-1;
            upgrades[i][2][j].bot = 1;
            allSort.push_back(upgrades[i][2][j]);
        }
    }
    sort(allSort.begin(),allSort.end(),comp);
    printf("%d\n",min(m,(int) allSort.size()));
    for (int i=0;i<k;i++) for (int j=0;j<3;j++) upgrades[i][j].clear();
    for (int i=0;i<min(m,(int) allSort.size());i++) upgrades[allSort[i].to][allSort[i].type].push_back(allSort[i]);
    for (int i=0;i<k;i++) {
        for (int j=0;j<upgrades[i][0].size();j++) printf("%d ",upgrades[i][0][j].index);
        for (int j=0;j<upgrades[i][1].size();j++) printf("%d ",upgrades[i][1][j].index);
        for (int j=0;j<upgrades[i][2].size();j++) printf("%d ",upgrades[i][2][j].index);
    }
    printf("\n");

    return 0;
}