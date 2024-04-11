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


int mindp[2][100005][17],maxdp[2][100005][17];

int getmin(int typ,int l,int r){
	int val=log2(r-l+1);
	return min(mindp[typ][l][val],mindp[typ][r-(1<<val)+1][val]);
}

int getmax(int typ,int l,int r){
	int val=log2(r-l+1);
	return max(maxdp[typ][l][val],maxdp[typ][r-(1<<val)+1][val]);
}


int getans(int typ,int l,int r,int val){
	int ans=l;
	int st=l;
	while(l<=r){
		int mid=(l+r)/2;
		if(getmax(typ,st,mid)>val || getmin(typ,st,mid)<val){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return ans;
}

int haha[123456];
int a[123456][2],b[123456][2];
int dp[2][123456],rem[2][123456];
int marker[5],reas[5];

int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n,m;
    cin>>n>>m;
    int i,j;
    rep(i,n){
    	cin>>haha[i];
    	cin>>a[i][0]>>a[i][1];
    	cin>>b[i][0]>>b[i][1];
    }
    a[n][0]=-1;
    a[n][1]=-1;
    b[n][0]=-1;
    b[n][1]=-1;

    rep(i,n+1){
    	maxdp[0][i][0]=a[i][0];
    	maxdp[1][i][0]=b[i][0];
    	mindp[0][i][0]=a[i][1];
    	mindp[1][i][0]=b[i][1];
    }


    f(j,1,17){
    	rep(i,n+1){
    		if(i+(1<<j)-1>n){
    			continue;
    		}
    		maxdp[0][i][j]=max(maxdp[0][i][j-1],maxdp[0][i+(1<<(j-1))][j-1]);
    		mindp[0][i][j]=min(mindp[0][i][j-1],mindp[0][i+(1<<(j-1))][j-1]);
    		maxdp[1][i][j]=max(maxdp[1][i][j-1],maxdp[1][i+(1<<(j-1))][j-1]);
    		mindp[1][i][j]=min(mindp[1][i][j-1],mindp[1][i+(1<<(j-1))][j-1]);
    	}
    }


    if((a[0][0]<=haha[0] && haha[0] <=a[0][1]) && (b[0][0]<=0 && 0<=b[0][1])){
    	//cout<<"fdas"<<endl;
    	dp[0][0]=1;
    }

    if((a[0][0]<= 0 && 0<=a[0][1]) && (b[0][0]<= haha[0] && haha[0]<=b[0][1])){
    	//cout<<"fdsfa"<<endl;
    	dp[1][0]=1;
    }

    int preva = 0,prevb=0;
    f(i,1,n){
    	if((a[i][0]<=haha[i] && haha[i]<=a[i][1]) && (b[i][0]<=haha[i-1] && haha[i-1]<=b[i][1]))
    		dp[0][i]=1;

	    if((a[i][0]<=haha[i-1] && haha[i-1]<=a[i][1]) && (b[i][0]<=haha[i] & haha[i]<=b[i][1]))
    		dp[1][i]=1;
    }

    vi veca,vecb;
    rep(i,n){
    	if(a[i][0]>haha[i] || a[i][1]<haha[i])
    		veca.pb(i);
    	if(b[i][0]>haha[i] || b[i][1]<haha[i])
    		vecb.pb(i);
    }
    veca.pb(n);
    vecb.pb(n);

    //return 0;
	marker[0] = 0;
	marker[1] = 0;
    rep(i,n){
    	int posi;
    	if(i>marker[0]){
    		dp[0][i]=0;
    	}
    	if(i>marker[1]){
    		dp[1][i]=0;
    	}
    	rem[0][i]=reas[0];
    	rem[1][i]=reas[1];
    	if(dp[0][i]){
    		posi = veca[lower_bound(all(veca),i+1)-veca.begin()];
    		posi = min(getans(1,i+1,n,prevb),posi);
    		//cout<<0<<" "<<i<<" "<<posi<<endl;
    		if(marker[1]<posi){
    			marker[1] = posi;
    			reas[1] = i;
    		}
    	}

    	if(dp[1][i]){
    		posi = vecb[lower_bound(all(vecb),i+1)-vecb.begin()];
    		posi = min(getans(0,i+1,n,preva),posi);
    		// cout<<1<<" "<<i<<" "<<posi<<endl;
    		if(marker[0]<posi){
    			marker[0] = posi;
    			reas[0] = i;
    		}
    	}
    	if(marker[0]==n || marker[1]==n)
    		break;
    	preva = haha[i];
    	prevb = haha[i];
    }
    if(marker[0]!=n && marker[1]!=n){
    	cout<<"NO"<<endl;
    	return 0;
    }
    cout<<"YES"<<endl;
    
    vi gg;
    int typ,pos;

    if(marker[0]==n){
    	f(i,reas[0],n){
    		gg.pb(1);
    	}
    	typ=1;
    	pos=reas[0];
    } else{
    	f(i,reas[1],n){
    		gg.pb(0);
    	}
    	typ=0;
    	pos=reas[1];
    }

    while(pos!=0){
    	// cout<<pos
    	f(i,rem[typ][pos],pos){
    		gg.pb(typ^1);
    	}
    	pos=rem[typ][pos];
    	typ^=1;
    }

    fd(i,n-1,0){
    	cout<<gg[i]<<endl;
    }


    return 0;
}