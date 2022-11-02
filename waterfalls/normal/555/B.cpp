#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int n,m;
pair<pair<long long,long long>,int> p[200013];
multiset<pair<long long,int> > len;
int cur[200013];

int main() {
    scanf("%d%d",&n,&m);
    long long prevl,prevr;
    scanf("%I64d%I64d",&prevl,&prevr);
    for (int i=1;i<n;i++) {
        long long l,r;
        scanf("%I64d%I64d",&l,&r);
        p[i-1] = make_pair(make_pair(r-prevl,l-prevr),i-1);
        prevl = l, prevr = r;
    }
    sort(p,p+n-1);
    for (int i=0;i<m;i++) {
        long long ll;
        scanf("%I64d",&ll);
        len.insert(make_pair(ll,i+1));
    }
    int ok = 1;
    for (int i=0;i<n-1;i++) {
        if (len.size()==0) {
            ok = 0;
            break;
        }
        if (len.lower_bound(make_pair(p[i].first.second,0))==len.end()) {
            ok = 0;
            break;
        }
        pair<long long,int> x = *len.lower_bound(make_pair(p[i].first.second,0));
        if (x.first>p[i].first.first) {
            ok = 0;
            break;
        }
        cur[p[i].second] = x.second;
        len.erase(len.find(x));
    }
    if (ok) {
        printf("Yes\n");
        for (int i=0;i<n-1;i++) printf("%d ",cur[i]);
        printf("\n");
    } else printf("No\n");

    return 0;
}