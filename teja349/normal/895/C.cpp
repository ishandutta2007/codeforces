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
int pr[19]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
ll boo[1234];
ll a[123456];
ll two[123466];
int main(){
    std::ios::sync_with_stdio(false);
    ll i,j;
    ll n;
    map<int,ll> mapi,newsub,sub;
    cin>>n;
    rep(i,n){
    	cin>>a[i];
    }
    // rep(i,19){
    // 	haha[pr[i]]=i;
    // }
    ll wow,lol,val,val1;
    //cout<<pr[18]<<endl;
    two[0]=1;
    f(i,1,123456){
    	two[i]=2*two[i-1];
    	two[i]%=mod;
    }
    rep(i,n){
    	lol=0;
    	val=a[i];
    	wow=100;
    	//cout<<"dad"<<endl;
    	rep(j,19){
    		//cout<<pr[j]<<endl;
    		while(val%pr[j]==0){

    			wow=pr[j];
    			lol^=(1<<j);
    			val/=pr[j];
    		}


    	}
    	if(wow>35){
    		boo[wow]++;
    	}
    	else{
    		mapi[lol]++;
    	}
    }
    //return 0;
    map<int,ll>::iterator it,it1;
   	sub[0]=1;
    for(it=mapi.begin();it!=mapi.end();it++){
    	val=it->ss;
    	val1=it->ff;
    	for(it1=sub.begin();it1!=sub.end();it1++){
    		newsub[(it1->ff)^val1]+=(it1->ss)*(two[val-1]);
    		newsub[(it1->ff)^val1]%=mod;
    		newsub[(it1->ff)]+=(it1->ss)*(two[val-1]);
    		newsub[(it1->ff)]%=mod;
    	}
    	sub.clear();
    	for(it1=newsub.begin();it1!=newsub.end();it1++){
    		sub[it1->ff]=it1->ss;
    	}

    	newsub.clear();


    }
    ll ans;
    ans=sub[0];

    f(i,36,80){
    	if(!boo[i])
    		continue;
    	ans*=(two[boo[i]-1]);
    	ans%=mod;
    }
    ans*=(two[boo[100]]);
    ans%=mod;
    ans--;
    ans+=mod;
    ans%=mod;

    cout<<ans<<endl;

    return 0;  
    
}