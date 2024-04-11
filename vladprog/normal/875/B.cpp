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
    set<int> s;
    int l=n+1;
    cout<<1<<" ";
    for(int i=1;i<=n;i++)
    {
        int p;
        cin>>p;
        s.insert(p);
        while(s.count(l-1))
            l--;
        cout<<i-(n-l+1)+1<<" ";
    }
}