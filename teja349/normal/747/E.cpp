
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
vector< vii > vec(600100);  
string stre;

int IIt=0;
int form_tree(int level){
	int i,child;
	
	
	int intial=IIt;
	while(stre[IIt]!=','){
		//s=s+stre[IIt];
		IIt++;

	}
	vec[level].pb(mp(intial,IIt-intial));
	//string s=s.substr(intial,IIt-initial);
	//cout<<s<<"    bsdsdf"<<endl;
	i=0;
	char chili[100];
	
	IIt++;
	while(stre[IIt]!=','&& stre[IIt]!='\0'){
		chili[i++]=stre[IIt];
		IIt++;

	}
	
	if(IIt!=stre.length())
		IIt++;
	chili[i]='\0';
	//cout<<chili<<"dasads"<<endl;
	 child=atoi(chili);
	//cin>>child;
	
	
	//cout<<child<<endl;
	rep(i,child){
		form_tree(level+1);
	}
	return 0;

}

int main(){
	std::ios::sync_with_stdio(false);
	//string s;
	int i,j,maxi=0;
	
	cin>>stre;
	
	form_tree(0);
	

	
	while(IIt!=stre.length()){
		
		form_tree(0);
	}
	while(vec[maxi].size()!=0){
		maxi++;
	}
	cout<<maxi<<endl;
	rep(i,maxi){
		rep(j,vec[i].size()){
			cout<<stre.substr(vec[i][j].ff,vec[i][j].ss)<<" ";
		}
		cout<<endl;
	}
}