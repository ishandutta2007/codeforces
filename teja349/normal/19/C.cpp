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


/*
 * Complexity: O(NlogN)
 * Problems:
 * 1. http://www.spoj.com/problems/SUBST1/
 * Taken from Chemthan !...!
 */

const int maxn = 2e5 + 5;
const char sep = '$';
int s[maxn];
int sa[maxn], pos[2][maxn];
int lcp[maxn];
struct SuffixArray {
    int n;
    void build(int _n) {
        n =_n;
        for (int i = 0; i < n; i++) {
            sa[i] = i, pos[0][i] = 0, pos[1][i] = s[i] + 1;
        }
        for (int d = 1; radixsort(); d <<= 1) {
            for (int i = 0; i < n; i++) {
                if (i + d < n) {
                    pos[1][i] = pos[0][i + d] + 1;
                }
                else {
                    pos[1][i] = 0;
                }
            }
        }
        buildlcp();
    }

    int radixsort() {
        static int p[maxn];
        static int tmpsa[maxn];
        static int tmpra[maxn];
        int mx = max(256, n) + 3;
        for (int step = 1; step >= 0; step--) {
            fill_n(p, mx, 0);
            for (int i = 0; i < n; i++) {
                p[pos[step][i] + 1]++;
                tmpsa[i] = sa[i];
            }
            partial_sum(p, p + mx, p);
            for (int i = 0; i < n; i++) {
                sa[p[pos[step][tmpsa[i]]]++] = tmpsa[i];
            }
        }
        int ptr = 0;
        tmpra[sa[0]] = ptr;
        for (int i = 1; i < n; i++) {
            int u = sa[i - 1];
            int v = sa[i];
            if (pos[0][u] < pos[0][v] || pos[1][u] < pos[1][v]) {
                ptr++;
            }
            tmpra[v] = ptr;
        }
        for (int i = 0; i < n; i++) pos[0][i] = tmpra[i];
        return ptr < n - 1;
    }

    void buildlcp() {
        for (int i = 0, k = 0; i < n; i++) {
            if (!pos[0][i]) lcp[pos[0][i]] = 0;
            else {
                for (int j = sa[pos[0][i] - 1];i+k < n && j+k < n && s[i + k] == s[j + k];)
                    k++;
                lcp[pos[0][i]] = k;
                k = max(k - 1, 0);
            }
        }
    }
};

int dp[maxn][19];
int getans(int u,int v){
	int len=log2(v-u+1);
	return min(dp[u][len],dp[v-(1<<len)+1][len]);
}
int getlcp(int u,int v){
	if(u>v)
		swap(u,v);
	u++;
	return getans(u,v);
}
map<int,int> mapi;
int inv[maxn];
vector<vi> vec(maxn);
vii poss;
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
  	int n;
  	cin>>n;
  	int i;
  	rep(i,n){
  		cin>>s[i];
  		mapi[s[i]]=0;
  	}
  	int counter=0;
  	map<int,int>::iterator it;
  	for(it=mapi.begin();it!=mapi.end();it++){
  		it->ss=counter++;	
  		inv[counter-1]=it->ff;
  	}
  	rep(i,n){
  		s[i]=mapi[s[i]];
  		vec[s[i]].pb(i);
  	}
  	SuffixArray hh;
  	hh.build(n);
  	rep(i,n){
  		dp[i][0]=lcp[i];
  	}
  	int j;
  	int u,v;
  	f(i,1,19){
  		rep(j,n){
  			if(j+(1<<(i-1))<n)
  				dp[j][i]=min(dp[j][i-1],dp[j+(1<<(i-1))][i-1]);
  		}
  	}
  	int k;
  	int wow;
  	rep(i,counter){
  		rep(j,vec[i].size()){
  			f(k,j+1,vec[i].size()){
  				//cout<<i<<endl;
  				u=vec[i][j];
  				v=vec[i][k];

  				wow=getlcp(pos[0][u],pos[0][v]);
  				if(wow>=abs(v-u)){
  					poss.pb(mp(abs(v-u),u));
  				}
  			}
  		}
  	}
  	sort(all(poss));
  	int st=0;
  	rep(i,poss.size()){
  		if(poss[i].ss<st)
  			continue;
  		st=poss[i].ff+poss[i].ss;
  	}
  	cout<<n-st<<endl;
  	f(i,st,n){
  		cout<<inv[s[i]]<<" ";
  	}
    return 0;   
}