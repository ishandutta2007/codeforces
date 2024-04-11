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
bitset<300000026> b;
bitset<300000026> bee;
vi vec,vect;
int main(){
    std::ios::sync_with_stdio(false); 
    int l,r;
    cin>>l>>r;
    int i,j,sumi=0;
    for(i=2;i*i<=r+3;i++){
    	if(b[i])
    		continue;
    	for(j=i*i;j<=r+2;j+=i){
    		b[j]=1;
    	}
    }

    for(i=1;i*i<r+1;i+=2){
    	vec.pb(i*i);
    }
    for(j=2;j*j<r+1;j+=2){
    	vect.pb(j*j);
    }
    rep(i,vect.size()){
    	rep(j,vec.size()){
    		if(vect[i]+vec[j]<=r && vect[i]+vec[j]>=l && bee[vect[i]+vec[j]]==0 && b[vect[i]+vec[j]]==0){
    			bee[vect[i]+vec[j]]=1;
    			sumi++;
    		}
    		if(vect[i]+vec[j]>r)
    			break;
    	}
    }
    if(l<=2 && r>=2)
    	sumi++;
    cout<<sumi<<endl;

}