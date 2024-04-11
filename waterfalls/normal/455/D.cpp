#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int n,q;
deque<int> blocks[320];
int has[320][100013];

const int SQRT = 316;

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        blocks[i/SQRT].push_back(a);
        has[i/SQRT][a]+=1;
    }
    scanf("%d",&q);
    int last = 0;
    for (int Q=0;Q<q;Q++) {
        int type;
        scanf("%d",&type);
        if (type==1) {
            int l,r;
            scanf("%d%d",&l,&r);
            l-=1; r-=1;
            l = (l+last)%n; r = (r+last)%n;
            if (l>r) swap(l,r);
            for (int i=0;i<320;i++) {
                if (l<SQRT*i && SQRT*i<=r) {
                    blocks[i].push_front(blocks[i-1][blocks[i-1].size()-1]);
                    has[i][blocks[i][0]]+=1;
                }
            }
            for (int i=0;i<320;i++) {
                if (l<=SQRT*(i+1)-1 && SQRT*(i+1)-1<r) {
                    has[i][blocks[i][blocks[i].size()-1]]-=1;
                    blocks[i].pop_back();
                }
            }
            int one = l/SQRT;
            int two = r/SQRT;
            int what = blocks[two][(r%SQRT)+(one!=two)];
            blocks[two].erase(blocks[two].begin()+(r%SQRT)+(one!=two));
            has[two][what]-=1;
            blocks[one].insert(blocks[one].begin()+(l%SQRT),what);
            has[one][what]+=1;
        } else {
            int l,r,k;
            scanf("%d%d%d",&l,&r,&k);
            l-=1; r-=1;
            l = (l+last)%n; r = (r+last)%n; k = (k+last-1)%n+1;
            if (l>r) swap(l,r);
            int ans = 0;
            for (int i=0;i<320;i++) {
                if (SQRT*(i+1)-1<l || r<SQRT*i) continue;
                if (l<=SQRT*i && SQRT*(i+1)-1<=r) ans+=has[i][k];
                else for (int j=max(l,SQRT*i);j<=min(r,SQRT*(i+1)-1);j++) if (blocks[i][j-SQRT*i]==k) ans+=1;
            }
            printf("%d\n",ans);
            last = ans;
        }
    }

    return 0;
}