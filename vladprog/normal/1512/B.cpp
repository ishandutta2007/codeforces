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
        int n;
        cin>>n;
        set<int> x,y;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                char c;
                cin>>c;
                if(c=='*')
                    x.insert(i),
                    y.insert(j);
            }
        for(int i=1;i<=n;i++)
        {
            if(x.size()<2)
                x.insert(i);
            if(y.size()<2)
                y.insert(i);
        }
        for(int i=1;i<=n;i++,cout<<"\n")
            for(int j=1;j<=n;j++)
                if(x.count(i)&&y.count(j))
                    cout<<'*';
                else
                    cout<<'.';
    }
}