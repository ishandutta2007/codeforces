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
ll one[123],zero[123],a[212345],b[212345],c[212345],n;

int process(ll val){
	int i=30;
	while(i>=0){
		if(val&(1<<i)){
			one[i]++;
		}
		else{
			zero[i]++;
		}
		i--;
	}
	return 0;
}
ll compute(int ind){
	int i=30;
	ll sumi=0;
	while(i>=0){
		if(a[ind]&(1<<i)){
			sumi+=(1LL<<i)*zero[i];
		}
		else{
			sumi+=(1LL<<i)*one[i];
		}
		i--;
	}
	return sumi;


}
int checkans(){
	int i;
	rep(i,n){
		process(a[i]);
	}
	rep(i,n){
		ll val=c[i]-b[i];
		if(compute(i)!=val){
			cout<<-1<<endl;
			exit(0);
		}
	}
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
   // int n;
    cin>>n;
    ll i,sumi=0;
    rep(i,n){
    	cin>>b[i];
    	sumi+=b[i];
    }
    rep(i,n){
    	cin>>c[i];
    	if(c[i]<b[i]){
    		cout<<-1<<endl;
    		return 0;
    	}
    	sumi+=c[i];
    }
    if(sumi%2==0){
    	sumi/=2;
    }
    else{
    	cout<<-1<<endl;
    	return 0;
    }
    if(sumi%n==0){
    	sumi/=n;
    }
    else{
    	cout<<-1<<endl;
    	return 0;
    }
    rep(i,n){
    	a[i]=(b[i]+c[i]-sumi);
    	if(a[i]<0 || a[i]%n){
    		cout<<-1<<endl;
    		return 0;
    	}
    	a[i]/=n;
    	if(a[i]>c[i]){
    		cout<<-1<<endl;
    		return 0;
    	}

    }
    checkans();
    rep(i,n){
    	cout<<a[i]<<" ";
    }


    return 0;      

}