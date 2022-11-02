#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

#define MP make_pair
#define A first
#define B second

int n,q;
const int SQRT = 700;
const int BLOCKS = 500513/SQRT;
int a[500013];
int add[BLOCKS];
int L[BLOCKS];
int R[BLOCKS];
set<pair<int,int> > has[BLOCKS];
const int INF = 1000000001;

int main() {
    scanf("%d%d",&n,&q);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i=0;i<n;i++) {
        int which = i/SQRT;
        has[which].insert(MP(a[i],i));
    }
    for (int which=0;which*SQRT<n;which++) {
        L[which] = which*SQRT;
        R[which] = (which+1)*SQRT-1;
    }
    for (int Q=0;Q<q;Q++) {
        int type;
        scanf("%d",&type);
        if (type==1) {
            int l,r,x;
            scanf("%d%d%d",&l,&r,&x);
            l-=1; r-=1;
            for (int which=0;which*SQRT<n;which++) {
                if (r<L[which] || R[which]<l) continue;
                if (l<=L[which] && R[which]<=r) {
                    add[which]+=x;
                    if (add[which]>=INF) add[which] = INF;
                } else {
                    int from = l<L[which] ? L[which] : l;
                    int to = l<L[which] ? r : R[which];
                    if (L[which]<=l && r<=R[which]) from = l, to = r;
                    for (int i=from;i<=to;i++) {
                        has[which].erase(MP(a[i],i));
                        a[i]+=x;
                        if (a[i]>=INF) a[i] = INF;
                        has[which].insert(MP(a[i],i));
                    }
                }
            }
        } else {
            int y;
            scanf("%d",&y);
            int from = n;
            int to = -1;
            for (int which=0;which*SQRT<n;which++) {
                int need = y-add[which];
                if (need<0) continue;
                set<pair<int,int> >::iterator it = has[which].lower_bound(MP(need,0));
                if (it==has[which].end() || it->first!=need) continue;
                else {
                    from = min(from,it->second);
                    it = --has[which].upper_bound(MP(need,n));
                    to = max(to,it->second);
                }

            }
            if (to==-1) printf("-1\n");
            else printf("%d\n",to-from);
        }
    }

    return 0;
}