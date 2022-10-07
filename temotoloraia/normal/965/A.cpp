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
ll k, n, s, p;
int main()
{
    cin>>k>>n>>s>>p;
    cout<<(k * ((n + s - 1) / s) + p - 1) / p<<endl;
    return 0;
}