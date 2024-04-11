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
ll inv[1000003],mult[1000003],invmult[1000003];
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
	if(n<r)
		return 0;
	ll ans=1;
	ans*=mult[n];
	ans%=mod;
	ans*=invmult[r];
	ans%=mod;
	ans*=invmult[n-r];
	ans%=mod;
	return ans;
}

ll initcombi(){
	int i;
	f(i,1,1000001){
		ll x,y;
		ll val=extend_gcd(mod,i,x,y);
		if(y>0)
			inv[i]=y%mod;
		else{
				inv[i]=(y+mod)%mod;
		}
	}
	mult[0]=1;
	f(i,1,1000001){
		mult[i]=mult[i-1]*i;
		mult[i]%=mod;
	}
	invmult[0]=1;
	f(i,1,1000001){
		invmult[i]=invmult[i-1]*inv[i];
		invmult[i]%=mod;
	}
	return 0;
}


// do initcombi();
ll haha[123456];
int main(){
    std::ios::sync_with_stdio(false);
    initcombi();
    string a,b,aa="",bb="";
    cin>>a>>b;
    int flag=0,i,j;
    rep(i,a.length()){
    	if(flag){
    		aa+=a[i];
    		bb+=b[i];
    	}
    	else{
    		if(a[i]!=b[i]){
    			flag=1;
    			aa+=a[i];
    			bb+=b[i];
    		}
    	}

    }
    a=aa;
    b=bb;
    rep(i,a.length()){
    	haha[a[i]]++;
    }
    ll len=a.length();
    len--;
    ll ans2=0,ans=0,ans1=mult[len];
    //cout<<ans1<<endl;
	f(j,'a','z'+1){
		ans1*=invmult[haha[j]];
		ans1%=mod;
	}
	//cout<<ans1<<endl;
    f(i,a[0]+1,b[0]){
    	ans2+=haha[i];
   	}

   	ans2*=ans1;
   	ans2%=mod;
   	ans+=ans2;
   	ans%=mod;
   	ans1%=mod;

   //cout<<ans<<endl;
   ll 	biggie=ans1;
   	ans1*=haha[a[0]];
   	ans1%=mod;
   	haha[a[0]]--;

   	f(i,1,a.length()){
   		//haha[a[i]]--;
   		ans2=0;
   		ans1*=inv[len];
   		len--;
   		ans1%=mod;
   		f(j,a[i]+1,'z'+1){
   			ans2+=haha[j];
   		}
   		//cout<<ans2<<"daads"<<endl;
   		ans2*=ans1;
   		ans2%=mod;
   		ans+=ans2;
   		ans%=mod;
   		ans1*=haha[a[i]];
   		ans1%=mod;
   		haha[a[i]]--;
   		
   		ans1%=mod;


   	}
   	//cout<<ans<<endl;
   	len=a.length();
   	len--;
   	ans1=biggie;
   	rep(i,1000){
   		haha[i]=0;
   	}
   	rep(i,a.length()){
   		haha[a[i]]++;
   	}
   	ans1*=haha[b[0]];
   	ans1%=mod;
   	haha[b[0]]--;
   	if(haha[b[0]]<0)
   	{
   		cout<<ans<<endl;
   		return 0;
   	}
   	f(i,1,b.length()){
   		//haha[a[i]]--;
   		ans1*=inv[len];
   		len--;
   		ans1%=mod;
   		ans2=0;
   		f(j,'a',b[i]){
   			ans2+=haha[j];
   		}
   		ans2*=ans1;
   		ans2%=mod;
   		ans+=ans2;
   		ans%=mod;
   		if(haha[b[i]]==0)
   			break;
   		ans1*=haha[b[i]];
   		ans1%=mod;
   		haha[b[i]]--;
   		
   		


   	}

   	cout<<ans<<endl;
    return 0;  
    
}