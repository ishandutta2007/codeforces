#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first

const int M=1e5+100,D=1e5;

int ans[M];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        ans[i]=-1;
    set<int,greater<int>> s{0};
    for(int step=1;step<=n;step++)
    {
//        cout<<"====\n";
        int t,x,y;
        cin>>t>>x>>y;
        for(auto it=s.begin();it!=s.end();it++)
        {
            int k=*it;
//            cout<<k<<" ";
            for(int _=1;_<=y;_++)
            {
                if(t==1)
                    k=(k*D+x+D-1)/D;
                else
                    k=(k*x+D-1)/D;
//                cout<<k<<" ";
                if(k>m||s.count(k))
                    break;
                s.insert(k);
                ans[k]=step;
            }
//            cout<<"\n";
        }
//        cout<<"====\n";
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<" ";
}