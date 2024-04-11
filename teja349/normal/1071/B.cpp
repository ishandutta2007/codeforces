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
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
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

bool wow[2010][2010];
int d[2010][2010];
int n;
string s[2234];
int valid(int i,int j){
	if(i<0 || i>=n || j<0 || j>=n)
		return 0;
	return 1;
}
vii vec,vec1;
int comp(pii a,pii b){
	return s[a.ff][a.ss]<s[b.ff][b.ss];
}
int addstate(pii a){
	int i=a.ff;
	int j=a.ss;
	if(valid(i+1,j))
		vec1.pb(mp(i+1,j));
	if(valid(i,j+1))
		vec1.pb(mp(i,j+1));
	return 0;
}
char elem(pii a){
	return s[a.ff][a.ss];
}
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int k;
    cin>>n>>k;
    int i,j;
    rep(i,n){
    	cin>>s[i];
    	rep(j,n){
    		if(s[i][j]!='a')
    			wow[i][j]=1;
    	}
    }
    //return 0;
    rep(i,n){
    	rep(j,n){
    		d[i][j]=inf;
    	}
    }
    if(wow[0][0]==0)
    	d[0][0]=0;
    else
    	d[0][0]=1;
    rep(i,n){
    	rep(j,n){
    		if(d[i][j]==k+1){
    			continue;
    		}
    		if(valid(i+1,j) && d[i+1][j]>d[i][j]+wow[i+1][j]){
    			d[i+1][j]=d[i][j]+wow[i+1][j];
    			//par[i+1][j]=1;
    		}
    		if(valid(i,j+1) && d[i][j+1]>d[i][j]+wow[i][j+1]){
    			d[i][j+1]=d[i][j]+wow[i][j+1];
    			//par[i][j+1]=0;
    		}
    	}
    }
    //return 0;
    if(d[n-1][n-1]<=k){
    	rep(i,2*n-1){
    		cout<<'a';
    	}
    	return 0;
    }
    int maxi=0;
    rep(i,n){
    	rep(j,n){
    		//cout<<d[i][j]<<" ";
    		if(d[i][j]==k+1){
    			maxi=max(maxi,i+j);
    		}
    	}
    	//cout<<endl;
    }
   // return 0;
   // cout<<maxi<<endl;
    string ans="";
    rep(i,maxi){
    	ans+='a';
    }

    rep(i,n){
    	rep(j,n){
    		if(d[i][j]==k+1 && maxi==i+j){
    			vec.pb(mp(i,j));
    		}
    	}
    }
    f(j,maxi,2*n-1){
    	sort(all(vec));
    	vec.resize(unique(all(vec))-vec.begin());
    	sort(all(vec),comp);
    	ans+=elem(vec[0]);
    	addstate(vec[0]);
    	f(i,1,vec.size()){
    		if(elem(vec[i])!=elem(vec[i-1]))
    			break;
    		addstate(vec[i]);
    	}
    	vec.clear();
    	rep(i,vec1.size()){
    		vec.pb(vec1[i]);
    	}
    	vec1.clear();
    }
    cout<<ans<<endl;


    return 0;   
}