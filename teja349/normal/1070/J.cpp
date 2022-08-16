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

int bt[212345];
int arr[123];
int solve(){
	int n,m,k;
	cin>>n>>m>>k;
	string s;
	int mini=inf;
	//mini*=inf;
	cin>>s;
	int i,j;
	rep(i,30){
		arr[i]=0;
	}
	rep(i,s.length()){
		arr[s[i]-'A']++;
	}
	sort(arr,arr+26);
	rep(i,26){		
		bt[0]=1;
		int sofar=0,who;
		rep(j,26){
			if(!arr[j])
				continue;
			if(i==j)
				continue;
			fd(who,sofar,0){
				if(bt[who])
					bt[who+arr[j]]=1;
			}
			sofar+=arr[j];
		}
		bt[sofar]=sofar;
		fd(who,sofar-1,0){
			if(!bt[who]){
				bt[who]=bt[who+1];
			}
			else{
				bt[who]=who;
			}
		}
		bt[0]=0;
		int tot,left,gg,val;
		tot=k-arr[i];
		rep(j,arr[i]+1){
			
			if(j>n)
				break;
			left=n-j;
			if(left>sofar)
				continue;
				val=bt[left];
			gg=tot-val;
			if(gg>=m){
				mini=0;
			}
			else{
				if(m-gg<=arr[i]-j)
					mini=min(mini,j*(m-gg));
			}
		}
		rep(j,sofar+2){
			bt[j]=0;
		}
	}
	cout<<mini<<"\n";
}
signed main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    	solve();
    }
    return 0;   
}