#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,l,r;
    cin>>n>>l>>r;
    int mn=n-l;
    for(int i=0;i<l;i++)
        mn+=1ll<<i;
    int mx=(n-r)*(1ll<<(r-1));
    for(int i=0;i<r;i++)
        mx+=1ll<<i;
    cout<<mn<<" "<<mx;
}