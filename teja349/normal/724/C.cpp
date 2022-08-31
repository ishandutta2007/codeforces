
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
#define inf 1000*1000*1000+5
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod 1000*1000*1000+7

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

int main(){
	ll n,m,q,gcd1,m1,n1,invn1,invm1,ans=inf;
	cin>>n>>m;
	cin>>q;
	if(m>n)
		gcd1=gcd(m,n);
	else
		gcd1=gcd(n,m);
	ll lcm=m*n/gcd1;
	n1 = (n/gcd1);
	m1 = (m/gcd1);
	if(m1<n1){
		extend_gcd(n1,m1,invn1,invm1);
	}
	else
		extend_gcd(m1,n1,invm1,invn1);
	invn1+=m;
	invn1%=m;

	invm1+=n;
	invm1%=n;
	// if(invn1<0 || invm1<0)
	// 	cout<<"hii";
	//cout<<invm1<<"  "<<invn1;
	while(q--){
		ans=inf;
		ans*=inf;
		//cout<<ans;
		ll check=ans;
		ll a,b;
		cin>>a>>b;
		// if((abs(b-a))%gcd1!=0)
		// {
		// 	cout<<-1<<endl;
		// 	continue;
		// }
		ll t;
		t=a*m1*invm1+b*n1*invn1;
		t%=lcm;
		t+=lcm;
		t%=lcm;
		if((t/n)%2==0 && (t/m)%2==0 && (abs(b-a))%gcd1==0)
		{	
			//cout<<"hii1"<<endl;
			if(ans>t)
				ans=t;		
			
		}

		t=(n-a)*m1*invm1+(m-b)*n1*invn1;
		t%=lcm;
		t+=lcm;
		t%=lcm;
		if((t/n)%2==1 && (t/m)%2==1 && (abs(n-b-n+a))%gcd1==0)
		{
			//cout<<"hii2"<<endl;
			if(ans>t)
				ans=t;
		}
		//cout<<(n-a)*m1*invm1<<":    "<<b*n1*invn1; 
		t=(n-a)*m1*invm1+b*n1*invn1;
		//cout<<t<<endl;
		t%=lcm;
		t+=lcm;
		t%=lcm;
		//cout<<(t-n+a)%n<<"hii"<<endl;
		if((t/n)%2==1 && (t/m)%2==0 && (abs(b-n+a))%gcd1==0)
		{
			//cout<<"hii3"<<endl;
			if(ans>t)
				ans=t;
		}
		t=a*m1*invm1+(m-b)*n1*invn1;
		t%=lcm;
		t+=lcm;
		t%=lcm;

		if((t/n)%2==0 && (t/m)%2==1 && (abs(n-b-a))%gcd1==0)
		{
			//cout<<"hii4"<<endl;
			if(ans>t)
				ans=t;
		}
		if(ans==check)
			cout<<-1<<endl;
		else
			cout<<ans<<endl;

	}

}