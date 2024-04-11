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
ll a[1234567],b[1234567];

int main(){
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
   	ll bigg=0,sml=0,haha=0,lol=0,mini,ans;
    int i,j;
    rep(i,n){
    	cin>>a[i];
    }
    //sort(a,a+n);
    j=0;
    fd(i,n-1,0){
    	b[j++]=a[i];
    }
    rep(i,n-1){
    	if(i%m==0){
    		bigg+=b[i];
    		//cout<<i<<" "<<b[i]<<endl;
    		haha++;
    	}
    }
    mini=bigg-a[0]*haha;
   // cout<<bigg<<endl;
    j=n-2;
    f(i,1,n){
    	
    	if(j%m==0){
    		bigg-=a[i];
    		//cout<<"Dad";
    		haha--;
    	}
    	if((i-1)%m==0){
    		sml+=a[i-1];
    		lol++;
    	}
    	j--;
    	ans=bigg-a[i]*haha;
    	ans+=a[i]*lol-sml;
    	//cout<<sml<<endl;
    	mini=min(mini,ans);
    }
    cout<<2*mini<<endl;

    return 0;      

}