
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
#define inf 1000*1000*1000+5
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod 1000*1000*1000+7


int a[100000],b[100000],n,m;
int check(int p);
int main(){
	int i;
	cin>>n>>m;
	rep(i,n){
		cin>>a[i];
	}
	f(i,1,m+1){
		cin>>b[i];
	}
	int high=n;
	int low=m;
	int mid=(low+high)/2;
	if(!check(n)){
		cout<<-1<<endl;
		return 0;
	}
	while(low<high){
		if(check(mid)){
			high=mid;

		}
		else {
			low=mid+1;
		}
		mid=(low+high)/2;
	}
	cout<<mid<<endl;

}

int check(int p){
	//memset(visit,0,m+1);
	int visit[100000]={0};
	visit[0]=1;
	int i,days=0;
	// rep(i,m+1){
	// 	cout<<visit[i]<"   hiiiwww";
	// }
	
	//cout<<endl<<p<<endl;
	fd(i,p-1,0){
		//cout<<"hii"<<endl;
		if(visit[a[i]]==0){
			visit[a[i]]=1;
			days-=b[a[i]]+1;
		}
		days++;
		if(days>0)
			days=0;
	}
	f(i,1,m+1){
		if(visit[i]==0)
			return 0;
	}
	if(days<0)
		return 0;
	return 1;
}