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
int n, m;
int t;
int a[N];
int main()
{
    cin>>n;
    m = sqrt(n);
    if (n > m*(m+1))
        m++;
    for (int i = n-m+1; i+m-1 > 0; i -= m)
        for (int j = i; j < i + m; j++)
            if (j > 0)
                a[j] = ++t;
    for (int i = 1; i <= n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}