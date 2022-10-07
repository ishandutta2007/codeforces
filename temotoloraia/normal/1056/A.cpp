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

const ll N = 1507;
int n;
int a[N];
int main()
{
    cin>>n;
    for (int i = 1; i <= n; i++){
        int r;
        cin>>r;
        while (r--){
            int x;
            cin>>x;
            a[x]++;
        }
    }
    for (int i = 1; i <= 100; i++)
        if (a[i] == n)
            cout<<i<<" ";
    return 0;
}