
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
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx


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
int main(){
	int n,a=0,c=0,g=0,t=0,i;
	cin>>n;
	string s;
	cin>>s;
	if(n%4!=0){
		cout<<"===";
		return 0;
	}
	int val=n/4;
	
	rep(i,n){
		if(s[i]=='A')
			a++;
		else if(s[i]=='G')
			g++;
		else if(s[i]=='T')
			t++;
		else if(s[i]=='C')
			c++;

	}
	a=val-a;
	c=val-c;
	g=val-g;
	t=val-t;
	if(a<0||g<0||c<0||t<0){
		cout<<"===";
		return 0;
	}
	i=0;
	while(a!=0){
		if(s[i]=='?'){
			s[i]='A';
			a--;
		}
		i++;
	}
	a=c;
	while(a!=0){
		if(s[i]=='?'){
			s[i]='C';
			a--;
		}
		i++;
	}
	a=t;
	while(a!=0){
		if(s[i]=='?'){
			s[i]='T';
			a--;
		}
		i++;
	}
	a=g;
	while(a!=0){
		if(s[i]=='?'){
			s[i]='G';
			a--;
		}
		i++;
	}
	cout<<s<<endl;
	return 0;
}