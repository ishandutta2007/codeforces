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
int arr[1234];
vi vec;
int main(){
    std::ios::sync_with_stdio(false);
    string s,t,st;
    cin>>s>>t;
    st=s;
    int n=s.length();
    int m=t.length();
    int i,j;
    rep(i,s.length()){
    	arr[s[i]]++;
    	if(s[i]=='?'){
    		vec.pb(i);
    	}
    }
    i=0;
    j=0;
   	int k=0;
    while(i<n){
    	if(arr[t[j]]!=0){
    		//st[i]=t[j];
    		arr[t[j]]--;
    	}
    	else if(arr['?']!=0){
    		s[vec[k]]=t[j];
    		k++;
    		arr['?']--;
    	}
    	else{
    		break;
    	}
    	j++;
    	i++;
    	if(j==m)
    		j=0;
    }
    cout<<s<<endl;
    return 0;
    rep(j,256){
    	while(arr[j]>0){
    		st[i]=char(j);
    		arr[j]--;
    		i++;
    	}
    }
    cout<<st<<endl;
    return 0;      

}