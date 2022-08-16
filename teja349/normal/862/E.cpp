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
ll a[123456],b[123456],ans[123456],haha[123456];
int main(){
    std::ios::sync_with_stdio(false);
    int n,m,q,l,r,x;
    cin>>n>>m>>q;
    int i,j;
    ll sumi=0;
    rep(i,n){
    	cin>>a[i];
    	if(i%2==0)
    		sumi+=a[i];
    	else
    		sumi-=a[i];
    }

    rep(i,m){
    	cin>>b[i];
    }
    fd(i,m-1,0){
    	ans[i]=b[i]-ans[i+1];
    }
    vl vec;
    rep(i,m-n+1){
    	if(n%2)
    		haha[i]=ans[i]+ans[i+n];
    	else
    		haha[i]=ans[i]-ans[i+n];
    	haha[i]=sumi-haha[i];
    	//cout<<haha[i]<<"dasdas"<<endl;
    	vec.pb(haha[i]);
    }
    vl::iterator it1,it2;
    sort(vec.begin(),vec.end());
    it1=lower_bound(vec.begin(),vec.end(),0);
    if(it1==vec.begin()){
    	cout<<*it1<<endl;
    }
    else{
    	//cout<<*it1<<"dasdasds";
    	it2=it1--;
    	if(it2!=vec.end())
    		cout<<min(*it2,abs(*it1))<<endl;
    	else
    		cout<<abs(*it1)<<endl;
    }
    sumi=0;
    while(q--){
    	cin>>l>>r>>x;
    	l--;
    	r--;
    	if((l+r)%2==0){
    		if(l%2==0)
    			sumi+=x;
    		else
    			sumi-=x;
    	}
    	//cout<<sumi<<"======";
    	it1=lower_bound(vec.begin(),vec.end(),-1*sumi);
	    if(it1==vec.begin()){
	    	cout<<sumi+*it1<<endl;
	    }
	    else{
	    	//cout<<vec.size()<<"--------";
	    	it2=it1--;
	    	if(it2!=vec.end())
	    		cout<<min(*it2+sumi,abs(*it1+sumi))<<endl;
	    	else{
	    		cout<<abs(*it1+sumi)<<endl;
	    	}
	    }
    }
    return 0;

    

    return 0;  
    
}