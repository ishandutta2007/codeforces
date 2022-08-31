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
string reduc(string s){
	int i=0;
	string haha="",s1="";
	stack<char > st;
	rep(i,s.length()){
		if(s[i]=='u'){
			s1+='o';
			s1+='o';
		}	
		else
			s1+=s[i];
	}
	s=s1;
	//cout<<s<<endl;
	i=0;
	while(i<s.length()){
		if(s[i]=='h'){
			while(!st.empty() && st.top()=='k'){
				st.pop();
			}
			st.push('h');
		}
		else if(s[i]=='o'){
			if(!st.empty() && st.top()=='o'){
				st.pop();
				st.push('u');
			}
			else{
				st.push('o');
			}
			
		}
		else{
			//cout<<"dsdsa";
			st.push(s[i]);
		}
		i++;
	}
	while(!st.empty()){
		haha+=st.top();
		st.pop();
	}
	return haha;
}
string str[12345];
set<string> seti;
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i;
    rep(i,n){
    	cin>>str[i];
    	str[i]= reduc(str[i]);
    	//cout<<str[i]<<endl;
    	seti.insert(str[i]);
    }
    //set<string>::iterator
    cout<<seti.size()<<endl;
    return 0;  
    
}