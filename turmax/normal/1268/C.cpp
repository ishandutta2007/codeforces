#include <bits/stdc++.h>

using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_tree;
struct setvector
{
    set <int> a;
    ordered_tree tree;
    void insert(int x)
    {
        tree.insert(x);
        a.insert(x);
    }
    void erase(int x)
    {
        tree.erase(x);
        a.erase(x);
    }
    ordered_tree::iterator find_by_order(int x)
    {
        return tree.find_by_order(x);
    }
    set <int>::iterator lower_bound(int x)
    {
        return a.lower_bound(x);
    }
    set <int>::iterator upper_bound(int x)
    {
        return a.upper_bound(x);
    }
    int order_of_key(int x)
    {
        return tree.order_of_key(x);
    }
    int count(int x)
    {
        return a.count(x);
    }
};
int32_t main()
{
    #define int long long
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <int> a(n);
    int pos[n];
    int o[n];
    int pr[n+1];
    pr[0]=0;
    setvector v1;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        a[i]--;
        pos[a[i]]=i;
    }
    int z;
    int h;
    for(int i=0;i<n;++i)
    {
        v1.insert(pos[i]);
        z=v1.order_of_key(pos[i]);
        h=i-z;
        pr[i+1]=pr[i]+h;
    }
    /*for(int i=0;i<n;++i)
    {
        cout<<pr[i+1]<<" ";
    }*/
    //cout<<endl;
    int posans[n];
    setvector v;
    v.insert(pos[0]);
    int ans=0;
    int mid=pos[0];
    posans[0]=mid;
    for(int i=1;i<n;++i)
    {
        v.insert(pos[i]);
        mid=(*v.find_by_order((i+1)/2));
        posans[i]=mid;
    }
    int ans1[n];
    ans1[0]=0;
    int t;
    for(int i=1;i<n;++i)
    {
        t=ans1[i-1];
        if(posans[i]!=posans[i-1] && i%2==1)
        {
            t+=abs(posans[i]-posans[i-1]);
        }
        t+=abs(posans[i]-pos[i]);
        ans1[i]=t;
        //cout<<ans1[i]<<endl;
    }
    for(int i=0;i<n;++i)
    {
        if(i%2==0)
        {
            ans1[i]-=((i)/2*(i+2)/2);
        }
        else
        {
            ans1[i]-=((i/2))*((i+2)/2)/2+((i/2)+1)*((i+2)/2+1)/2;
        }
    }
    /*for(int i=0;i<n;++i)
    {
        cout<<ans1[i]<<" ";
    }*/
    //cout<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<ans1[i]+pr[i+1]<<" ";
    }
    return 0;
}