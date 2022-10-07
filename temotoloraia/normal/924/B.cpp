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
int n, U;
int a[N];
double ans=-1;
int main()
{
    cin>>n>>U;
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    for (int i = 1; i <= n - 2; i++){
        int I = i + 1;
        for (int j = 19; j >= 0; j--){
            if (I + (1<<j) > n)
                continue;
            if (a[i] + U >= a[I + (1<<j)])
                I += (1<<j);
        }
        if (I == i + 1)
            continue;
        double x = a[I] - a[i + 1];
        double y = a[I] - a[i];
        double pas = x / y;
        if (ans < pas)
            ans = pas;
    }
    if (ans == -1){cout<<-1<<endl;return 0;}
    printf ("%.9f\n",ans);
    return 0;
}