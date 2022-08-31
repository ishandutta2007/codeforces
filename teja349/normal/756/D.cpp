
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
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx


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
ll arr[27][5002]={0};
ll arrall[5005]={0};
//ll comb[5002][5002]={0};
ll inv[100003],mult[100003],invmult[100003];
ll gcd(ll a,ll b){
	while(b!=0){
		
		a=a%b;
		swap(a,b);
	}
	return a;
}

ll extend_gcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	ll x1,y1;
	ll ans =extend_gcd(b,a%b,x1,y1);
	x=y1;
	y=x1-(a/b)*y1;

	return ans;
}
ll combination(ll n,ll r){
	if(r==0)
		return 1;
	ll ans=1;
	ans*=mult[n];
	ans%=mod;
	ans*=invmult[r];
	ans%=mod;
	ans*=invmult[n-r];
	ans%=mod;
	return ans;
}

ll initcombi(){			// need to call it from main 
	int i;
	f(i,1,100001){
		ll x,y;
		ll val=extend_gcd(mod,i,x,y);
		if(y>0)
			inv[i]=y%mod;
		else{
				inv[i]=(y+mod)%mod;
		}
	}
	mult[0]=1;
	f(i,1,100001){
		mult[i]=mult[i-1]*i;
		mult[i]%=mod;
	}
	invmult[0]=1;
	f(i,1,100001){
		invmult[i]=invmult[i-1]*inv[i];
		invmult[i]%=mod;
	}
}


int main(){
	std::ios::sync_with_stdio(false);
	initcombi();
	int n;
	string s;
	cin>>n>>s;
	// f(i,0,n+1){
	// 	comb[0][i]=0;
	// 	comb[i][0]=0;
	// }
	// f(i,2,n+1){
	// 	f(j,1,i+1){
	// 		comb[i][j]=comb[i-1][j-1]+comb[i-1][j];
	// 		comb[i][j]%=mod;
	// 	}
	// }
	int i,j,k;
	ll len[7000]={0};
	rep(i,n){
		f(j,1,n+1){
			arrall[j]=arrall[j]-arr[s[i]-'a'][j];
			arrall[j]%=mod;
			arrall[j]%=mod;
		}
		f(j,2,n+1){
			arr[s[i]-'a'][j]=arrall[j-1];
			//arr[s[i]-'a'][j]%=mod;

		}
		arr[s[i]-'a'][1]=1;
		//cout<<"Hii";
		f(j,1,n+1){
			arrall[j]+=arr[s[i]-'a'][j];
			arrall[j]%=mod;
		}
		
	}

	
	ll sum=0;
	f(i,1,n+1){
		//cout<<len[i]<<endl;
		sum+=arrall[i]*combination(n-1,i-1);
		sum%=mod;
	}
	cout<<sum<<endl;





}