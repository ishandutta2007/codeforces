#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int a[N];

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
        for(int i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+n+1,greater<int>());
        int alice=0,bob=0;
        for(int i=1;i<=n;i++)
            if(i%2==1&&a[i]%2==0)
                alice+=a[i];
            else if(i%2==0&&a[i]%2==1)
                bob+=a[i];
        if(alice>bob)
            cout<<"Alice\n";
        else if(bob>alice)
            cout<<"Bob\n";
        else
            cout<<"Tie\n";
    }
}