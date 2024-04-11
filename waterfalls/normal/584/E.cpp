#include <bits/stdc++.h>
using namespace std;

int n;
int id[2013];
int p[2013];
vector<pair<int,int> > moves;

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&p[i]);
    for (int i=1;i<=n;i++) {
        int x;
        scanf("%d",&x);
        id[x] = i;
    }
    for (int i=1;i<=n;i++) p[i] = id[p[i]];
    int ans = 0;
    for (int r=1;r<=n;r++) {
        int i = 0;
        for (int j=0;j<=n;j++) if (p[j]>j && (!i || p[j]>p[i])) i = j;
        if (!i) break;
        int where = i+1;
        while (p[i]>i) {
            if (p[where]<=i) {
                ans+=where-i;
                moves.push_back(make_pair(i,where));
                swap(p[i],p[where]);
                i = where;
            }
            where+=1;
        }
    }
    printf("%d\n%d\n",ans,moves.size());
    for (auto i: moves) printf("%d %d\n",i.first,i.second);

    return 0;
}