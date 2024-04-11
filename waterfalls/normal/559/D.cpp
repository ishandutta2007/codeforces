#include <cstdio>
#include <algorithm>
using namespace std;
#define ld long double
int n,X[100013],Y[100013];
ld t[90];
int gcd(int a, int b) { return a==0 ? b : gcd(b%a,a); }
int main() {
    t[0] = 1;
    for (int i=1;i<90;i++) t[i] = t[i-1]*2;
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d%d",&X[i],&Y[i]);
    ld A = 0;
    for (int l=1;l<=min(35,n-2);l++) {
        ld prob = n>88 ? 1/t[l+2] : (t[n-l-1]-1)/(t[min(n,89)]-1-1LL*n*(n+1)/2)/2;
        for (int i=0;i<n;i++) {
            int j = (i+l)%n;
            A+=prob*(1LL*Y[j]*X[i]-1LL*X[j]*Y[i]-abs(gcd(Y[j]-Y[i],X[j]-X[i])));
        }
    }
    printf("%.9f\n",(double) A+1);
}