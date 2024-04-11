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
int ans[10000];
int haha[100];
int main(){
    std::ios::sync_with_stdio(false);
    int i,j;
    ans[1]=0;
    ans[0]=0;
    int k;
    cin>>k;
    if(k==0){
    	cout<<'a'<<endl;
    	return 0;
    }
    f(i,2,3000){
    	ans[i]=i*(i-1)/2;
    }
   	i=2989,j=0;
   	while(1){
   		if(k==0){
   			break;
   		}
   		while(ans[i]>k){
   			i--;
   		}
   		haha[j++]=i;
   		k-=ans[i];
   	}
   	rep(i,j){
   		rep(k,haha[i]){
   			cout<<(char)('a'+i);
   		}
   	}

    return 0;  
    
}