#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000001];
int n;
const long long MAX = 3000000000000000000ll;
long long solve(long long p) {
    long long C = 0; // count this range
    long long M = (p+1)/2; // median
    long long ans = 0;
    for(int i=0; i<n; i++) {
        long long X = a[i] % p;
        if(C+X >= p) {
            if(C >= M) {
                ans += (p - C)*i;
            }
            else {
                ans += C * i;
            }
            X = (C+X) % p;
            C = 0;
        }
        if(C >= M) {
            ans += X * i;
        }
        else if(C+X >= M) {
            ans += C * i;
            ans -= (p-C-X) * i;
        }
        else {
            ans -= X*i;
        }
        C += X;
    }
    //printf("%lld %lld\n", p, ans);
    return ans;
}
int main() {
    long long S = 0;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", a+i);
        S += a[i];
    }
    long long ans = MAX;
    for(long long p=2; p*p<=S; p++) {
        if(S%p == 0) {
            ans = min(ans, solve(p));
            while(S%p == 0) S /= p;
        }
    }
    if(S != 1) {
        ans = min(ans, solve(S));
    }
    if(ans == MAX) ans = -1;
    printf("%lld\n", ans);
    return 0;
}