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

const int N=110;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int b,d;
    string a,c;
    cin>>b>>d>>a>>c;
    int n=a.size(),m=c.size();
    vector<int> v{0};
    map<int,int> s;
    s[0]=0;
    int be,en;
    for(int i=0;;)
    {
        for(int j=0;j<m;i++)
            if(a[i%n]==c[j])
                j++;
            else if(i>N*N*N)
                cout<<0,exit(0);
        if(s.count(i%n))
        {
            be=s[i%n];
            v.push_back(i);
            en=v.size()-1;
            break;
        }
        else
            s[i%n]=v.size(),
            v.push_back(i);
    }
//    for(int x:v)
//        cout<<x<<" ";
//    cout<<"\n";
//    cout<<be<<" "<<en<<"\n";
    int have=n*b;
    if(v.back()>have)
    {
        int ans=0;
        for(int i=0;i<v.size();i++)
            if(v[i]<have)
                ans=i;
        cout<<ans/d;
        exit(0);
    }
    int ans=be;
    have-=v[be];
    int cyc=v[en]-v[be];
    ans+=have/cyc*(en-be);
    have%=cyc;
    for(int i=be+1;i<=en;i++)
        if(v[i]-v[be]<=have)
            ans++;
    cout<<ans/d;
}