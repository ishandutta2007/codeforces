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

const int N=5010;

int a[N];

int calc(int l,int r,int val)
{
//    cout<<"DEBUG!\n";
//    int ans1=0;
//    for(int i=l;i<=r;i++)
//        for(int j=i+1;j<=r;j++)
//            if(i+j==val)
//                ans1++;

    int l1=max(l,val-r);
    int r1=min(r,val-l);
    int ans2=max(0ll,(r1-l1+1)/2);

//    if(ans1!=ans2)
//        cout<<l<<" "<<r<<" "<<val<<" -> "<<ans1<<" "<<ans2<<"\n",exit(0);

    return ans2;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        a[i]=n*i;
    int cnt=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(i+j<=n)
                cnt++;
//    cout<<cnt<<"\n";
    if(cnt<m)
        cout<<-1,exit(0);
    int pos=n,inf=1e9;
    while(cnt>m)
    {
        int cur=calc(1,pos-1,pos);
        cnt-=cur;
        int add=cur;
        if(cnt>=m)
            add=0,a[pos]=inf--;
        else
            while(cnt+add>m)
                a[pos]+=n,
                add=calc(1,pos-1,a[pos]/n);
//        cout<<cur<<" "<<add<<"\n";
        cnt-=add;
        pos--;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";

//    cout<<"\nDEBUG!\n";
//    set<int> s;
//    for(int i=1;i<=n;i++)
//        if(a[i]<0||a[i]>1000000000)
//            cout<<"INVALID\n",exit(0);
//        else if(s.count(a[i]))
//            cout<<"EQUAL\n",exit(0);
//        else
//            s.insert(a[i]);
//    int check=0;
//    for(int i=1;i<=n;i++)
//        for(int j=i+1;j<=n;j++)
//            if(s.count(a[i]+a[j]))
//                check++;
//    if(check!=m)
//        cout<<"WRONG "<<m<<" "<<check<<"\n";
}