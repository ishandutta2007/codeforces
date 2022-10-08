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
int ans;
bool P[1000005];
int n, m;
int main()
{
    cin>>n;
    for (int i = 2; i * i <= n; i++)
        if (P[i] == 0)
            for (int j = i * i; j <= n; j += i)
                P[j] = 1;
    for (int i = n; i >= 1; i--)
        if (n % i == 0 && P[i] == 0){
            m = n - i + 1;
            break;
        }
    ans = n;
    for (int i = 2; i <= n; i++)
        if (P[i] == 0){
            int x = (m - 1) / i * i;
            if (x == 0)x = i;
            if (x + i <= n)
                ans = min (ans, x + 1);
        }
    cout<<ans<<endl;
    return 0;
}