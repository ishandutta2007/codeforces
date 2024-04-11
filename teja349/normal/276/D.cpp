// teja349
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


//helper functions
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
ll l,r;

ll compute(int ind,int ha,int la,int uped){
	if(ind<0)
		return 0;
	ll ans=0;

	ll val1=l&(1LL<<ind);
	ll val2=r&(1LL<<ind);
	ll lol=(1LL<<ind);
	//cout<<lol<<endl;
	if(ha*la==1){
		ans=lol;
		ans+=compute(ind-1,1,1,1);
		//cout<<ans<<endl;
		return ans;
	}
	if(ha==0 && la==0 && uped==0){
		if(val1!=0 && val2==0){
			ans=val1;
			ans+=compute(ind-1,ha,la,0);
		}
		else if(val1==0){
			if(val2==0){
				
				ans=compute(ind-1,0,0,0);
			}
			else{
				ans=lol;
				ans+=compute(ind-1,0,0,1);
				//cout<<lol<<endl;
			}

		}
		else{
			ans=compute(ind-1,ha,la,0);
		}
		return ans;
	}
	//cout<<val1<<" "<<val2<<endl;
	if(ha==0 && la==0){
	//	cout<<lol<<endl;
		if(val1!=0 && val2==0){
			//cout<<lol<<endl;
			ans=lol;
			ans+=compute(ind-1,ha,la,1);
		}
		else if(val1==0){
			if(val2==0){
				ans=lol;
				ans+=compute(ind-1,1,0,1);
			}
			else{
				ans=lol;
				ans+=compute(ind-1,1,1,1);
			}

		}
		else{
			ans=lol;
			//cout<<lol<<endl;
			ans+=compute(ind-1,ha,1,1);
		}
		//cout<<ans<<endl;
		return ans;
	}
	if(ha==0){
		if(val1==0){
			ans=lol;
			ans+=compute(ind-1,1,1,1);
		}
		else{
			ans=lol;
			ans+=compute(ind-1,0,1,1);
		}
		//cout<<ans<<endl;
		return ans;
	}
	if(la==0){
		if(val2==0){
			ans=lol;
			ans+=compute(ind-1,1,0,1);
		}
		else{
			ans=lol;
			ans+=compute(ind-1,1,1,1);
		}
		//cout<<ans<<endl;
		return ans;
	}



}

int main(){
	cin>>l>>r;
	int ind=0;
	while((l>>ind) || (r>>ind)){
		ind++;
	}
	ind--;
	cout<<compute(ind,0,0,0)<<endl;
}