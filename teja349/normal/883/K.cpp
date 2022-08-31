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
ll l[223456],r[212345],s[212345],g[212345];

int calc(int i){
	l[i]=max(s[i],l[i-1]-1);
	r[i]=min(r[i-1]+1,g[i]);
	//cout<<l[i]<<" "<<r[i]<<endl;
	if(l[i]>r[i]){

		cout<<-1<<endl;
		exit(0);
	}
}
ll boo[223456];
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i;
    ll sumi=0,ans=0;
    rep(i,n){
    	cin>>s[i]>>g[i];
    	g[i]+=s[i];
    	sumi+=s[i];
    }
    l[0]=s[0];
    r[0]=g[0];
    f(i,1,n){
    	calc(i);
    }	
    ll prev=r[n-1];
    ans+=prev;
    boo[n-1]=prev;
    fd(i,n-2,0){
    	if(r[i]>prev){
    		ans+=prev+1;
    		prev++;
    	}
    	else if(r[i]==prev){
    		ans+=prev;
    	}
    	else{
    		prev--;
    		ans+=prev;
    	}
    	boo[i]=prev;
    }
    cout<<ans-sumi<<endl;
    rep(i,n){
    	cout<<boo[i]<<" ";
    }
    return 0;  
    
}