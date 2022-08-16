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


const int N = 2e6 + 10;
int tried[N][26], link[N], idx, tot[N]; 
string s;
string t[123456];

int wow;
void insert(string p) {
    int u = 0, len = p.length();
    for(int i = 0; i < len; i++) {
        int &v = tried[u][p[i] - 'a']; 
        u = v = v ? v : ++idx; 
    } tot[u]=wow;
}
void bfs() {
    queue<int> q; 
    for(q.push(0); !q.empty(); ) {
        int u = q.front(); q.pop(); 
        for(int c = 0; c < 26; c++) {
            int &v = tried[u][c]; 
            if(!v) v = tried[link[u]][c]; 
            else {
                link[v] = u ? tried[link[u]][c] : 0; 
               // tot[v] += tot[link[v]];
                q.push(v); 
            }
        }
    }
}
int poss[N];
int match() {
    int u = 0, len = s.length(); 
    int ret = 0; 
    for(int i = 0; i < len; i++) {

        u = tried[u][s[i] - 'a']; 
       // cout<<i<<" "<<s[i]<<" "<<u<<endl;
        if(tot[u]){

        	poss[i]=tot[u];	
        }
    } return ret; 
}

int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
  	int n,k;
  	cin>>n>>k;
  	cin>>s;
  	s+=s;
  	int g;
  	cin>>g;
  	int i;
  	rep(i,g){
  		cin>>t[i];
  		wow=i+1;
  		insert(t[i]);
  	}
  	bfs();
  	match();
  	int j;
  	set<int> seti;
  	int flag=0;
  	f(i,k-1,2*k-1){
  		seti.clear();
  		rep(j,n){
  			if(poss[j*k+i])
  				seti.insert(poss[j*k+i]);
  			else
  				break;
  		}
  		if(seti.size()==n){
  			flag=1;
  			break;
  		}

  	}
  	if(flag){
  		cout<<"YES"<<endl;
  		rep(j,n){
  			cout<<poss[j*k+i]<<" ";
  		}
  	}
  	else{
  		cout<<"NO"<<endl;
  	}
    return 0;   
}