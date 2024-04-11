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
	std::ios::sync_with_stdio(false);
	string s;
	int i,k;
	cin>>s;
	cin>>k;
	int val1=0,val2=0,flag=0,counti=0;

	int j=s.length();
	j--;
	rep(i,s.length()){
		if(s[i]!='0')
			val1++;
	}
	fd(i,k-1,0){
		
		if(s[j]!='0'){
			counti++;
			i++;
		}
		else{
			flag++;
		}
		j--;
		if(j<0)
			break;
	}

	if(counti<val1)
		cout<<counti<<endl;
	else{
		//cout<<"dsasd";
		cout<<(int)(s.length())-1<<endl;
	}
	


}