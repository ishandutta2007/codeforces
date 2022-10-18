#pragma GCC optimize("O3")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

#define mp make_pair
#define all(c) (c).begin() , (c).end()
#define sz(c) ((long long)((c).size()))
#define phb push_back
#define ppb pop_back
#define phf push_front
#define ppf pop_front

using namespace __gnu_pbds;
using namespace std;

#define int ll

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template
<
    class key,
    class val=null_type,
    class comp=less<key>
>
using ord_set=tree
<
    key,
    val,
    comp,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

bool read()
{
    char ch;
    cin>>ch;
    return ch-'0';
}

const int N=2010;

bool a[N][N],b[N];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            a[i][j]=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            a[i][j]^=read();
    int one=0;
    for(int i=1;i<=n;i++)
        if(b[i]=read())
            one=i;
    if(!one)
    {
        bool ok=true;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(a[i][j])
                    ok=false;
        if(ok)
            cout<<0;
        else
            cout<<-1;
    }
    for(int row=0;row<2;row++)
    {
        int col=a[one][one]^(row?b[one]:0);
        bool ok=true;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(a[i][j]^(a[i][one]^(col?b[i]:0)?b[j]:0)^(a[one][j]^(row?b[j]:0)?b[i]:0))
                    ok=false;
        if(ok)
        {
            vector<int> rows,cols;
            for(int i=1;i<=n;i++)
                if(a[i][one]^(col?b[i]:0))
                    rows.push_back(i);
            for(int j=1;j<=n;j++)
                if(a[one][j]^(row?b[j]:0))
                    cols.push_back(j);
            cout<<rows.size()+cols.size()<<"\n";
            for(int r:rows)
                cout<<"row "<<r-1<<"\n";
            for(int c:cols)
                cout<<"col "<<c-1<<"\n";
            exit(0);
        }
    }
    cout<<-1;
}