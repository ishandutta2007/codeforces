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
int dp[520][520]={0};
bool haha[520][520][520];
int k;
int a[1000];
int compute(int pos,int val){
	if(val<0)
		return 0;
	
	if(val==0){
		haha[pos+1][val][0]=1;
		return 0;
	}
	if(pos==-1)
		return 0;
	//dp[pos][val]=1;
	if(dp[pos][val]==1)
		return 0;
	dp[pos][val]=1;
	compute(pos-1,val);
	compute(pos-1,val-a[pos]);
	int i;
	rep(i,k+2){
		haha[pos+1][val][i]=haha[pos+1][val][i]|haha[pos][val][i];
	}
	if(val-a[pos]>=0){
		rep(i,k+2){
			haha[pos+1][val][i]=haha[pos+1][val][i]|haha[pos][val-a[pos]][i];
			if(i+a[pos]<=k+2){
				haha[pos+1][val][i+a[pos]]=haha[pos+1][val][i+a[pos]]|haha[pos][val-a[pos]][i];
			}
		}

	}
	return 0;

}	
int main(){
    std::ios::sync_with_stdio(false); 
    int n,i,cou=0;
    cin>>n>>k;
    rep(i,n){
    	cin>>a[i];
    }
    compute(n-1,k);
    rep(i,k+2){
    	if(haha[n][k][i]!=0)
    		cou++;
    }
    cout<<cou<<endl;
    rep(i,k+2){
    	if(haha[n][k][i]!=0)
    		cout<<i<<" ";
    }
    return 0;
}