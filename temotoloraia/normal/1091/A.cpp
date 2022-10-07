#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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

const int N = 1e5 + 5;

int a, b, c;

int main()
{
    cin>>a>>b>>c;
    int x = min (a, min (b - 1, c - 2));
    cout<<x * 3 + 3<<endl;
    return 0;
}