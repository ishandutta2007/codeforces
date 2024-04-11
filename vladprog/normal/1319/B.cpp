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

    int n;
    cin>>n;
    map<int,int> ans;
    int best=0;
    for(int i=1;i<=n;i++)
    {
        int b;
        cin>>b;
        best=max(best,ans[b-i]+=b);
    }
    cout<<best;
}