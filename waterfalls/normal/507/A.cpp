#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,k;
int next;
vector<pair<int,int> > a;

int main() {
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++) {
        scanf("%d",&next);
        a.push_back(make_pair(next,i));
    }
    sort(a.begin(),a.end());
    int ans = -1;
    int cur = 0;
    for (int i=0;i<n;i++) {
        if (cur+a[i].first>k) {
            ans = i;
            break;
        }
        cur+=a[i].first;
    }
    if (ans==-1) ans = n;
    printf("%d\n",ans);
    for (int i=0;i<ans;i++) printf("%d ",a[i].second+1);

    return 0;
}