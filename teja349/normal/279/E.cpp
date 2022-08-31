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
vi vec;
int main(){
    std::ios::sync_with_stdio(false);
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    int i,j;
   	rep(i,s.length()){
   		if(s[i]=='1'){
   			break;
   		}
   	}
   	//cout<<i<<"dsasd"<<endl;
   	int cont=1,ans=0,prev=0,maxi=1;
   	fd(j,s.length()-2,i){

   		if(s[j]==s[j+1]){
   			cont++;
   		}
   		else{
   			vec.pb(cont);
   			cont=1;
   		}

   	}
   	//cout<<i<<endl;
   	vec.pb(cont);
   	vec.pb(2);
   	//cout<<vec.size()<<endl;
   	rep(i,vec.size()){
   		if(i%2){
   			if(vec[i]>1){
   				if(maxi==1){
   					ans+=prev+1;
   					
   				}
   				else{
   					ans+=prev+2;
   				}
   				maxi=1;
   				prev=0;
   			}
   			else{
   				prev++;
   			}
   		}
   		else{
   			maxi=max(maxi,vec[i]);

   		}
   	}

   	cout<<ans<<endl;
}