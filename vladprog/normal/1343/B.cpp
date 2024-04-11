#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int M=1e9;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n%4)
        {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        int k=n/4;
        for(int i=0;i<k;i++)
            cout<<2*i+2<<" ";
        for(int i=0;i<k;i++)
            cout<<M-2*i<<" ";
        for(int i=0;i<k;i++)
            cout<<2*i+3<<" ";
        for(int i=0;i<k;i++)
            cout<<M-2*i-1<<" ";
        cout<<"\n";
    }
}