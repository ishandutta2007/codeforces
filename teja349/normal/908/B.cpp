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
string s[100];
pii wow[10];
int arr[100];
int jj,n,m;
string haha;
int invalid(pii st){
	if(st.ff<0 || st.ff>=n || st.ss<0 || st.ss>=m)
		return 1;
	if(s[st.ff][st.ss]=='#')
		return 1;
	return 0;
} 
int dfs(pii st,int pos){
	//cout<<st.ff<<" "<<st.ss<<endl;
	if(pos==jj){

		if(s[st.ff][st.ss]=='E')
			return 1;
		return 0;
	}
	st.ff+=wow[arr[haha[pos]-'0']].ff;
	st.ss+=wow[arr[haha[pos]-'0']].ss;
	if(invalid(st))
		return 0;
	if(s[st.ff][st.ss]=='E')
		return 1;
	return dfs(st,pos+1);
}
int main(){
    std::ios::sync_with_stdio(false);
    //int n,m;
    cin>>n>>m;
    int i,j;
    rep(i,n){
    	cin>>s[i];
    }
    pii st;
    rep(i,n){
    	rep(j,m){
    		if(s[i][j]=='S')
    			st=mp(i,j);
    	}
    }

    cin>>haha;
    jj=haha.size();
    rep(i,4){
    	arr[i]=i;
    }
    wow[0]=mp(1,0);
    wow[1]=mp(0,-1);
    wow[2]=mp(-1,0);
    wow[3]=mp(0,1);
    int ans=0;
    while(1){
    	if(dfs(st,0))
    		ans++;
    	//return 0;
    	if(!next_permutation(arr,arr+4))
    		break;
    }
    cout<<ans<<endl;
    return 0;  
    
}