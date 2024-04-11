#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define MP make_pair
#define A first
#define B second

int n;
int X[300013];

vector<int> changed;
int has_[900013];
int& has(int i) {
    changed.push_back(i+300000);
    return has_[i+300000];
}
queue<pair<int,int> > smalls;

long long go(vector<int> l, vector<int> r) {
    while (smalls.size()>0) smalls.pop();
    vector<int> minr(r);
    for (int i=1;i<minr.size();i++) minr[i] = min(minr[i],minr[i-1]);
    vector<int> maxr(r);
    for (int i=1;i<maxr.size();i++) maxr[i] = max(maxr[i],maxr[i-1]);
    int highl = 0;
    int lowl = 1e9;
    int lowr = 1e9;
    int onr = -1;
    long long res = 0;
    for (int i=0;i<l.size();i++) {
        highl = max(highl,l[i]);
        while (onr+1<r.size() && r[onr+1]<highl) {
            onr+=1;
            lowr = min(lowr,r[onr]);
            smalls.push(MP(lowr,onr+lowr+1));
            has(onr+lowr+1)+=1;
        }
        lowl = min(lowl,l[i]);
        while (smalls.size()>0 && smalls.front().A>lowl) {
            has(smalls.front().B)-=1;
            smalls.pop();
        }
        res+=has(highl-i);
        if (highl-lowl-i-1>=0 && highl-lowl-i-1<r.size() &&
            lowl<minr[highl-lowl-i-1] && highl>maxr[highl-lowl-i-1]) res+=1;
    }
    for (int i: changed) has_[i] = 0;
    changed.clear();
    return res;
}

long long solve(int l, int r) {
    if (l>r) return 0;
    if (l==r) return 1;
    int mid = (l+r)/2;
    long long res = solve(l,mid)+solve(mid+1,r);
    vector<int> one(X+l,X+mid+1);
    reverse(one.begin(),one.end());
    vector<int> two(X+mid+1,X+r+1);
    res+=go(one,two)+go(two,one);
    return res;
}

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        X[a] = b;
    }
    printf("%lld\n",solve(1,n));

    return 0;
}