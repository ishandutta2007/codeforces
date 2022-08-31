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
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx


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
int N=20;
int gcdaux[323456][20],minaux[323456][20],a[412345];
int n;

ll buildgcd(int node,int s,int e){
	int i,j;
	rep(i,n){
		gcdaux[i][0]=a[i];
	}
	f(j,1,N){
		rep(i,n){
			if(i+(1<<j)>n)
				break;
			gcdaux[i][j]=__gcd(gcdaux[i][j-1],gcdaux[i+(1<<(j-1))][j-1]);
		}
	}
	return 0;

}   

ll buildmin(int node,int s,int e){
	int i,j;
	//cout<<"hii";
	rep(i,n){
		minaux[i][0]=a[i];
	}
	f(j,1,N){
		rep(i,n){
			if(i+(1<<j)>n)
				break;
			minaux[i][j]=min(minaux[i][j-1],minaux[i+(1<<(j-1))][j-1]);
		}
	}
	return 0;
}  



int querygcd(int node,int s,int e,int l,int r){
	int val=log2(r-l+1);
	return __gcd(gcdaux[l][val],gcdaux[r-(1<<val)+1][val]);
}
int querymin(int node,int s,int e,int l,int r){
	int val=log2(r-l+1);
	return min(minaux[l][val],minaux[r-(1<<val)+1][val]);
}


int check(int val){
	int i;
	rep(i,n){
		if(i+val>=n)
			break;
		if(querygcd(1,0,n-1,i,i+val)==querymin(1,0,n-1,i,i+val)){
			//cout<<val<<"  "<<i<<" "<<querygcd(1,0,n-1,i,i+val)<<endl;
			return 1;
		}
	}
	return 0;
}
int checker(int val){
	int counti=0,i;
	rep(i,n){
		if(i+val>=n)
			break;
		if(querygcd(1,0,n-1,i,i+val)==querymin(1,0,n-1,i,i+val))
			counti++;
	}
	return counti;
}
int checkker(int val){
	int counti=0,i;
	rep(i,n){
		if(i+val>=n)
			break;
		if(querygcd(1,0,n-1,i,i+val)==querymin(1,0,n-1,i,i+val))
			cout<<i+1<<" ";
	}
	return counti;
}

int main(){
	std::ios::sync_with_stdio(false);
	int i;
	cin>>n;
	rep(i,n){
		cin>>a[i];
	}
	buildgcd(1,0,n-1);
	buildmin(1,0,n-1);
	int low=0;
	int high=n-1;
	int ans=0;
	int mid=(low+high)/2;
	//cout<<querymin(1,0,n-1,1,4)<<endl;
	while(low<=high){
		if(check(mid)){
			ans=mid;
			low=mid+1;
		}
		else{
			high=mid-1;
		}
		mid=(low+high)/2;
	}
	cout<<checker(ans)<<"  "<<ans<<endl;
	checkker(ans);


}