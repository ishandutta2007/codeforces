#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
long long gcd(long long x, long long y) {
    return y?gcd(y, x%y):x;
}
long long chk2(long long x) {
    long long f = 0, r = 3000000000ll;
    while(f<=r) {
        long long m = (f+r)/2, mm; mm = m*m;
        if(mm == x) return m;
        else if(mm < x) f = m+1;
        else r = m-1;
    }
    return -1;
}
long long chk3(long long x) {
    long long f = 0, r = 2000000ll;
    while(f<=r) {
        long long m = (f+r)/2, mm; mm = m*m*m;
        if(mm == x) return m;
        else if(mm < x) f = m+1;
        else r = m-1;
    }
    return -1;
}
long long chk4(long long x) {
    long long t = chk2(x);
    if(t == -1) return -1;
    return chk2(t);
}
long long a[501];
int chk[501], cnt[501];
vector<long long> P;
map<long long, int> m;
const int MOD = 998244353;
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%lld", a+i);
    sort(a, a+n);
    int c = 0;
    for(int i=0, j; i<n; i=j) {
        for(j=i; a[i] == a[j]; j++);
        cnt[c] = j-i;
        a[c++] = a[i];
    }
    n = c;
    long long t;
    for(int i=0; i<n; i++) {
        if((t=chk4(a[i])) != -1) P.push_back(t);
        else if((t=chk3(a[i])) != -1) P.push_back(t);
        else if((t=chk2(a[i])) != -1) P.push_back(t);
    }
    for(int i=0; i<n; i++) for(int j=i+1; j<n; j++) {
        t = gcd(a[i], a[j]);
        if(t != 1) P.push_back(t);
    }
    sort(P.begin(), P.end());
    P.erase(unique(P.begin(), P.end()), P.end());
    for(long long p: P) {
        for(int i=0; i<n; i++) {
            while(a[i]%p == 0) {
                m[p]+=cnt[i];
                a[i] /= p;
                chk[i] = 1;
            }
        }
    }
    long long ans = 1;
    for(auto pp: m) {
        ans = ans * (pp.second+1) % MOD;
    }
    for(int i=0; i<n; i++) {
        if(a[i] != 1) {
            if(chk[i] == 1) ans = ans * (cnt[i]+1) % MOD;
            else ans = ans * (cnt[i]+1) % MOD * (cnt[i]+1) % MOD;
        }
    }
    printf("%lld\n", ans);
    return 0;
}


/*3 = 3
4 = 2*2
5 = 5

p^2, p^3, p^4
p*q

*/