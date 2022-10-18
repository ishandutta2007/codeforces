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
        int a=0,b=0;
        for(int i=1;i<=n;i++)
            if(i<=(n-2)/2||i==n)
                a+=1<<i;
            else
                b+=1<<i;
        cout<<abs(a-b)<<"\n";
    }
}