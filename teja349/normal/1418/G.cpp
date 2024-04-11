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
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000

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

int a[512345];
vector<vi> vec(512345);
int seg[2123456],lazy[2123456],cnt[2123456];
int build(int node,int s,int e){
    seg[node]=0;
    cnt[node]=e-s+1;
    if(s==e){
        return 0;
    }
    int mid=(s+e)/2;
    build(2*node,s,mid);
    build(2*node+1,mid+1,e);
    return 0;
}
int update(int node,int s,int e,int l,int r,int val){
    if(r<l){
       // cout<<"fadsf"<<endl;
        return 0;
    }
    if(lazy[node]){
        seg[node]+=lazy[node];
        if(s!=e){
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(r<s || e<l)
        return 0;
    if(l<=s && e<=r){
        lazy[node]+=val;
        seg[node]+=lazy[node];
        if(s!=e){
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
        return 0;
    }
    int mid=(s+e)/2;
    update(2*node,s,mid,l,r,val);
    update(2*node+1,mid+1,e,l,r,val);
    if(seg[2*node+1]>seg[2*node]){
        seg[node]=seg[2*node+1];
        cnt[node]=cnt[2*node+1];
    }
    else if(seg[2*node]>seg[2*node+1]){
        seg[node]=seg[2*node];
        cnt[node]=cnt[2*node];
    }
    else{
        seg[node]=seg[2*node+1];
        cnt[node]=cnt[2*node+1]+cnt[2*node];
    }
    return 0;
}
int haha[512345];

int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    int i;
    rep(i,n){
        cin>>a[i];
        haha[i]=vec[a[i]].size();
        vec[a[i]].pb(i);
    }
    ll ans=0;
    build(1,0,n);
    fd(i,n-1,0){
        update(1,0,n,i,i,n);
        int en;
        if(haha[i]+1<vec[a[i]].size()){
            en=vec[a[i]][haha[i]+1]-1;
        }
        else{
            en=n-1;
        }
        update(1,0,n,i,en,-1);
        if(haha[i]+3<vec[a[i]].size()){
            en=vec[a[i]][haha[i]+3];
        }
        else{
            en=n;
        }
        int en1;
        if(haha[i]+4<vec[a[i]].size()){
            en1=vec[a[i]][haha[i]+4];
        }
        else{
            en1=n;
        }
        update(1,0,n,en,en1-1,-1);
        if(haha[i]+2<vec[a[i]].size()){
            en=vec[a[i]][haha[i]+2];
        }
        else{
            en=n;
        }
        if(haha[i]+3<vec[a[i]].size()){
            en1=vec[a[i]][haha[i]+3];
        }
        else{
            en1=n;
        }
        update(1,0,n,en,en1-1,1);
        if(seg[1]==n){
           // cout<<i<<" "<<cnt[1]<<endl;
            ans+=cnt[1];
        }
        // else{
        //     cout<<i<<"  dasds"<<endl;
        // }
    }
    cout<<ans<<endl;
    return 0;   
}