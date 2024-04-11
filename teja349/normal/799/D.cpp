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
int b[100];
map<pair<int,pii >,int > mapi;
int solved(int n,int lol,int haha){
	int aa,val;
	if(n==-1){
		if(lol*haha==1){
			return 1;
		}
		else{
			return 0;
		}
	}
	if(mapi.find(mp(n,mp(max(lol,haha),min(lol,haha))))!=mapi.end()){
		return mapi[mp(n,mp(max(lol,haha),min(lol,haha)))];
	}
	if(lol*haha==1){
		return 1;
	}
	aa=lol/b[n];
    if(lol%b[n]!=0){
    	aa++;
    }
    val=solved(n-1,aa,haha);
    aa=haha/b[n];
    if(haha%b[n]!=0){
    	aa++;
    }
     val=max(val,solved(n-1,aa,lol));
     mapi[mp(n,mp(max(lol,haha),min(lol,haha)))]=val;
     return val;
}
int arr[123456];
int main(){
    std::ios::sync_with_stdio(false); 
    int a,br,h,w,n;
    cin>>a>>br>>h>>w>>n;
    int i,lol,haha,ans=inf;
    rep(i,n){
    	cin>>arr[i];
    }
    sort(arr,arr+n);
    int j=0;
    fd(i,n-1,max(0,n-35)){
    	b[j]=arr[i];
    	j++;
    }
    lol=a/h;
    if(a%h!=0){
    	lol++;
    }
    haha=br/w;
    if(br%w!=0){
    	haha++;
    }
    if(lol*haha==1){
    	cout<<0<<endl;
    	return 0;
    }
    rep(i,j){
    	if(solved(i,lol,haha)){
    		ans=min(ans,i);
    		break;
    	}
    }
    lol=br/h;
    if(br%h!=0){
    	lol++;
    }
    haha=a/w;
    if(a%w!=0){
    	haha++;
    }
    if(lol*haha==1)
    {
    	cout<<0<<endl;
    	return 0;
    }
    //cout<<lol<<" "<<haha<<endl;
    rep(i,j){
    	if(solved(i,lol,haha)){
    		ans=min(ans,i);
    		break;
    	}
    }
    if(ans==inf)
    {
    	cout<<-1<<endl;
    }
    else{
    	cout<<ans+1<<endl;
    }


}