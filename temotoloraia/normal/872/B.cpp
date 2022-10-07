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
const int MAXN = 100000;
int n, k;
int a[MAXN + 5];
int b[MAXN + 5];
int c[MAXN + 5];
int M;
int main()
{
    cin>>n>>k;
    for (int i = 1; i <= n; ++i){
        cin>>a[i];
        b[i] = a[i];
    }
    sort (b + 1, b + n + 1);
    if (k > 2){
        cout<<b[n]<<endl;
        return 0;
    }
    if (k == 1){
        cout<<b[1]<<endl;
        return 0;
    }
    cout<<max (a[1], a[n])<<endl;
    return 0;
}