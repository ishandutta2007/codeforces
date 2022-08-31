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

/*
 * Complexity: O(NlogN)
 * Problems:
 * 1. http://www.spoj.com/problems/SUBST1/
 * Taken from Chemthan !...!
 */
const int maxn = 1e5 + 5;
string s;
int sa[maxn], pos[2][maxn];
int lcp[maxn];
struct SuffixArray {
    static const char sep = '$';
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
        int mx = max(256LL, n) + 1;
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
                k = max(k - 1, 0LL);
            }
        }
    }
};

int gg[maxn];

int getnext(int l,int r,int j){

	int val=s[sa[l]+j];
	int mid,ans=l;
	while(l<=r){
		mid=(l+r)/2;
		if(s[sa[mid]+j]==val)
		{
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	//cerr<<l<<" "<<r<<endl;
	return ans;
}

int getsum(int l,int r){
	int ans=gg[r];
	if(l!=0)
		ans-=gg[l-1];
	return ans;
}
signed main(){


    std::ios::sync_with_stdio(false); cin.tie(NULL);
  	int k;
  	cin>>s>>k;
  	ll val=s.length();
  	val=val*(val+1)/2;
  	if(val<k){
  		cout<<"No such line."<<endl;
  		return 0;
  	}
  	int N=s.length();
  	SuffixArray ff;
  	ff.build();
  	int i;
  	rep(i,N){
  		 gg[i]=N-sa[i];
  	}
  	rep(i,N){
  		if(i!=0)
  			gg[i]+=gg[i-1];
  	}
  	string ans="";
  	int j=0;
  	int l=0;
  	int r=N-1;
  	int v,haha;
  	int iter=0;
  	while(1){
  		//iter++;
  		//cerr<<l<<" "<<r<<endl;
  		if(N-sa[l]==j){
  			//cout<<"Ds"<<endl;
  			l++;
  		}
  		ans+='a';
  		
  		while(1){
  			iter++;
  			ans[j]=s[sa[l]+j];
  			
  			v=getnext(l,r,j);
  			haha=getsum(l,v)-(j)*(v-l+1);
  			//cerr<<j<<" "<<k<<" "<<haha<<endl;
  			//cout<<l<<" "<<v<<" "<<haha<<endl;
  			if(haha<k){
  				k-=haha;
  				l=v+1;
  			}
  			else{
  				k-=(v-l+1);
  				if(k<=0){
  					cout<<ans<<endl;
  					return 0;
  				}
  				r=v;
  				break;
  			}
  		}
  		j++;
  	}
    return 0;   

}