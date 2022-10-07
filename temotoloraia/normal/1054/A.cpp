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
//#define temo

using namespace std;
const int N = 2e5 + 5;

int main()
{
    int x, y, z, t1, t2, t3;
    cin>>x>>y>>z>>t1>>t2>>t3;
    int T1 = abs (x - y) * t1;
    int T2 = 3 * t3 + t2 * (abs (x - z) + abs (x - y));
    if (T1 >= T2)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}