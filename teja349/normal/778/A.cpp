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
string s,p;
int a[212345];
int check(int val){
	string stre=s,swe="";
	int i,j=0;
	rep(i,val){
		stre[a[i]]='1';

	}
	rep(i,stre.length()){
		if(stre[i]!='1')
			swe+=stre[i];
	}
	i=0;
	while(i<swe.length()){
		if(swe[i]==p[j]){
			j++;
		}
		i++;
		if(j==p.length())
			break;
	}
	if(j==p.length())
		return 1;
	else
		return 0;
}
int main(){
	std::ios::sync_with_stdio(false);
	//string s,p;
	cin>>s>>p;
	int i;
	rep(i,s.length()){
		cin>>a[i];
		a[i]--;
	}
	int low=0;
	int high=s.length();
	int mid=(low+high)/2;
	int ans=0;
	while(low<=high){
		if(check(mid)){
			ans=mid;
			low=mid+1;
		}
		else{
			high=mid-1;
		}
		mid=(low+high)/2;

	}
	cout<<ans<<endl;

}