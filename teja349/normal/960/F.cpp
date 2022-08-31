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
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

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
vector< map<int,int> > vec(123456);
vector< vi > bit(123456);
int sz[123456];
int update(int typ,int posi,int val){
	while(posi<sz[typ]+3){
		//cout<<"dsadsa"<<endl;
		bit[typ][posi]=max(bit[typ][posi],val);
		posi+=posi&(-posi);
	}
}
int getmax(int typ,int pos){
	int val=0;
	
	while(pos>0){

		val=max(val,bit[typ][pos]);
		pos-=pos&(-pos);
	}
	return val;
}
int a[123456],b[123456],w[123456];
int main(){
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int i;
    rep(i,m){
    	cin>>a[i]>>b[i]>>w[i];
    	vec[a[i]][w[i]]=0;
    	vec[b[i]][w[i]]=0;
    }

    map<int,int>::iterator it;
    rep(i,n+1){
    	int counter=1;
    	for(it=vec[i].begin();it!=vec[i].end();it++){
    		it->ss=counter++;
    		//inv[i][counter-1]=it->ff;
    	}
    	sz[i]=counter;
    	bit[i].resize(counter+4,0);
    	
    }
    int maxi=0;
    rep(i,m){
    	int posi=getmax(a[i],vec[a[i]][w[i]]-1);
    	//cout<<i<<" "<<posi<<endl;
    	update(b[i],vec[b[i]][w[i]],posi+1);

    	maxi=max(maxi,posi+1);
    }
    cout<<maxi<<endl;


    return 0;  
    
}