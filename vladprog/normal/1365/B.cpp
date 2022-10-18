#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=510;

int a[N],b[N];

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
        for(int i=1;i<=n;i++)
            cin>>b[i];
        if(is_sorted(a+1,a+n+1))
            cout<<"Yes\n";
        else
        {
            bool eq=true;
            for(int i=1;i<=n;i++)
                if(b[i]!=b[1])
                    eq=false;
            cout<<(eq?"No\n":"Yes\n");
        }
    }
}