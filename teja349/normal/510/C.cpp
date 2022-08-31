
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
int ideg[50]={0};
vector< set<int> > adjout(50);  
int build(string s,string s1){
	int i=0;
	while(i<s1.length() && i<s.length() &&s[i]==s1[i]){
		i++;
	}
	if(i==s.length()){
		return 0;
	}
	if(i==s1.length()){
		cout<<"Impossible"<<endl;
		exit(0);
	}
	if(adjout[s[i]-'a'].find(s1[i]-'a')==adjout[s[i]-'a'].end()){
		adjout[s[i]-'a'].insert(s1[i]-'a');
		ideg[s1[i]-'a']++;
	}
	return 0;
}
int toposort(){
	int i;
	stack<int> st;
	rep(i,26){
		if(ideg[i]==0){
			st.push(i);

		}
	}
	string s="";
	set<int>::iterator it;
	int counti=0;
	while(!st.empty()){
		int val=st.top();
		st.pop();
		s+=(char)(val+'a');
		counti++;
		for(it=adjout[val].begin();it!=adjout[val].end();it++){
			ideg[*it]--;
			if(ideg[*it]==0){
				st.push(*it);
			}
		}

	}
	if(counti!=26){
		cout<<"Impossible"<<endl;
	}
	else{
		cout<<s<<endl;
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	int n,i;
	string s,s1;
	cin>>n;
	cin>>s;
	rep(i,n-1){
		cin>>s1;
		build(s,s1);
		s=s1;

	}
	toposort();
}