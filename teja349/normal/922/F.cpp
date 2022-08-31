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
vii vec;
vector<vi > divis(312345);
int tot[312345],a[312345],n;
int relax(int val){

	int i,j;
	rep(i,divis[val].size()){
		//cout<<divis[val]
		tot[divis[val][i]]--;
	}
	for(j=val+val;j<=n;j+=val){
		tot[j]--;
	}
	//cout<<seti.size()<<"dummy"<<endl;
}
int main(){
    std::ios::sync_with_stdio(false);
    int k;
    int i,j,ans=0;
    cin>>n>>k;
    for(i=1;i<=n;i++){
    	for(j=i+i;j<=n;j+=i){
    		divis[j].pb(i);
    		tot[j]++;
    		ans++;
    		tot[i]++;
    	}
    }
    if(ans<k){
    	cout<<"No"<<endl;
    	return 0;
    }
    k=ans-k;
    set<pii>::iterator it;
    cout<<"Yes"<<endl;
    f(i,2,n+1){
    	vec.pb(mp(tot[i],i));
    }
    sort(all(vec));
   // cout<<k<<endl;
    //cout<<bac[6]+forw[6]<<endl;
   	i=vec.size()-1;
   	while(k>0){
   		if(tot[vec[i].ss]<=k){
   			//cout<<k<<endl;
   			//cout<<tot[vec[i].ss]<<" "<<vec[i].ss<<endl;
   			a[i]=1;
   			k-=tot[vec[i].ss];
   			relax(vec[i].ss);
   			
   		}
   		i--;
   	}
   	//cout<<k<<endl;
   	int cnt=0;
   	rep(i,vec.size()){
   		if(!a[i])
   			cnt++;
   	}
   	cout<<cnt+1<<endl;
   	cout<<1<<" ";
   	f(j,0,vec.size()){
   		if(!a[j])
   			cout<<vec[j].ss<<" ";
   	}
    return 0;  
    
}