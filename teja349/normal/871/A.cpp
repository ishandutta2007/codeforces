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
int pr[12345],ans[12345];
vi vec;
int main(){
    std::ios::sync_with_stdio(false);
    int i,j;
    //vec.pb(1);
    for(i=2;i<200;i++){
    	if(pr[i])
    		continue;
    	//vec.pb(pr[i]);
    	for(j=i*i;j<=200;j+=i){
    		pr[j]=1;
    	}
    }
    f(i,1,180){
    	if(pr[i]==1){
    		vec.pb(i);
    	}
    }
    ans[1]=-1;
    ans[2]=-1;
    ans[3]=-1;
    ans[0]=0;
   f(i,4,150){
   		ans[i]=-1;
   		rep(j,vec.size()){
   			if(i<vec[j])
   				break;
   			if(ans[i-vec[j]]!=-1)
   				ans[i]=max(ans[i],1+ans[i-vec[j]]);
   		}
   }
   int q;
   cin>>q;
   ll val,haha;
   while(q--){
   		cin>>val;
   		if(val<120){
   			cout<<ans[val]<<endl;
   		}
   		else{
   			val-=100;
   			haha=val/4;
   			val=100+val%4;
   			haha+=ans[val];
   			cout<<haha<<endl;
   		}
   }

    return 0;  
    
}