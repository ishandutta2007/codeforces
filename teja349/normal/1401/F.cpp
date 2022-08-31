//teja349
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
using namespace __gnu_pbds;

#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define flush fflush(stdout) 
#define primeDEN 727999983
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// find_by_order()  // order_of_key
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
#define int ll

int a[(1<<18)+10];
int seg[(1<<20)+10],lazy[(1<<20)+10],lef[(1<<20)+10],rig[(1<<20)+10];
int build(int node,int s,int e){
    lazy[node]=0;
    if(s==e){
        seg[node]=a[s];
        return 0;
    }
    int mid=(s+e)/2;
    build(2*node,s,mid);
    build(2*node+1,mid+1,e);
    lef[node]=2*node;
    rig[node]=2*node+1;
    seg[node]=seg[2*node]+seg[2*node+1];
    return 0;
}

int update(int node,int s,int e,int pos,int val){
    if(lazy[node]){
        if(lazy[node]%2){
            swap(lef[node],rig[node]);
            lazy[lef[node]]^=1;
            lazy[rig[node]]^=1;
        }
        lazy[node]/=2;
        lazy[lef[node]]^=lazy[node];
        lazy[rig[node]]^=lazy[node];
        lazy[node]=0;
    }
    if(pos<s || e<pos){
        return 0;
    }   
    if(s==e){
        seg[node]=val;
        return 0;
    }
    int mid=(s+e)/2;
    update(lef[node],s,mid,pos,val);
    update(rig[node],mid+1,e,pos,val);
    seg[node]=seg[2*node]+seg[2*node+1];
    return 0;
}

int query(int node,int s,int e,int l,int r){
     if(lazy[node]){
        if(lazy[node]%2){
            swap(lef[node],rig[node]);
            lazy[lef[node]]^=1;
            lazy[rig[node]]^=1;
        }
        lazy[node]/=2;
        lazy[lef[node]]^=lazy[node];
        lazy[rig[node]]^=lazy[node];
        lazy[node]=0;
    }
    if(r<s || e<l)
        return 0;
    if(l<=s && e<=r){
        return seg[node];
    }
    int mid=(s+e)/2;
    return query(lef[node],s,mid,l,r)+query(rig[node],mid+1,e,l,r);
}
main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    int gg=(1<<n);
    int i;
    f(i,1,gg+1){
        cin>>a[i];
    }
    build(1,1,gg);
    rep(i,q){
        int type;
        cin>>type;
        if(type==1){
            int pos,val;
            cin>>pos>>val;
            update(1,1,gg,pos,val);
        }
        else if(type==2){
            int k;
            cin>>k;
            lazy[1]^=(1<<(n-k));
        }
        else if(type==3){
            int k;
            cin>>k;
            lazy[1]^=(1<<(n-k));
            lazy[1]^=(1<<(n-k-1));
        }
        else{
            int l,r;
            cin>>l>>r;
            cout<<query(1,1,gg,l,r)<<endl;
        }
    }

    return 0;   
}