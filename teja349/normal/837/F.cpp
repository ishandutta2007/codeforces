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
ll n,k;
ll a[212345],iinf;

ll brute(){
	ll i;
	rep(i,n){
		if(a[i]>=k){
			return 0; 
		}
	}
	ll co=0;
	while(1){
		co++;
		a[0]=a[0];
		f(i,1,n){
			a[i]=a[i-1]+a[i];
			if(a[i]>=k){
				return co;
			}
		}
	}

}
ll calc(ll i){
	return i*(i+1)/2*a[0]+i*a[1]+a[2];
}
ll binsear(){
	ll low=1;
	ll high=(2*iinf/a[0]);
	high=sqrt(high);
	high+=3;
	if(a[1]!=0){
		high=min(high,iinf/a[1]+2);
	}
	ll ans=0;
	ll mid;
	while(low<=high){
		mid=(high+low)/2;
		if(calc(mid)>=k){
			ans=mid;
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	return ans;
}
int main(){
    std::ios::sync_with_stdio(false);
    //int n,k;
    iinf=inf;
    iinf*=inf;
    ll val,flag=1,j=0,i;
    cin>>n>>k;

    rep(i,n){
    	cin>>val;
    	if(val>=k){
    		cout<<0<<endl;
    		return 0;
    	}
    	if(val==0 && flag)
    		continue;
    	a[j++]=val;
    	flag=0;
    }
    n=j;
    if(n>=4){
    	cout<<brute()<<endl;
    	return 0;
    }
    if(n==2){
    	k-=a[1];

    	val=k/a[0];
    	if(a[1]%a[0]){
    		val++;
    	}
    	cout<<val<<endl;
    	return 0;
    }
    else{
    	cout<<binsear()<<endl;
    }




    return 0;      

}