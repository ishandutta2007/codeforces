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
#define tri pair<int, pii>
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

int n;

int gg[212345][19];
int a[212345],dsu[212345];

int getgcd(int l,int r){
	int val=r-l+1;
    int cur=1,logg=0;
    while(cur<=val){
        cur*=2;
        logg++;
    }
    logg--;
    val=logg;
	return __gcd(gg[l][val],gg[r-(1<<val)+1][val]);
}


int geten(int val,int pos){
    int low=pos;
    int high=n-1;
    int ans=pos;
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(getgcd(pos,mid)==val){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}
int getst(int val,int pos){
    int low=0;
    int high=pos;
    int ans=pos;
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(getgcd(mid,pos)==val){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

int getpar(int u){
    if(dsu[u]<0)
        return u;
    dsu[u]=getpar(dsu[u]);
    return dsu[u];
}

int merge(int u,int v){
    u=getpar(u);
    v=getpar(v);
    if(dsu[u]<dsu[v])
        swap(u,v);
    dsu[v]+=dsu[u];
    dsu[u]=v;
    return 0;
}

int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    	int p;
    	cin>>n>>p;
    	int i,j;
    	rep(i,n){
    		cin>>a[i];
    		gg[i][0]=a[i];
    	}
    	f(j,1,19){
            rep(i,n){
                if(i+(1<<(j-1))>=n)
                    break;
                gg[i][j] = __gcd(gg[i][j-1],gg[i+(1<<(j-1))][j-1]);
            }
        }
     
        viii vec;
        rep(i,n){
            if(a[i]>=p)
                continue;
            int haha = getst(a[i],i);   
            int wow = geten(a[i],i);
            vec.pb(mp(a[i],mp(haha,wow)));
        }

        sort(all(vec));
        rep(i,n){
            dsu[i]=-1;
        }
        set<int> seti;
        rep(i,n-1){
            seti.insert(i+1);
        }
        ll wt=0;
        ll edges=0;
        rep(i,vec.size()){
            int len = vec[i].ff;
            int st = vec[i].ss.ff;
            int en = vec[i].ss.ss;
            int pos=st;
            set<int>::iterator it;
            while(1){
                it=seti.upper_bound(st);        
                if(it==seti.end())
                    break;
                st=*it;
                if(st>en)
                    break;
                seti.erase(st);
                if(getpar(st)!=getpar(pos)){
                    edges++;
                    merge(st,pos);
                    wt+=len;
                }
            }
        }
        ll bar = n-1-edges;
        wt+=bar*p;
        cout<<wt<<endl;

    }
    return 0;
}