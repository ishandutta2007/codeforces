#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define LL long long int
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n;
vector<int> v;
bool F[1005][15][15];
int mas[1005];
int ans[1005];
bool ok;
void go (int k, int p){
    if (k > n){
        ok = 1;
        for (int i = 1; i <= n; ++i)
            ans[i] = mas[i];
        return;
    }
    if (F[k][p][mas[k - 1]])
        return;
    F[k][p][mas[k - 1]] = 1;
    for (int i = 0; i < (int)v.size(); ++i){
        if (p - v[i] >= 0 || v[i] == mas[k - 1])
            continue;
        mas[k] = v[i];
        go (k + 1, v[i] - p);
        mas[k] = 0;
    }
}
int main()
{
    string s;
    cin>>s>>n;
    for (int i = 0; i < 10; ++i)
        if (s[i] == '1')
            v.pb(i + 1);
    go (1, 0);
    if (ok == 0){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    for (int i = 1; i <= n; ++i)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}