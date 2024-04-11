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
ll haha1,haha2,haha3,ans1,ans2,ans3;
int n,m,p;
vi vec;
int a[212345],b[212345],sumi=0;
int checker(int pos){
	if(haha1!=ans1){
		return 0;
	}
	if(haha2!=ans2){
		return 0;
	}
	if(haha3!=ans3){
		return 0;
	}
	sumi++;
	vec.pb(pos);
	return 0;
}  
int compute(int pos){
	int ind=0;
	ll value;
	haha2=haha3=haha1=0;
	while(ind!=m){
		if(pos+ind*p>n){
			return 0;
		}
		value=a[pos+ind*p];
		haha1+=value;
		value*=a[pos+ind*p];
		value%=mod;
		haha2+=value;
		value*=a[pos+ind*p];
		value%=mod;
		haha3+=value;
		ind++;
	}
	checker(pos);
	
	while(1){
		if(pos+ind*p>n){
			return 0;
		}
		value=a[pos+ind*p];
		haha1+=value;
		value*=a[pos+ind*p];
		value%=mod;
		haha2+=value;
		value*=a[pos+ind*p];
		value%=mod;
		haha3+=value;
		value=a[pos+(ind-m)*p];
		haha1-=value;
		value*=a[pos+(ind-m)*p];
		value%=mod;
		haha2-=value;
		value*=a[pos+(ind-m)*p];
		value%=mod;
		haha3-=value;

		checker(pos+(ind-m+1)*p);
		//vec.pb(pos+(ind-m+1)*p)
		ind++;
	}
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
	
	cin>>n>>m>>p;
	int i;
	f(i,1,n+1){
		cin>>a[i];
	}    
	ll value;
	f(i,1,m+1){
		cin>>b[i];
		value=b[i];
		// ans4^=b[i];
		// ans5|=b[i];
		ans1+=value;
		value*=b[i];
		value%=mod;		
		ans2+=value;
		value*=b[i];
		value%=mod;		
		ans3+=value;
	}
	f(i,1,p+1){
		compute(i);
	}

    cout<<sumi<<endl;
    sort(vec.begin(),vec.end());
    rep(i,vec.size()){
    	cout<<vec[i]<<" ";
    }
}