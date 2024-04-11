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

const int maxn = 1e5 + 5;
const char sep = '$';   
// add  (&& s[i + k] != sep) in buildlcp when multiple strings are concatenated using sep
string s;
int sa[maxn], pos[2][maxn];
int lcp[maxn];
struct SuffixArray {
    int n;
    void build() {
        n = s.length();
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
        int mx = max(256, n) + 1;
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

int dp[123456][19];
int getlcp(int s,int e){
	s++;
	int val=log2(e-s+1);
	return min(dp[s][val],dp[e-(1<<val)+1][val]);
}

int geten(int i,int val,int st,int en){
	int ans=st;
	int mid;
	en--;

	while(st<=en){
		//cout<<i<<" "<<en<<endl;
		mid=(st+en)/2;
		if(getlcp(i,mid)==val){
			ans=mid;
			st=mid+1;
		}
		else{
			en=mid-1;
		}
	}
	//cout<<i<<" "<<val<<" "<<st<<" "<<getlcp(0,2)<<endl;
	return ans;
}
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
  	//string s;
  	cin>>s;
  	int n=s.length();
  	SuffixArray hh;
  	hh.build();
  	int i;
  	rep(i,n){
  		dp[i][0]=lcp[i];
  	}
  	int j;
  	f(j,1,19){
  		rep(i,n){
  			if(i+(1<<(j-1))<n)
  				dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
  		}
  	}
  	ll previ=0;
  	ll curlen,st,en,val;
  	ll ans=0;
  	rep(i,n){
  		curlen=n-sa[i];
  		st=i+1;
  		previ=lcp[i];
  		while(st<n){
  			val=getlcp(i,st);
  			
  			if(curlen<=previ){
  				break;
  			}
  			ans+=(curlen-max(val,previ))*(st-i)*(st-i+1)/2;
  			en=geten(i,val,st,n);
  			//cout<<i<<" "<<st<<" "<<val<<" "<<sa[i]<<endl;
  			curlen=val;
  			st=en+1;
  		}
  		val=0;
  		if(curlen>previ)
  			ans+=(curlen-max(val,previ))*(st-i)*(st-i+1)/2;
  	}
  	cout<<ans<<endl;
    return 0;   
}