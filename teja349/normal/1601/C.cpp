//teja349
#include <bits/stdc++.h>
// #include <sys/resource.h>
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
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 candy.cpp


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

int seg[4123456],lazy[4123456];

int bit[1234567];
int counter=0;
int updatebit(int pos){
    while(pos<counter+10){
        bit[pos]++;
        pos+=pos&(-pos);
    }
    return 0;
}

int querybit(int pos){
    int ans=0;
    while(pos){
        ans+=bit[pos];
        pos-=pos&(-pos);
    }
    return ans;
}

int build(int node,int s,int e){
    lazy[node]=0;
    if(s==e){
        seg[node]=s;
        return 0;
    }

    int mid=(s+e)/2;
    build(2*node,s,mid);
    build(2*node+1,mid+1,e);
    seg[node]=min(seg[2*node],seg[2*node+1]);
    // cout<<
    return 0;
}

int update(int node,int s,int e,int l,int r,int val){
    if(lazy[node]){
        seg[node]+=lazy[node];
        if(s!=e){
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(r<s || e<l){
        return 0;
    }

    if(l<=s && e<=r){
        lazy[node]=val;
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

    seg[node]=min(seg[2*node],seg[2*node+1]);
    // cout<<s<<" "<<e<<" "<<seg[3]<<endl;
    return 0;
}

int a[1234567],b[1234567];
int foo[1234567];

int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
 //    rlimit R;
	// getrlimit(RLIMIT_STACK, &R);
	// R.rlim_cur = R.rlim_max;
	// setrlimit(RLIMIT_STACK, &R);
    int t=1;
    cin>>t;
    int t1=t;
    while(t--){
    	// cout<<"Case #"<<t1-t<<": ";
        int n,m;
        cin>>n>>m;
        vii vec;
        map<int,int> mapi;
        int i,j;
        rep(i,n){
            cin>>a[i];
            mapi[a[i]]=1;
            vec.pb(mp(a[i],i));
        }
        sort(all(vec));
        counter=1;
        map<int,int>::iterator it;
        for(it=mapi.begin();it!=mapi.end();it++){
            it->ss=counter++;
        }
        rep(i,n){
            foo[i]=mapi[a[i]];
        }
        rep(i,counter+20){
            bit[i]=0;
        }
        ll ans=0;
        fd(i,n-1,0){
            updatebit(foo[i]);
            ans+=querybit(foo[i]-1);
        }
        build(1,0,n);
        rep(i,m){
            cin>>b[i];
        }
        sort(b,b+m);
        j=0;
        int prevj,prevb=-1;
        b[m]=inf;
        rep(i,m){
            while(j<vec.size() && vec[j].ff<b[i]){
                int ind = vec[j].ss;
                update(1,0,n,ind+1,n,-1);
                update(1,0,n,0,ind,1);
                j++;
            }
            if(prevb!=b[i]){
                prevj=j;
            }
            prevb=b[i];
            while(j<vec.size() && vec[j].ff==b[i]){
                int ind = vec[j].ss;
                // cout<<"dsds"<<endl;
                update(1,0,n,ind+1,n,-1);
                // cout<<ind<<endl;
                j++;
            }
            ans+=seg[1];
            // cout<<ans<<endl;
            // if(i==1)
            //     return 0;
            // return 0;
            if(b[i]==b[i+1]){
                continue;
            }
            j=prevj;
            while(j<vec.size() && vec[j].ff==b[i]){
                int ind = vec[j].ss;
                update(1,0,n,0,ind,1);
                j++;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}