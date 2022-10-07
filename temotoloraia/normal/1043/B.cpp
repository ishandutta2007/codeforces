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
const int N = 3005;
int n, a[N];
int ans;
vector < int > v;
int main()
{
    cin>>n;
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    for (int k = 1; k <= n; k++){
        bool ok = 1;
        for (int i = 0; i + k + 1 <= n; i++)
            if (a[i + 1] - a[i] != a[i + k + 1] - a[i + k])
                ok = 0;
        if (ok)
            v.pb (k);
    }
    cout<<v.size()<<endl;
    for (int i = 0; i < v.size(); i++)
        cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}