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
int dp[301][301],dp1[301][301][301];
int compute(int a,int b){
	int i;
	if(a>b){
		swap(a,b);
	}
	if(dp[a][b]!=0){
		return dp[a][b];
	}
	f(i,1,a+1){
		if(compute(a-i,b)==2){
			dp[a][b]=1;
			return 1;
		}
		if(compute(a-i,b-i)==2){
			dp[a][b]=1;
			return 1;
		}
	}
	f(i,1,b+1){
		if(compute(a,b-i)==2){
			dp[a][b]=1;
			return 1;
		}
	}
	dp[a][b]=2;
	return 2;

}
int computeb(int a,int b,int c){
	int i;
	int arr[3];
	arr[0]=a;
	arr[1]=b;
	arr[2]=c;
	sort(arr,arr+3);
	a=arr[0];
	b=arr[1];
	c=arr[2];

	if(dp1[a][b][c]!=0){
		return dp1[a][b][c];
	}
	f(i,1,a+1){
		if(computeb(a-i,b,c)==2){
			dp1[a][b][c]=1;
			return 1;
		}
		if(computeb(a-i,b-i,c-i)==2){
			dp1[a][b][c]=1;
			return 1;
		}
	}
	f(i,1,b+1){
		if(computeb(a,b-i,c)==2){
			dp1[a][b][c]=1;
			return 1;
		}
	}
	f(i,1,c+1){
		if(computeb(a,b,c-i)==2){
			dp1[a][b][c]=1;
			return 1;
		}
	}
	dp1[a][b][c]=2;
	return 2;

}

int main(){
    std::ios::sync_with_stdio(false);
    int n,i;
    int a[10];
    cin>>n;
    if(n==1){
    	cin>>n;
    	if(n!=0)
    		cout<<"BitLGM"<<endl;
    	else
    		cout<<"BitAryo"<<endl;
    	return 0;
    }

    rep(i,n){
    	cin>>a[i];
    }
    sort(a,a+n);
    if(n==2){
    	dp[0][0]=2;
    	if(compute(a[0],a[1])==1){
    		cout<<"BitLGM"<<endl;
    	}
    	else{
    		cout<<"BitAryo"<<endl;
    	}
    	return 0;
    }
    if(n==3){
    	dp1[0][0][0]=2;
    	if((a[0]^a[1]^a[2]) != 0){
    		cout<<"BitLGM"<<endl;
    	}
    	else{
    		cout<<"BitAryo"<<endl;
    	}
    	return 0;
    }


}