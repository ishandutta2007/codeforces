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

    int b,g,n;
    cin>>b>>g>>n;
    int l=max(0ll,n-g),r=min(n,b);
    cout<<r-l+1;
}