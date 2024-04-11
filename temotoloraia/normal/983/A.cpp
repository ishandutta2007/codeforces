#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int N = 100005;
int Q;
ll x;
ll p, q, b;
main()
{
    cin>>Q;
    while (Q--){
        scanf ("%lld %lld %lld", &p, &q, &b);
        if (p == 0){
            printf ("Finite\n");
            continue;
        }
        q /= __gcd (p,q);
        while (b <= 1e9)
            b *= b;
        while (1){
            x = __gcd (q, b);
            if (x == 1)break;
            q /= x;
            if (q == 1)
                break;
            if (x < b) {b=x;
            //while (b < 1e9)
            //b *= b;
                
            }
        }
        if (q == 1)
            printf ("Finite\n");
        else
            printf ("Infinite\n");
    }
    return 0;
}