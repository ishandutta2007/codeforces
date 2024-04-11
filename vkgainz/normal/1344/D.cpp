#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define f first
#define s second
const int MX = 2e5+5;
long long get(long long y, long long a) {
    if(a-1<y) //edge case
        return -1LL;
    if(-3*1LL*a*1LL*a+4*1LL*a-1>=y)
        return a-1;
    return (long long) (ceil(sqrt((4*1.0/3*a-4*1.0/3*y-1.0/3))-1.0/2)*1.0/2);
}
int a[100001];
long long cost(int i, int x) {
    //to jump to x+1...don't need to jump if x =a
    return -3*1LL*x*1LL*x-3*1LL*x-1+a[i];
}
struct cmp {
    bool operator() (const pair<int, int> &i, const pair<int, int> &j) const {
        long long costA = cost(i.f, i.s);
        long long costB = cost(j.f, j.s);
        if(costA!=costB)
            return costA>costB;
        return i.f<j.f;
    }
};
int main() {
    int n;
    long long k; cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> a[i];
    long long lo = -4e18, hi = 4e18;
    long long mid = 0LL;
    long long sum = 0LL;
    for(int i=0;i<100;i++) { //check this
        //[lo, hi)
        mid = (lo+hi)/2;
        sum = 0LL;
        for(int i=0;i<n;i++)
            sum+=get(mid, a[i])+1;
        //cout << mid << " " << sum << "\n";
        if(sum==k) 
            break;
        if(sum>k) {
            lo = mid+1;
        }
        else {
            hi = mid;
        }
    }
    k-=sum;
    //cout << k << " " << mid << "\n";
    long long b[n];
    for(int i=0;i<n;i++) {
        b[i] = get(mid, a[i])+1;
    }
    set<pair<int, int>, cmp> in;
    for(int i=0;i<n;i++) {
        if(b[i]<a[i])
            in.insert({i, b[i]});
    }
    while(k>0) {
        --k;
        auto it = in.begin();
        pair<int, int> curr = (*it);
        ++b[curr.f];
        in.erase(it++);
        if(b[curr.f]<a[curr.f])
            in.insert({curr.f, b[curr.f]});
    }
    for(int i=0;i<n;i++) {
        cout << b[i] << " ";
    }
}