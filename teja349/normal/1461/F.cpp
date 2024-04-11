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

int iter=1;
int vis[123][123],dp[123][123],foo[123][123];
vi vec1;
int solver(int s,int e){
	if(vis[s][e]==iter){
		return dp[s][e];
	}

	int i,prod=1;
	for(i=s;i<=e;i+=2){
		prod*=vec1[i];
	}
	int maxi=prod;
	int breaker=-1;
	for(i=s+1;i<=e;i+=2){
		int val=solver(s,i-1)+vec1[i]+solver(i+1,e);
		if(val>maxi){
			maxi=val;
			breaker=i;
		}
	}
	vis[s][e]=iter;
	dp[s][e]=maxi;
	foo[s][e]=breaker;
	return dp[s][e];
}

int gao[123];
int fillans(int s,int e){
	//cout<<s<<" "<<e<<" "<<dp[s][e]<<endl;
	int i;
	if(foo[s][e]==-1){
		for(i=s+1;i<=e;i+=2){
			gao[i/2]=2;
		}
		return 0;
	}
	gao[foo[s][e]/2]=1;
	fillans(s,foo[s][e]-1);
	fillans(foo[s][e]+1,e);
	return 0;
}

int a[123456];
int haha[123456];
vi vec;
int solve(int s,int e){
	if(s==e)
		return 0;
	int i;
	f(i,s,e){
		if(a[i]>1)
			break;
		haha[i]=1;
	}
	int st=i;
	fd(i,e,s+1){
		if(a[i]>1)
			break;
		haha[i-1]=1;
	}
	int en=i;
	if(en<=st){
		return 0;
	}

	int prod=1;
	int gg=inf;
	gg/=1000;
	f(i,st,en+1){
		prod*=a[i];
		if(prod>gg)
			prod=gg;	
	}
	if(prod>=gg){
		f(i,st,en){
			haha[i]=2;
		}
		return 0;
	}
	int j=0;
	f(i,st,en){
		if(a[i]>1 && a[i+1]>1){
			haha[i]=2;
		}
	}
	int soprod=1;
	int soone=0;
	vec1.clear();
	f(i,st,en+1){
		if(a[i]>1){
			if(soone>0){
				vec1.pb(soone);
				soone=0;
			}
			soprod*=a[i];
		}
		else{
			if(soprod>1){
				vec1.pb(soprod);
				soprod=1;
			}
			soone++;
		}
	}
	vec1.pb(soprod);

	int star=0;
	int endi=vec1.size();
	endi--;
	solver(star,endi);
	fillans(star,endi);
	iter++;
	int curr=0;
	soprod=1;
	soone=0;
	f(i,st,en+1){
		if(a[i]>1){
			if(soone>0){
				soone=0;
				curr++;
			}
		}
		else{
			haha[i-1]=gao[curr];
			haha[i]=gao[curr];
			soone++;
		}
	}

	return 0;

}

int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    //cin>>t;
    t=1;
    while(t--){
    	int n;
    	cin>>n;
    	int i;
    	rep(i,n){
    		cin>>a[i];
    	}
    	string s;
    	cin>>s;
    	if(s.length()==1){
    		cout<<a[0];
    		f(i,1,n){
    			cout<<s[0]<<a[i];
    		}
    		cout<<endl;
    		return 0;
    	}
    	if(s.length()==3){
    		s="*+";
    	}
    	int muli=0,addi=0,subi=0;
    	rep(i,s.length()){
    		if(s[i]=='*'){
    			muli=1;
    		}
    		if(s[i]=='-'){
    			subi=1;
    		}
    		if(s[i]=='+')
    			addi=1;
    	}
    	if(muli==0){
    		cout<<a[0];
    		f(i,1,n){
    			cout<<'+'<<a[i];
    		}
    		cout<<endl;
    		return 0;
    	}

    	if(addi==0){
    		cout<<a[0];
    		f(i,1,n){
    			if(a[i]==0)
    				break;
    			cout<<'*'<<a[i];
    		}
    		if(i<n)
    			cout<<"-"<<a[i];
    		int j;
    		i++;
    		f(j,i,n){
    			cout<<'*'<<a[j];
    		}
    		cout<<endl;
    		return 0;
    	}
    	
    	rep(i,n){
    		if(a[i]==0){
    			haha[i]=1;
    			if(i>0)
    				haha[i-1]=1;
    		}
    	}
    	haha[n-1]=1;
    	int previ=0;
    	int gg=-1;
    	rep(i,n){
    		if(haha[i]){
    			solve(previ,i);
    			previ=i+1;
    		}
    	}
    	if(previ<=n-1)
    		solve(previ,n-1);

    	rep(i,n-1){
    		cout<<a[i];
    		if(haha[i]==1)
    			cout<<'+';
    		else
    			cout<<'*';
    	}
    	cout<<a[n-1]<<endl;
    }

    return 0;
}