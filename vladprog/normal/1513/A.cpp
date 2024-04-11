#include <bits/stdc++.h>

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

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        if(k<=(n-1)/2)
        {
            cout<<1<<" ";
            int cur=2;
            while(k--)
                cout<<cur+1<<" "<<cur<<" ",
                cur+=2;
            while(cur<=n)
                cout<<cur<<" ",
                cur++;
            cout<<"\n";
        }
        else
            cout<<"-1\n";
    }
}