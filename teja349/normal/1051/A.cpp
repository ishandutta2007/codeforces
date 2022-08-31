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
#define flush fflush(stdout) 
#define primeDEN 727999983
//cout<<fixed<<setprecision(15)<<ans;
 
template <typename T>
void printvec(vector<T>& vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}

int pres[1234],pre[1234];

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
    	string s;
    	cin>>s;
    	int i;
    	rep(i,500){
    		pres[i]=0;
    	}
    	rep(i,s.length()){
    		pres[s[i]]++;
    	}
    	f(i,1,400){
    		pre[i]=pre[i-1]+pres[i];
    	}
    	int num,sm,lg;
    	num=pre['9']-pre['0'-1];
    	sm=pre['z']-pre['a'-1];
    	lg=pre['Z']-pre['A'-1];
    	if(num!=0 && lg!=0 && sm!=0){
    		cout<<s<<endl;
    		continue;
    	}
    	if(num==0 && lg==0){
    		s[0]='A';
    		s[1]='7';
    	}
    	else if(num==0 && sm==0){
    		s[0]='a';
    		s[1]='7';
    	}
    	else if(sm==0 && lg==0){
    		s[0]='a';
    		s[1]='A';
    	}
    	else if(num==0){
    		rep(i,s.length()){
    			if(s[i]<='Z' && s[i]>='A' && lg>1){
    				s[i]='7';
    				break;
    			}
    			if(s[i]<='z' && s[i]>='a' && sm>1){
    				s[i]='7';
    				break;
    			}
    		}
    	}
    	else if(sm==0){
    		rep(i,s.length()){
    			if(s[i]<='Z' && s[i]>='A' && lg>1){
    				s[i]='a';
    				break;
    			}
    			if(s[i]<='9' && s[i]>='0' && num>1){
    				s[i]='a';
    				break;
    			}
    		}
    	}
    	else{
    		rep(i,s.length()){
    			if(s[i]<='9' && s[i]>='0' && num>1){
    				s[i]='A';
    				break;
    			}
    			if(s[i]<='z' && s[i]>='a' && sm>1){
    				s[i]='A';
    				break;
    			}
    		}
    	}
    	cout<<s<<endl;
    }
    
    return 0;   
}