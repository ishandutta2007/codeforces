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
const ll N = 605;
int x, y;
int main()
{
    cin>>y>>x;
    if ((x + y) % 2 == 0 || x - 1 > y || (x == 1 && y > 0) || x == 0)
        cout<<"No\n";
    else
        cout<<"Yes\n";
    return 0;
}