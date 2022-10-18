#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ord_set;

typedef long long ll;
#define int ll

typedef long double ld;
const ld one=1;

typedef pair<int,int> pii;
#define x first
#define y second

struct query
{
    int i,a,t,x;
    query(int i,int a,int t):i(i),a(a),t(t){}
};

const int N=1e5+100;

int ans[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    map<int,vector<query>> q;
    for(int i=1;i<=n;i++)
    {
        int a,t,x;
        cin>>a>>t>>x;
        q[x].push_back(query(i,a,t));
        ans[i]=-1;
    }
    for(auto xv:q)
    {
        int x=xv.first;
        auto v=xv.second;
        ord_set add,del;
        for(auto iat:v)
        {
            int i=iat.i,a=iat.a,t=iat.t;
            if(a==1)
                add.insert(t);
            else if(a==2)
                del.insert(t);
            else
                ans[i]=add.order_of_key(t)-del.order_of_key(t);
        }
    }
    for(int i=1;i<=n;i++)
        if(ans[i]!=-1)
            cout<<ans[i]<<"\n";
}