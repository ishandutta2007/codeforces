
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

int main(){
	int n,i;
	cin>>n;
	string s;
	cin>>s;
	rep(i,n-2){
		int flag=0;
		if(s.at(i)=='o'&&s.at(i+1)=='g'&&s.at(i+2)=='o'){

			s.erase(i,3);
			n-=2;
			s.insert(s.begin()+i,'*');
			flag=1;
		}
		//cout<<s;
		while(i<n-2&& s.at(i)=='*'&& s.at(i+1)=='g'&& s.at(i+2)=='o'){
			//cout<<s;
			s.erase(i,3);
			n-=2;
			s.insert(s.begin()+i,'*');
		}
		if(flag==1){
			s.insert(s.begin()+i,'*');
			s.insert(s.begin()+i,'*');
			n+=2;
		}
		//cout<<s<<endl;
	}
	cout<<s<<endl;
}