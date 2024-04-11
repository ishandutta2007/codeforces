#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int n;
map<int,int> best;
vector<int> has;
int l[300];
int c[300];

int gcd(int a, int b) {
    if (a>b) swap(a,b);
    if (a==0) return b;
    return gcd(b%a,a);
}

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&l[i]);
    for (int i=0;i<n;i++) scanf("%d",&c[i]);
    for (int i=0;i<n;i++) {
        int to = has.size();
        if (best.count(l[i])) best[l[i]] = min(best[l[i]],c[i]);
        else {
            best[l[i]] = c[i];
            has.push_back(l[i]);
        }
        for (int j=0;j<to;j++) {
            int next = gcd(has[j],l[i]);
            if (best.count(next)) best[next] = min(best[next],best[has[j]]+c[i]);
            else {
                best[next] = best[has[j]]+c[i];
                has.push_back(next);
            }
        }
    }
    if (best.count(1)) printf("%d\n",best[1]);
    else printf("-1\n");

    return 0;
}