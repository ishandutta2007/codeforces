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
//setbase - cout << setbase (16); cout << 100 << endl; Prlls 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx


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

//std::ios::sync_with_stdio(false); 
ll mult(ll arr[20][20],ll barr[20][20],ll siz){
	ll i,j,k;
	ll ba[20][20]={0};
	rep(i,siz){
		rep(j,siz){
			rep(k,siz){
				ba[i][j]+=arr[i][k]*barr[k][j];
				ba[i][j]%=mod;
			}
		}
	}
	rep(i,siz){
		rep(j,siz){
			arr[i][j]=ba[i][j];
		}
	}
	return 0;
}  
ll multexp(ll arr[20][20],ll siz,ll n){
	ll res[20][20]={0};
	ll i,j;
	rep(i,siz){
		rep(j,siz){
			res[i][j]=0;
		}
		res[i][i]=1;
	}
	while(n>0){
		if(n%2){
			
			mult(res,arr,siz);
			//cout<<siz<<endl;
			// rep(i,siz){
			// 	rep(j,siz){
			// 		cout<<res[i][j]<<" ";
			// 	}
			// 	cout<<endl;
			// }
		}
		//cout<<n<<endl;
		mult(arr,arr,siz);

		n/=2;
	}
	rep(i,siz){
		rep(j,siz){
			arr[i][j]=res[i][j];
		}
	}
	return 0;
}

ll c[200],a[200],b[200];
ll dp[200][30];
ll compute(ll val){
	//cout<<"gddf";
	ll arr[20][20];
	ll i,j;
	rep(i,c[val]+1){
		rep(j,c[val]+1){
			arr[i][j]=0;
		}
	}
	if(c[val]){
		arr[0][0]=1;
		arr[0][1]=1;
		arr[c[val]][c[val]]=1;
		arr[c[val]][c[val]-1]=1;
	}
	else{
		arr[0][0]=1;
		arr[c[i]][c[i]]=1;
	}
	f(i,1,c[val]){
		arr[i][i+1]=1;
		arr[i][i-1]=1;
		arr[i][i]=1;
	}
	rep(i,c[val]+1){
		rep(j,c[val]+1){
			//cout<<i<<" "<<j<<" "<<arr[i][j]<<endl;
		}
	}
	multexp(arr,c[val]+1,b[val]-a[val]);
	rep(i,c[val]+1){
		rep(j,c[val]+1){
			//cout<<i<<" "<<j<<" "<<arr[i][j]<<endl;
			dp[val][i]+=(arr[j][i]*dp[val+1][j])%mod;
			dp[val][i]%=mod;
		}
	}
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
	ll n,k;
	cin>>n>>k;
	ll i;
	rep(i,n){
		cin>>a[i]>>b[i]>>c[i];
	}
	b[n-1]=k;
	rep(i,16){
		dp[n][i]=0;
	}
	dp[n][0]=1;
	fd(i,n-1,0){
		compute(i);
	}   
	cout<<dp[0][0]<<endl;  
    
}