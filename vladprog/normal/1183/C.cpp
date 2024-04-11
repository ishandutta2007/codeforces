#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>q;
    while(q--)
    {
        int k,n,a,b;
        cin>>k>>n>>a>>b;
        k--;
        if(k<n*b)
            cout<<-1<<"\n";
        else
        {
            k-=n*b;
            cout<<min(n,k/(a-b))<<"\n";
        }
    }
}