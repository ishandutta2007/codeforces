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
int a[12345],dp[12345],n;
int lol[5004][5004];   
int compute(int pos){
	set<int> seti;
	int haha=0;
	if(pos==n+1){
		return 0;
	}
	int val=compute(pos+1);
	if(lol[pos-1][a[pos]]!=0){
		dp[pos]=val;
		return val;
	}
	if(lol[n][a[pos]]-lol[pos][a[pos]]==0){
		dp[pos]=a[pos]+val;
		return dp[pos];
	}
	seti.insert(a[pos]);
	haha^=a[pos];
	int j=pos+1;
	while(1){
		if(seti.find(a[j])!=seti.end()){
			if(lol[n][a[j]]-lol[j][a[j]]==0){
				seti.erase(a[j]);
			}

		}
		else{
			if(lol[j-1][a[j]]!=0){
				dp[pos]=val;
				return val;
			}
			else{
				haha^=a[j];
				if(lol[n][a[j]]-lol[j][a[j]]!=0){
					seti.insert(a[j]);
				}

			}
		}
		j++;
		if(seti.empty()){
			dp[pos]=max(haha+compute(j),val);
			return dp[pos];
		}
	}

}
int main(){
    std::ios::sync_with_stdio(false);
  
    cin>>n;
    int i,j;
    f(i,1,n+1){
    	cin>>a[i];
    	if(i!=0){
    		rep(j,5001){
    			lol[i][j]=lol[i-1][j];
    		}
    	}
    	lol[i][a[i]]++;
    }
    rep(i,5001){
    	lol[n+1][i]=lol[n][i];
    }
    cout<<compute(1)<<endl;
    
}