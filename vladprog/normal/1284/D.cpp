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

int rnd()
{
    return abs(rand()*(RAND_MAX+1)+rand());
}

int rnd(int x)
{
    return rnd()%x;
}

int rnd(int l,int r)
{
    return l+rnd()%(r-l+1);
}

const int N=1e5+100;

int h[N];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    srand(time(0));
    int mod=rnd(9e8,2e9);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        h[i]=rnd(mod);
    vector<pair<int,int>> a,b;
    for(int i=1;i<=n;i++)
    {
        int sa,sb,ea,eb;
        cin>>sa>>ea>>sb>>eb;
        a.emplace_back(sa,-i);
        a.emplace_back(ea,i);
        b.emplace_back(sb,-i);
        b.emplace_back(eb,i);
    }
    sort(a.begin(),a.end());
    int suma=0,cur=0;
    for(auto p:a)
    {
        int t=p.first,i=p.second;
        if(i<0)
        {
//            cout<<"+ "<<-i<<" ("<<t<<")\n";
            suma=(suma+cur*h[-i])%mod;
            cur=(cur+h[-i])%mod;
        }
        else
        {
//            cout<<"- "<<i<<" ("<<t<<")\n";
            cur=(cur-h[i]+mod)%mod;
        }
    }
//    cout<<"====\n";
    sort(b.begin(),b.end());
    int sumb=0;cur=0;
    for(auto p:b)
    {
        int t=p.first,i=p.second;
        if(i<0)
        {
//            cout<<"+ "<<-i<<" ("<<t<<")\n";
            sumb=(sumb+cur*h[-i])%mod;
            cur=(cur+h[-i])%mod;
        }
        else
        {
//            cout<<"- "<<i<<" ("<<t<<")\n";
            cur=(cur-h[i]+mod)%mod;
        }
    }
//    cout<<suma<<" "<<sumb<<"\n";
    cout<<(suma==sumb?"YES":"NO");
}