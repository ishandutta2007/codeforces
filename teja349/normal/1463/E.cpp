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





int p[312345],nex[312345],haha[312345],posi[312345],x[312345],y[312345],deg[312345];
vector<vi> vec(312345), adj(312345);

int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
 //    rlimit R;
    // getrlimit(RLIMIT_STACK, &R);
    // R.rlim_cur = R.rlim_max;
    // setrlimit(RLIMIT_STACK, &R);
    int t=1;
    // cin>>t;
    int t1=t;
    while(t--){
        //cout<<"Case #"<<t1-t<<": ";
        int n,k;
        cin>>n>>k;
        int i;
        rep(i,n){
            cin>>p[i];
            p[i]--;
        }
        rep(i,n){
            nex[i]=-1;
            haha[i]=-1;
            posi[i]=0;
        }
        rep(i,k){
            cin>>x[i]>>y[i];
            x[i]--;
            y[i]--;
            nex[x[i]]=y[i];
            deg[y[i]]++;
        }

        stack<int> st;
        rep(i,k){
            if(deg[x[i]]==0){
                st.push(x[i]);
            }
        }
        int len=0,counter=0;
        while(!st.empty()){
            int cur = st.top();
            st.pop();
            len--;
            int boo=0;
            while(cur!=-1){
                vec[counter].pb(cur);
                haha[cur]=counter;
                posi[cur]=boo++;
                cur=nex[cur];
                len++;
            }
            counter++;
        }
        if(len!=k){
            cout<<0<<endl;
            return 0;
        }
        rep(i,n){
            if(haha[i]==-1){
                vec[counter].pb(i);
                haha[i]=counter++;
            }
        }

        rep(i,counter){
            deg[i]=0;
        }
        rep(i,n){
            if(p[i]==-1)
                continue;
            if(haha[p[i]]==haha[i]){
                if(posi[p[i]]>posi[i]){
                    cout<<0<<endl;
                    return 0;
                }
            }
            else{
                adj[haha[p[i]]].pb(haha[i]);
                deg[haha[i]]++;
            }
        }

        rep(i,counter){
            if(deg[i]==0){
                st.push(i);
            }
        }

        vi gao;
        int cnt=0;
        while(!st.empty()){
            int cur=st.top();
            st.pop();
            cnt++;
            gao.pb(cur);
            rep(i,adj[cur].size()){
                deg[adj[cur][i]]--;
                if(deg[adj[cur][i]]==0)
                    st.push(adj[cur][i]);
            }
            
        }

        if(cnt!=counter){
            cout<<0<<endl;
            return 0;
        }
        int j;
        rep(i,gao.size()){
            rep(j,vec[gao[i]].size()){
                cout<<vec[gao[i]][j]+1<<" ";
            }
        }
        cout<<endl;


    }

    return 0;
}