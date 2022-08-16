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
#include <sstream>
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
int counti=1; 
unordered_map<string ,int> mapi;
string var[6000];
string maxi,mini;
vector< vector<string> > equa(6000);
int n,m;
int haha[6000],haha1[6000]; 
int solve(int ind){
	int i,answ=0,ans=0;
	int val1,val2,val3,val4;
	rep(i,n){
		int value=mapi[var[i]];
		if(equa[i].size()==1){
			haha[value]=equa[i][0][ind]-'0';
			haha1[value]=haha[value];
			answ+=haha[value];
			ans+=haha1[value];
		}
		else if(equa[i].size()==3){
			if(equa[i][0]=="?"){
				val1=1;
				val3=0;
			}
			else{
				val1=haha[mapi[equa[i][0]]];
				val3=haha1[mapi[equa[i][0]]];
			}
			if(equa[i][2]=="?"){
				val2=1;
				val4=0;
			}
			else{
				val2=haha[mapi[equa[i][2]]];
				val4=haha1[mapi[equa[i][2]]];
			}
			if(equa[i][1]=="AND"){
				haha[value]=val1&val2;
				haha1[value]=val3&val4;
			}
			else if(equa[i][1]=="OR"){
				haha[value]=val1|val2;
				haha1[value]=val3|val4;
			}
			else if(equa[i][1]=="XOR"){
				haha[value]=val1^val2;
				haha1[value]=val3^val4;
			}
			//cout<<haha[mapi[var[i]]]<<"  daadsas"<<endl;
			answ+=haha[value];
			ans+=haha1[value];
		}

	}
	
	//cout<<ans<<" "<<answ<<endl;
	if(answ==ans){
		maxi[ind]='0';
		mini[ind]='0';
	}
	else{
		if(answ>ans){
			maxi[ind]='1';
			mini[ind]='0';
		}
		else{
			maxi[ind]='0';
			mini[ind]='1';
		}
	}

}
int main(){
	std::ios::sync_with_stdio(false);

	cin>>n>>m;
	string stre,s1;
	maxi="";
	mini="";
	getline(cin,stre);
	
	int i;
	string dumy;
	rep(i,m){
		maxi+='1';
	}
	rep(i,n){
		stringstream SS;
		getline(cin,stre);
		SS<<stre;
		SS>>var[i];
		//cout<<var[i]<<" fsd "<<endl;
		SS>>dumy;
		//cout<<dumy<<endl;
		mapi[var[i]]=counti++;
		while(SS){

		     //s1[i][j].erase(); // to remove all characters from s1.

		     SS>>s1;
		    
		     if(SS){
		     	// cout<<s1<<"  ";
		     	 equa[i].pb(s1);
		     }
		     
		 	//cout << s1 << endl;
		 }
		// cout<<equa[i].size()<<endl;

		//SS.str(""); 
		//cout<<equa[i].size()<<"  size "<<endl;

	}
	mini=maxi;
	rep(i,m){
		solve(i);
	}
	cout<<mini<<endl;
	cout<<maxi<<endl;

}