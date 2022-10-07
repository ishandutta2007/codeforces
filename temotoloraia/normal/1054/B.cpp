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
const int N = 1e5 + 5;

int n, nn;
int a[N];

int main()
{
    cin>>n;
    nn = 0;
    for (int i = 1; i <= n; i++){
        cin>>a[i];
        if (a[i] < nn)
            continue;
        if (a[i] > nn){
            cout<<i<<endl;
            return 0;
        }
        nn++;
    }
    cout<<-1<<endl;
    return 0;
}