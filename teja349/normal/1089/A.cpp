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

int dp[210][210][6][7];
pii par[210][210][6][7];
pii ans[210][210];	
int getans(int a,int b){
	if(ans[a][b]==mp(0,0))
	{
		cout<<"Impossible"<<endl;
		return 0;
	}
	int i=ans[a][b].ss;
	int lead=ans[a][b].ff;
	int haha,wow,gg=lead-3;
	haha=(i+gg)/2;
	wow=(i-gg)/2;
	assert(haha>=2 || wow>=2);
	cout<<haha<<":"<<wow<<endl;
	// cout<<a<<" "<<b<<endl;
	int a1,b1;
	vi vec,vec1;
	assert(i>=3);
	while(i>0){
		// if(i>1)
		// 	cout<<par[a][b][i][lead].ff<<":"<<par[a][b][i][lead].ss<<" ";
		// else
		// 	cout<<par[a][b][i][lead].ff<<":"<<par[a][b][i][lead].ss<<endl;
		vec.pb(par[a][b][i][lead].ff);
		vec1.pb(par[a][b][i][lead].ss);
		a1=a-par[a][b][i][lead].ff;
		b1=b-par[a][b][i][lead].ss;
		if(par[a][b][i][lead].ff>par[a][b][i][lead].ss)
			lead--;
		else
			lead++;
		i--;
		a=a1;
		b=b1;
	}
	fd(i,(int)vec.size()-1,0){
		if(i!=0)
			cout<<vec[i]<<":"<<vec1[i]<<" ";
		else
			cout<<vec[i]<<":"<<vec1[i]<<endl;
	}
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    dp[0][0][0][3]=1;
    int i,a,b,lead;
    int gg,haha,wow;
    int j;
    int who;
    rep(i,5){
    	rep(a,203){
    		rep(b,203){
    			f(lead,0,7){
    				if(dp[a][b][i][lead]==0)
    					continue;
    				gg=lead-3;
    				haha=(i+gg)/2;
    				wow=(i-gg)/2;

    				if(haha>2 || wow>2){
    					continue;
    				}
    				// if(a==0 && b==50){
    				// 	cout<<lead<<endl;
    				// }
    				//first win
    				if(i==4)
    					who=15;
    				else
    					who=25;
    				if(a+who<203){
    					rep(j,who-1){
    						if(j+b>=203)
    							break;
    						dp[a+who][j+b][i+1][lead+1]=1;
    						
    						par[a+who][j+b][i+1][lead+1]=mp(who,j);
    					}
    					j=who-1;
    					while(a+j+2<203 && b+j<203){
    						dp[a+j+2][j+b][i+1][lead+1]=1;
    						par[a+j+2][j+b][i+1][lead+1]=mp(j+2,j);
    						j++;
    					}	
    				}
    				// second wins
    				if(b+who<203){
    					rep(j,who-1){
    						if(j+a>=203)
    							break;
    						// if(a==0 && b==50 && j==0)
    						// 	cout<<"as"<<endl;
    						dp[a+j][who+b][i+1][lead-1]=1;
    						par[a+j][who+b][i+1][lead-1]=mp(j,who);
    					}
    					j=who-1;
    					while(b+j+2<203 && a+j<203){
    						dp[a+j][j+b+2][i+1][lead-1]=1;
    						par[a+j][j+b+2][i+1][lead-1]=mp(j,j+2);
    						j++;
    					}	
    				}

    			}
    		}
    	}
    }

    rep(i,6){
    	rep(a,203){
    		rep(b,203){
    			f(lead,0,7){
    				if(dp[a][b][i][lead]==0)
    					continue;

    				gg=lead-3;
    				haha=(i+gg)/2;
    				wow=(i-gg)/2;
    				if(haha<=2 && wow<=2){
    					continue;
    				}
    				ans[a][b]=max(ans[a][b],mp(lead,i));
    			}    				
    		}
    	}
    }
    // rep(a,201){
    // 	rep(b,201){
    // 		getans(a,b);
    // 	}
    // }
    int m;
    cin>>m;
    rep(i,m){
    	cin>>a>>b;
    	getans(a,b);
    }
    return 0;   
}