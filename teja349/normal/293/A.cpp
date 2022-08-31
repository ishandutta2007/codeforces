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
string sw,s1;
int main(){
    std::ios::sync_with_stdio(false);
	int n;
	cin>>n;
	cin>>sw>>s1;
	int i,com=0,f=0,s=0;
	rep(i,2*n){

		if(sw[i] == '1' && s1[i] == '1'){
			com++;			
		}
		else if(sw[i]=='1'){
			f++;
		}
		else if(s1[i]=='1'){
			s++;
		}
	}
	int chance=1,diff=0;
	if(com%2){
		diff=1;
		chance=2;
	}    
	//cout<<diff<<endl;
	while(f>0 || s>0){
		if(chance==1){
			if(f>0){
				diff++;
				f--;
			}
			else{
				s--;
			}
		}
		else{
			if(s>0){
				diff--;
				s--;
			}
			else{
				f--;
			}
		}
		if(chance==2){
			chance=1;
		}
		else 
			chance=2;
		//cout<<diff<<" "<<f<<" "<<s<<endl;
	}

	if(diff>0){
		cout<<"First"<<endl;
	}
	else if(diff<0){
		cout<<"Second"<<endl;
	}
	else{
		cout<<"Draw"<<endl;
	}
}