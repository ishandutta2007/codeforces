#include <cstdio>
#include <algorithm>

using namespace std;

int n;
pair<int,int> pts[200013];
int s[200013];

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d%d",&pts[i].first,&pts[i].second);
    for (int i=0;i<n;i++) pts[i].first+=pts[i].second;
    sort(pts,pts+n);
    int ans = 0;
    for (int i=0;i<n;i++) {
        s[i] = 1;
        int where = lower_bound(pts,pts+i+1,make_pair(pts[i].first-2*pts[i].second,2147483647))-pts-1;
        if (where>=0 && where!=i) s[i] = 1+s[where];
        if (i) s[i] = max(s[i],s[i-1]);
        ans = max(ans,s[i]);
    }
    printf("%d\n",ans);

    return 0;
}