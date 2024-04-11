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
#define pqueue priority_queue< pll >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);   
ll s;
ll arr[123456],a[123456],b[123456];
vll vec1,vec2;

int main(){
    std::ios::sync_with_stdio(false);
    ll n;
    cin>>n>>s;
    pll papa;
    int i;
    ll ans=0;
    //pqueue pq;
    ll slice1=0,slice2=0;
    ll haha=0;
    rep(i,n){
    	cin>>arr[i]>>a[i]>>b[i];
    	ans+=arr[i];
    	haha+=a[i]*arr[i];
    	if(b[i]-a[i]>=0){
    		slice2+=arr[i];
    		vec1.pb(mp(b[i]-a[i],arr[i]));
    	}
    	else{
    		slice1+=arr[i];
    		vec2.pb(mp(b[i]-a[i],arr[i]));
    	}
    }
    ll pizz=ans/s;
    if(ans%s)
    	pizz++;
    sort(vec1.begin(),vec1.end());
    sort(vec2.begin(),vec2.end());
    ll pizz1=slice1/s;
    ll pizz2=slice2/s;
    slice1=pizz1*s;
    ll sumi1=0,sumi2=0;
    slice2=pizz2*s;
    swap(slice1,slice2);
    fd(i,vec1.size()-1,0){
    	if(slice1>vec1[i].ss){
    		haha+=vec1[i].ss*vec1[i].ff;
    		slice1-=vec1[i].ss;
    		//cout<<vec1[i].ss<<"das"<<endl;
    	}
    	else{
    		//cout<<slice1<<"da"<<endl;
    		haha+=slice1*vec1[i].ff;
    		vec1[i].ss-=slice1;
    		slice1=0;
    		while(i>=0){
    			//cout<<vec1[i].ss<<" vv"<<vec1[i].ff<<endl;
    			sumi1+=vec1[i].ff*vec1[i].ss;
    			i--;
    			
    		}
    		break;
    	}

    }
    rep(i,vec2.size()){
    	if(slice2>vec2[i].ss){
    		
    		slice2-=vec2[i].ss;
    		continue;
    	}
    	else{
    		//haha+=slice1*vec1[i].ff;
    		vec2[i].ss-=slice2;

    		while(i<vec2.size()){
    			//cout<<vec2[i].ss<<" vv"<<vec2[i].ff<<endl;
    			sumi2+=vec2[i].ff*vec2[i].ss;
    			i++;
    			
    		}
    		break;
    	}
    }
    if(pizz==pizz1+pizz2){
    	cout<<haha<<endl;
    }
    else if(pizz==pizz1+pizz2+1){
    	cout<<max(haha+sumi2+sumi1,haha)<<endl;
    }
    else{
    	cout<<haha+sumi1<<endl;
    }

    
    
    return 0;  
    
}