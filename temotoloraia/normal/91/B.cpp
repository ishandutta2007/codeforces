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
int n;
int a[MAXN + 5];
int mas[MAXN + 5];
set < pair < int, int > > S;
set < pair < int, int > >::iterator I;
int main()
{
    cin>>n;
    for (int i = 1; i <= n; ++i)
        cin>>a[i];
    mas[n] = -1;
    S.insert ({a[n], n});
    for (int i = n - 1; i >= 1; --i){
        I = S.lower_bound ({a[i], 0});
        if (I == S.begin()){
            mas[i] = -1;
            S.insert ({a[i], i});
            continue;
        }
        --I;
        mas[i] = (*I).S - i - 1;
    }
    for (int i = 1; i <= n; ++i)
        cout<<mas[i]<<" ";
    return 0;
}