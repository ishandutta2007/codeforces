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

//std::ios::sync_with_stdio(false);   
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
int main(){
    std::ios::sync_with_stdio(false);
    ll aa,bb,t,n,m,x,y,vx,vy;
    cin>>n>>m>>x>>y>>vx>>vy;
    if(vy==0){
    	if(y==0 || y==m){
    		if(vx==1){
    			cout<<n<<" "<<y<<endl;
    		}
    		else{
    			cout<<0<<" "<<y<<endl;
    		}
    	}
    	else{
    		cout<<-1<<endl;
    		
    	}
    	return 0;
    }
    if(vx==0){
    	if(x==0 || x==n){
    		if(vy==1){
    			cout<<x<<" "<<m<<endl;
    		}
    		else{
    			cout<<x<<" "<<0<<endl;
    		}
    	}
    	else{
    		cout<<-1<<endl;
    		
    	}
    	return 0;
    }
    ll a,b,wow,gg,aaa,k;
    a=n;
    b=m;
    if(vx==-1){
    	wow=x+vy*y;
    	gg=__gcd(a,b);
    	if(wow%gg!=0){
    		cout<<-1<<endl;
    		return 0;
    	}
    	extend_gcd(a,b,aa,bb);
    	aaa=aa*-1;
    	aaa*=wow;
    	k=aaa/b;
    	k+=2;
    	while((k)*b>aaa){
    		k--;
    	}
    	n=aa*wow/gg+b*k/gg;
    	t=x-n*a;
    	x-=t;
    	y+=vy*t;
    	if(x%(2*a)){
    		cout<<a<<" ";
    	}
    	else{
    		cout<<0<<" ";
    	}
    	if(y%(2*b)){
    		cout<<b<<" ";
    	}
    	else{
    		cout<<0<<" ";
    	}
    }
    else{
    	wow=x-vy*y;
    	gg=__gcd(a,b);
    	if(wow%gg!=0){
    		cout<<-1<<endl;
    		return 0;
    	}
    	extend_gcd(a,b,aa,bb);
    	aaa=aa*-1;
    	aaa*=wow;
    	k=aaa/b;
    	k+=2;
    	while((k)*b>aaa){
    		k--;
    	}
    	k++;
    	n=aa*wow/gg+b*k/gg;
    	t=n*a-x;
    	x+=t;
    	y+=vy*t;
    	if(x%(2*a)){
    		cout<<a<<" ";
    	}
    	else{
    		cout<<0<<" ";
    	}
    	if(y%(2*b)){
    		cout<<b<<" ";
    	}
    	else{
    		cout<<0<<" ";
    	}
    }

    return 0;  
    
}