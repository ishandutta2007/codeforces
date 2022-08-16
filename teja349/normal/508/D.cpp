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
stack<int>st,revst;
int use[123456];
map<string,int> mapi;
map<int ,string> inv;
vector<vi> in(123456),out(123456);
int getpath(int cur){
	//cout<<inv[cur]<<endl;
	if(use[cur]!=out[cur].size()){
		st.push(out[cur][use[cur]]);
		use[cur]++;
		getpath(st.top());
	}
	return 0;
}

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i;
    string s;
    string s1,s2;
    int counter=0;
    rep(i,n){

    	cin>>s;
    	s1="";
    	s2="";
    	s1+=s[0];
    	s1+=s[1];
    	s2+=s[1];
    	s2+=s[2];
    	if(mapi.find(s1)==mapi.end()){
    		mapi[s1]=counter++;
    		inv[counter-1]=s1;
    	}
    	if(mapi.find(s2)==mapi.end()){
    		mapi[s2]=counter++;
    		inv[counter-1]=s2;
    	}
    	out[mapi[s1]].pb(mapi[s2]);
    	in[mapi[s2]].pb(mapi[s1]);
    }
    int haha=0,stt=0;
    rep(i,counter){
    	//sumi+=(int)in[i].size()-(int)out[i].size();
    	//cout<<in[i].size()<<"  "<<out[i].size()<<endl;
    	if(in[i].size()!=out[i].size()){
    		haha++;

    		if(abs((int)in[i].size()-(int)out[i].size())>1){

    			
    			cout<<"NO"<<endl;
    			return 0;
    		}
    		if((int)in[i].size()-(int)out[i].size()==-1){

    				stt=i;
    		}
    	}
    }
    if(haha>2){
    	cout<<"NO"<<endl;
    	return 0;
    }
    //cout<<"bbff"<<endl;
    st.push(stt);
    getpath(stt);
    //cout<<stt<<endl;
    //cout<<st.empty()<<endl;
    while(!st.empty()){
    	if(use[st.top()]!=out[st.top()].size()){
    		int cur=st.top();
    		st.push(out[cur][use[cur]]);
			use[cur]++;
			getpath(st.top());
    	}
    	else{
    		revst.push(st.top());
    		st.pop();
    	}
    }

    if(revst.size()!=n+1){
    	cout<<"NO"<<endl;
    	return 0;
    }
    cout<<"YES"<<endl;
    cout<<inv[revst.top()];
    revst.pop();
    while(!revst.empty()){
    	s=inv[revst.top()];
    	cout<<s[1];
    	revst.pop();
    }
    cout<<endl;


    return 0;  
    
}