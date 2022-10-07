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
int n;
string a, b;
ll x, y, z, t;
int main()
{
    cin>>n>>a>>b;
    for (int i = 0; i < n; i++)
        if (b[i] == '0'){
            if (a[i] == '0')
                x++;
            else
                y++;
        }
        else {
            if (a[i] == '0')
                z++;
            else
                t++;
        }
    cout<<x*y + x*t + y*z<<endl;
    return 0;
}