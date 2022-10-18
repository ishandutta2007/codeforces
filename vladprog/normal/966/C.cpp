#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<int> v[65];
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        v[64-__builtin_clzll(x)].push_back(x);
    }
    vector<int> b;
    int cur=0;
    while(n--)
    {
        bool ok=false;
        for(int i=0;i<65&&!ok;i++)
            if(!v[i].empty()&&(cur^v[i].back())>cur)
//                cout<<v[i].back()<<"\n",
                b.push_back(v[i].back()),
                cur^=v[i].back(),
                v[i].pop_back(),
                ok=true;
//            else
//                cout<<(v[i].empty()?0:v[i].back())<<" ";
        if(!ok)
            cout<<"No",exit(0);
    }
    cout<<"Yes\n";
    for(int x:b)
        cout<<x<<" ";
}