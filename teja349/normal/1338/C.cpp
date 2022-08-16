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
#define int ll 
 
 int getbit(int val,int pos){
 	if(val&(1LL<<pos))
 		return 1;
 	return 0;
 }
signed main(){
	std::ios::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		n--;
		int step=n/3;
		int term=n%3;
		int i=0,sofar=0,j;
		while(1){
			if(step<sofar+(1LL<<i)){
				break;
			}
			sofar+=(1LL<<i);
			i+=2;
		}
		int cur=(1LL<<i);
		cur+=step-sofar;
		int ans;
		if(term==0){
			ans=cur;
		}
		else{
			ans=(1LL<<(i+1));
			//cout<<term<<" "<<cur<<" "<<ans<<" ";
			fd(j,i-1,0){
				int val1=getbit(cur,j);
				int val2=getbit(cur,j-1);
				val1=val1*2+val2;
				//cout<<<<endl;
				if(val1==1){
					ans+=(1LL<<(j));
				}	
				else if(val1==2){
					ans+=(1LL<<(j))+(1LL<<(j-1));
				}
				else if(val1==3){
					ans+=(1LL<<(j-1));
				}
				j--;
			}
			if(term==2){
				ans^=cur;
			}
		}
		cout<<ans<<endl;
	}
}