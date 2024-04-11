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
int nexti[2234567];
string s="";
int last;
string str;
int findnexti(int val){
	if(nexti[val]==-1)
		return val;
	nexti[val]=findnexti(nexti[val]);
	return nexti[val];
}
int add(int val){
	int i=0;
	int val1=val;
	val=findnexti(val);
	i=val-val1;
	while(i<str.length()){
		last=max(last,val);
		s[val]=str[i];
		//cout<<val1<<endl;
		nexti[val]=val+1;
		i++;
		val++;
		val=findnexti(val);
		i=val-val1;
	}
	return 0;
} 
//string s;
int main(){
    std::ios::sync_with_stdio(false);
    int i,j;
     rep(i,2123456){
     	s+='*';
     }
     rep(i,2123456){
     	nexti[i]=-1;
     }
     //return 0;
     last=0;
     int n;
     cin>>n;
     int siz,val;
     rep(i,n){
     	cin>>str;
     	cin>>siz;
     	rep(j,siz){
     		cin>>val;
     		add(val-1);
     	}
     }
     rep(i,last+1){
     	if(s[i]=='*'){
     		cout<<"a";
     	}
     	else{
     		cout<<s[i];
     	}
     }
     cout<<endl;


    
}