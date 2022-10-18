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

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin>>s;
    int n=s.size();
    vector<int> op,cl;
    for(int i=0;i<n;i++)
        if(s[i]=='(')
           op.push_back(i);
        else
            cl.push_back(i);
    reverse(cl.begin(),cl.end());
    int m=0;
    for(int i=0;i<min(op.size(),cl.size());i++)
        if(op[i]<cl[i])
            m++;
    if(!m)
        cout<<0,exit(0);
    cout<<1<<"\n"<<2*m<<"\n";
    for(int i=0;i<m;i++)
        cout<<op[i]+1<<" ";
    for(int i=m-1;i>=0;i--)
        cout<<cl[i]+1<<" ";
}