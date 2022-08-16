
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
int lps[1000002];
int computelps(string s){
	lps[0]=0;
	int i=1;
	int j=0;
	while(i<s.length()){
		if(s[i]==s[j]){
			lps[i]=j+1;
			i++;
			j++;
		}
		else{
			if(j!=0){
				j=lps[j-1];
			}
			else{
				lps[i]=0;
				i++;
			}
		}
	}
	return 0;
}

int main(){
	std::ios::sync_with_stdio(false);   
	string s;
	cin>>s;
	int i,maxi=0;
	map<int,int> mapi;
	computelps(s);
	i=s.length();
	while(i!=0){

		mapi[lps[i-1]]=1;
		i=lps[i-1];
	}
	//cout<<"hii";
	fflush(stdout);
	rep(i,s.length()-1){
		if(mapi.find(lps[i])!=mapi.end()){
			if(maxi<lps[i]){
				maxi=lps[i];

			}

		}

	}
	if(maxi!=0){
		rep(i,maxi){
			cout<<s[i];
		}
	}
	else{
		cout<<"Just a legend";
	}
}