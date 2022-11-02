#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,q;
int a[200013];
int low[500013];
vector<int> has[200013];
bool on[200013];
int num[500013];

int main() {
    for (int i=0;i<500013;i++) low[i] = i;
    for (int i=2;i<500013;i++) if (low[i]==i) {
        for (int j=i+i;j<500013;j+=i) low[j] = min(low[j],i);
    }
    scanf("%d%d",&n,&q);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i=0;i<n;i++) {
        while (a[i]>1) {
            int x = low[a[i]];
            has[i].push_back(x);
            while (a[i]%x==0) a[i]/=x;
        }
    }
    long long tot = 0;
    long long cur = 0;
    for (int Q=0;Q<q;Q++) {
        int x;
        scanf("%d",&x);
        x-=1;
        int diff = 0;
        for (int i=1;i<(1<<has[x].size());i++) {
            int v = 1;
            int bits = 0;
            for (int j=0;j<has[x].size();j++) if (i&(1<<j)) {
                bits+=1;
                v*=has[x][j];
            }
            if (on[x]) num[v]-=1;
            if (bits%2) diff+=num[v];
            else diff-=num[v];
            if (!on[x]) num[v]+=1;
        }
        if (on[x]) tot-=1, cur-=diff;
        else tot+=1, cur+=diff;
        on[x] = 1-on[x];
        printf("%lld\n",tot*(tot-1)/2-cur);
    }
    
    
    return 0;
}