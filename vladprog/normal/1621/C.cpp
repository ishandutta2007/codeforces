#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e4+100;

int p[N];

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
            p[i]=0;
        for(int i=1;i<=n;i++)
            if(!p[i])
            {
                cout<<"? "<<i<<endl;
                int a;
                cin>>a;
                while(!p[a])
                {
                    cout<<"? "<<i<<endl;
                    int b;
                    cin>>b;
                    p[a]=b;
                    a=b;
                }
            }
        cout<<"! ";
        for(int i=1;i<=n;i++)
            cout<<p[i]<<" ";
        cout<<endl;
    }
}