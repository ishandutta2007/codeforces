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

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ans=0;
        while(n%6==0)
            n/=6,
            ans++;
        while(n%3==0)
            n/=3,
            ans+=2;
        cout<<(n==1?ans:-1)<<"\n";
    }
}