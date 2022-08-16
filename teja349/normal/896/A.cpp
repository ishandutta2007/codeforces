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
string f[100],st,mid,en;
ll len[123456];
ll iinf;
char getans(ll n,ll k){
	if(k>len[n]){
		return '.';
	}
	if(n==0){
		return f[0][k-1];
	}
	if(k<=st.length()){
		return st[k-1];
	}
	if(k<=st.length()+len[n-1]){
		return getans(n-1,k-st.length());
	}
	if(k<=st.length()+len[n-1]+mid.length()){
		return mid[k-len[n-1]-st.length()-1];
	}
	if(k<=st.length()+len[n-1]*2+mid.length()){
		return getans(n-1,k-(st.length()+len[n-1]+mid.length()));
	}
	else{
		return en[k-(st.length()+len[n-1]*2+mid.length())-1];
	}

}
int main(){
	iinf=inf;
	iinf*=inf;
    std::ios::sync_with_stdio(false);
    int q;
    f[0]="What are you doing at the end of the world? Are you busy? Will you save us?";
    st="What are you doing while sending \"";
    mid="\"? Are you busy? Will you send \"";
    en="\"?";
    len[0]=f[0].length();
    ll i;
    f(i,1,123456){
    	if(len[i-1]>iinf){
    		len[i]=iinf;
    		continue;
    	}
    	len[i]=st.length()+mid.length()+en.length()+len[i-1]+len[i-1];
    	

    }

    cin>>q;

    while(q--){
    	ll n,k;
    	cin>>n>>k;
    	cout<<getans(n,k);

    }
    cout<<endl;
    return 0;  
    
}