#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int n,q;
set<int> has;
int p[200013];

int find(int x) { return p[x]==x ? x : p[x]=find(p[x]); }
void merge(int a, int b) { p[find(a)] = find(b); }

int main() {
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++) p[i] = i, has.insert(i);
    has.insert(n+1);
    for (int Q=0;Q<q;Q++) {
        int type,x,y;
        scanf("%d%d%d",&type,&x,&y);
        if (type==1) {
            merge(x,y);
        } else if (type==2) {
            while (true) {
                int z = *has.lower_bound(x);
                if (z>y) break;
                has.erase(z);
                merge(x,z);
            }
            has.insert(x);
        } else {
            printf("%s\n",find(x)==find(y) ? "YES" : "NO");
        }
    }

    return 0;
}