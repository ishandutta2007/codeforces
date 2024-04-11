#include <cstdio>
#include <algorithm>

using namespace std;

int n;
pair<int,int> x[100];

int main() {
    scanf("%d",&n);
    int nl = 0;
    for (int i=0;i<n;i++) scanf("%d%d",&x[i].first,&x[i].second);
    sort(x,x+n);
    int l = 0;
    for (int i=0;i<n;i++) if (x[i].first<0) l+=1;
    int r = n-l;
    int ans = 0;
    if (l>r+1) {
        for (int i=n-1;i>=n-2*r-1;i--) ans+=x[i].second;
    } else if (r>l+1) {
        for (int i=0;i<2*l+1;i++) ans+=x[i].second;
    } else {
        for (int i=0;i<n;i++) ans+=x[i].second;
    }
    printf("%d\n",ans);

    return 0;
}