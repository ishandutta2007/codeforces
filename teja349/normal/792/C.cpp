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
vector<vi> vec(200);
int main(){
	std::ios::sync_with_stdio(false);
	string s,s1;
	
	cin>>s;
	int n=s.length();
	int i;
	ll sumi=0;
	int high=0;
	rep(i,s.length()){
		if(s[i]=='0'){
			vec[4].pb(i);

		}
		else{
			int val=s[i]-'0';
			vec[val%3].pb(i);
			sumi+=val%3;
		}
	}
	if(sumi%3==0){
		cout<<s<<endl;
		return 0;
	}
	else if(sumi%3==1){
		if(vec[1].empty()){
			if(vec[2].size()>2){
				int val=vec[2].size();
				val--;
				s[vec[2][val]]='#';
				val--;
				s[vec[2][val]]='#';
				

				rep(i,s.length()){
					if(s[i]!='#'){
						cout<<s[i];
					}
					
				}
				cout<<endl;
				return 0;
			}
			else if(vec[2].size()==2){
				if(n==2){
					cout<<-1<<endl;
					return 0;
				}
				int val=vec[2].size();
				val--;
				s[vec[2][val]]='#';
				val--;
				s[vec[2][val]]='#';
				rep(i,s.length()){
					if(s[i]!='#'){
						s1+=s[i];
					}
					
					//return 0;
				}
				int flag=0;
				rep(i,s1.length()){
					if(s1[i]!='0' || flag){
						flag=1;
						cout<<s1[i];
					}
				}
				if(!flag){
					cout<<0<<endl;
				}
				return 0;

			}
		}
		else if(vec[1].size()>1){
			int val=vec[1].size();
			val--;
			s[vec[1][val]]='#';
			rep(i,s.length()){
				if(s[i]!='#'){
					cout<<s[i];
				}
				
			}
			cout<<endl;
			return 0;
		}
		else{
			if(n==1){
				cout<<-1<<endl;
				return 0;
			}
			if(vec[1][0]!=0 || s[1]!='0'){
				rep(i,s.length()){
					if(i!=vec[1][0]){
						cout<<s[i];
					}
					
				}
				return 0;

			}
			if(vec[2].size()>2){
				int val=vec[2].size();
				val--;
				s[vec[2][val]]='#';
				val--;
				s[vec[2][val]]='#';
				

				rep(i,s.length()){
					if(s[i]!='#'){
						cout<<s[i];
					}
					
				}
				cout<<endl;
				return 0;
			}
			rep(i,s.length()){
				if(i!=vec[1][0]){
					s1+=s[i];
				}
				
			}
			int flag=0;
			rep(i,s1.length()){
				if(s1[i]!='0' || flag){
					flag=1;
					cout<<s1[i];
				}
			}
			if(!flag){
				cout<<0<<endl;
			}
			return 0;

		}
		

	}
	else{
		
		if(vec[2].empty()){
			if(vec[1].size()>2){
				int val=vec[1].size();
				val--;
				s[vec[1][val]]='#';
				val--;
				s[vec[1][val]]='#';
				

				rep(i,s.length()){
					if(s[i]!='#'){
						cout<<s[i];
					}
					
				}
				cout<<endl;
				return 0;
			}
			else if(vec[1].size()==2){
				//cout<<"yoo"<<endl;
				if(n==2){
					cout<<-1<<endl;
					return 0;
				}
				int val=vec[1].size();
				val--;
				s[vec[1][val]]='#';
				val--;
				s[vec[1][val]]='#';
				rep(i,s.length()){
					if(s[i]!='#'){
						s1+=s[i];
					}
					
					//return 0;
				}
				int flag=0;
				rep(i,s1.length()){
					if(s1[i]!='0' || flag){
						flag=1;
						cout<<s1[i];
					}
				}
				if(!flag){
					cout<<0<<endl;
				}
				return 0;

			}
		}
		else if(vec[2].size()>1){
			int val=vec[2].size();
			val--;
			s[vec[2][val]]='#';
			rep(i,s.length()){
				if(s[i]!='#'){
					cout<<s[i];
				}
				
			}
			cout<<endl;
			return 0;
		}
		else{
			if(n==1){
				cout<<-1<<endl;
				return 0;
			}
			if(vec[2][0]!=0 || s[1]!='0'){
				rep(i,s.length()){
					if(i!=vec[2][0]){
						cout<<s[i];
					}
					
				}
				return 0;

			}
			if(vec[1].size()>2){
				int val=vec[1].size();
				val--;
				s[vec[1][val]]='#';
				val--;
				s[vec[1][val]]='#';
				

				rep(i,s.length()){
					if(s[i]!='#'){
						cout<<s[i];
					}
					
				}
				cout<<endl;
				return 0;
			}
			rep(i,s.length()){
				if(i!=vec[2][0]){
					s1+=s[i];
				}
				
			}
			int flag=0;
			rep(i,s1.length()){
				if(s1[i]!='0' || flag){
					flag=1;
					cout<<s1[i];
				}
			}
			if(!flag){
				cout<<0<<endl;
			}
			return 0;

		}
		
	}

}