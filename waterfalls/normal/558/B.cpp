#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int low[1000013];
int high[1000013];
int num[1000013];

int main() {
    for (int i=0;i<1000013;i++) low[i] = 1e9;
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        low[a] = min(low[a],i);
        high[a] = max(high[a],i);
        num[a]+=1;
    }
    int maxn = 0;
    for (int i=0;i<1000013;i++) maxn = max(maxn,num[i]);
    int ans = n+1;
    pair<int,int> which;
    for (int i=0;i<1000013;i++) if (num[i]==maxn) {
        if (high[i]-low[i]+1<ans) {
            ans = min(ans,high[i]-low[i]+1);
            which = make_pair(low[i],high[i]);
        }
    }
    printf("%d %d\n",which.first+1,which.second+1);

    return 0;
}