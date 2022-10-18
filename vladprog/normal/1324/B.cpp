#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=5010;

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
        bool yes=false;
        for(int i=1;i<=n;i++)
            for(int j=i+2;j<=n;j++)
                if(a[i]==a[j])
                    yes=true;
        cout<<(yes?"YES\n":"NO\n");
    }
}