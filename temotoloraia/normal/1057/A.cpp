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

int n, a[N];
vector < int > v;

int main()
{
    cin>>n;
    for (int i = 2; i <= n; i++)
        cin>>a[i];
    int x = n;
    while (x){
        v.pb (x);
        x = a[x];
    }
    for (int i = v.size() - 1; i >= 0; i--)
        cout<<v[i]<<" ";
    return 0;
}