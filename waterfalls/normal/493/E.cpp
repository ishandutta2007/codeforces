#include <cstdio>
#include <cmath>

using namespace std;

long long t,a,b;

int main() {
    scanf("%I64d%I64d%I64d",&t,&a,&b);
    if (t>a && a!=b || b<a) printf("0\n");
    else if (t==1) {
        if (a==b) {
            if (a==1) printf("inf\n");
            else printf("1\n");
        } else if (a==1) printf("0\n");
        else {
            long long temp = b;
            while (temp%a==0) temp/=a;
            if (temp==1) {
                printf("1\n");
                return 0;
            }
            int pt = 0;
            int cur = 1;
            while (b>0) {
                long long digit = b%a;
                pt+=cur*digit;
                b/=a;
                cur*=t;
            }
            if (pt==a) printf("1\n");
            else printf("0\n");
        }
    } else {
        if (a==b) {
            if (t==a) printf("2\n");
            else printf("1\n");
        } else {
            long long pt = 0;
            long long cur = 1;
            while (b>0) {
                long long digit = b%a;
                pt+=cur*digit;
                b/=a;
                cur*=t;
            }
            if (pt==a) printf("1\n");
            else printf("0\n");
        }
    }

    return 0;
}