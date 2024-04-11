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
#define inf (1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);   
vector< vll > in(123456),out(123456);
ll haha[1234567],lol[1234567];
ll DAT=1234507;

int main(){
    std::ios::sync_with_stdio(false);
    ll n,m,k;
    ll d,f,t,c,i,j;
    cin>>n>>m>>k;
    rep(i,m){
    	cin>>d>>f>>t>>c;
    	if(f==0){
    		out[t].pb(mp(d,c));
    	}
    	else{
    		in[f].pb(mp(d,c));
    	}
    }
    f(i,1,n+1){
    	sort(out[i].begin(),out[i].end());
    	sort(in[i].begin(),in[i].end());
    }
    ll maxi;
    ll iinf=inf;
    iinf*=inf;
    ll anss=iinf;
    f(i,1,n+1){
    	maxi=iinf;
    	lol[0]+=iinf;
    	rep(j,in[i].size()){
    		lol[in[i][j].ff]-=maxi;
    		maxi=min(maxi,in[i][j].ss);
    		lol[in[i][j].ff]+=maxi;
    	}

    }
    f(i,1,n+1){
    	maxi=iinf;
    	haha[DAT]+=iinf;
    	if(out[i].empty())
    	    continue;
    	fd(j,out[i].size()-1,0){
    		haha[out[i][j].ff]-=maxi;
    		maxi=min(maxi,out[i][j].ss);
    		haha[out[i][j].ff]+=maxi;
    	}

    }
    f(i,1,DAT+1){
    	lol[i]+=lol[i-1];
    }
    fd(i,DAT-1,0){
    	haha[i]+=haha[i+1];
    }
    int st=0;
    int en=1+k;
    while(en<DAT-10 && haha[en]<iinf){
    	anss=min(anss,lol[st]+haha[en]);
    	st++;
    	en++;
    	//cout<<haha[st]+lol[en]<<" "<<st<<endl;
    }
    //cout<<haha[DAT]<<endl;
    if(anss>=iinf){
    	cout<<-1<<endl;
    }
    else{
    	cout<<anss<<endl;
    }

    return 0;  
    
}