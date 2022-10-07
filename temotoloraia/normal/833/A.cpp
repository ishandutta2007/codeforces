#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long int
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int N = 105;
int n, a, b;
map < int, bool > M;
int main()
{
    cin>>n;
    for (int i = 1; i <= 1000; i++)
        M[i * i * i] = 1;
    while (n--){
        scanf("%d%d",&a,&b);
        int c = __gcd (a, b);
        int d = c;
        a /= c;
        b /= c;
        a *= b;
        if (d % a != 0){
            printf("No\n");
            continue;
        }
        d /= a;
        if (M[d])
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}