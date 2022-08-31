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
int act[1234],lefi[1234];  
int match(string s1,string s2){
	int i;
	rep(i,s1.length()){
		if(s2[i]=='*' && act[s1[i]]==0)
			continue;
		if(s2[i]!=s1[i]){ 
			//cout<<i<<endl;
			return 0;}
	}
	return 1;
}
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    string s,str;

    int i;
    
    cin>>s;
    rep(i,n){
    	if(s[i]!='*')
    		act[s[i]]=1;
    }
    int m;
    cin>>m;
    int haha[400]={0};
    int j,cnt=0;
    i=0;
    rep(i,m){
    	
    	cin>>str;
    	if(!match(str,s))
    		continue;
    	cnt++;
    	rep(j,str.length()){
    		haha[str[j]]=1;
    	}
    	f(j,'a','z'+1){
    		//cout<<j<<endl;
    		if(haha[j])
    			lefi[j]++;
    		haha[j]=0;
    	}
    	
    }
    int ans=0;
    f(i,'a','z'+1){
    	if(act[i]) continue;
    	if(lefi[i]==cnt){
    		ans++;
    		//cout<<(char)i<<endl;
    	}
    }
    //cout<<lefi['b']<<endl;
    cout<<ans<<endl;
    return 0;  
    
}