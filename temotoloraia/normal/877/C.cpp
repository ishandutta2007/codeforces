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
const int MAXN = 5000;
int main()
{
    int n;
    cin>>n;
    cout<<n + n / 2<<endl;
    for (int i = 2; i <= n; i += 2)
        cout<<i<<" ";
    for (int i = 1; i <= n; i += 2)
        cout<<i<<" ";
    for (int i = 2; i <= n; i += 2)
        cout<<i<<" ";
    return 0;
}