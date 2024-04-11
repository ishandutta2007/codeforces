#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

int sum(int x)
{
    int s=0;
    while(x)
        s+=x%10,
        x/=10;
    return s;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<int> ans;
    for(int x=max(1ll,n-81);x<=n-1;x++)
        if(x+sum(x)==n)
            ans.push_back(x);
    cout<<ans.size()<<"\n";
    for(int x:ans)
        cout<<x<<"\n";
}