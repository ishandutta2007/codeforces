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
#define flush fflush(stdout) 
#define primeDEN 727999983
//cout<<fixed<<setprecision(15)<<ans;
 
template <typename T>
void printvec(vector<T>& vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}


int a[1234],b[1234];
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i=0;
    int vol=0,one=0;
    rep(i,n){
    	cin>>b[i];
    	a[b[i]]++;
    }
    rep(i,200){
    	if(a[i]==2){
    		continue;
    	}
    	else if(a[i]>2){
    		vol++;
    	}
    	else if(a[i]==1){
    		one++;
    	}
    }
    if(vol==0 && one%2){
    	cout<<"NO"<<endl;
    	return 0;
    }
    cout<<"YES"<<endl;
    if(one%2){
    	vol=1;
    }
    else{
    	vol=0;
    }
    string s="";
    int haha;
    haha=one/2;
    haha+=vol;
    rep(i,n){
    	s+="C";
    }
    //cout<<haha<<endl;
    rep(i,n){
    	if(a[b[i]]==1 && haha){
    		s[i]='A';
    		haha--;
    	}
    }
    haha=one/2;
    haha+=vol;
    rep(i,n){
    	if(a[b[i]]==1 && s[i]=='C'){
    		s[i]='B';
    	}
    	if(vol && a[b[i]]>2){
    		s[i]='B';
    		vol=0;
    	}
    }
    rep(i,n){
    	if(s[i]=='C'){
    		s[i]='A';
    	}
    }
    cout<<s<<endl;

    return 0;   
}