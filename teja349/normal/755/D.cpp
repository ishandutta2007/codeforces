
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
int n;  
int arra[1234567]={0};
int arr[10]={0};
int update(int pos,int val){
	while(pos<n+10){
		arra[pos]+=val;
		pos+=pos&(-pos);
	}
}
int compute(int pos){
	int sumi=0;
	while(pos>0){
		sumi+=arra[pos];
		pos-=pos&(-pos);
	}
	return sumi+arr[0];
}
int main(){
	int k,i;
	cin>>n>>k;
	int val=k-1;
	int num=n-2-k+1;
	int b=0;
	if(val<num)
		b=1;
	int next=1,nextf,value;
	ll sumi=1;
	rep(i,n){
		nextf=next+k;
		//cout<<next<<"  "<<nextf<<endl;
		if(nextf>n)
			value=nextf-n;
		else
			value=nextf;
		sumi+=compute(next)+compute(value)+1;
		cout<<sumi<<" ";
		if(b==1){

			if(nextf<=n){
				update(next+1,1);
				update(nextf,-1);
			}
			else{
				arr[0]++;
				update(nextf-n,-1);
				update(next+1,1);
			}
		}
		else{
			if(nextf<=n){
				update(nextf+1,1);
				update(next,-1);
				arr[0]++;
			}
			else{
				
				update(nextf-n+1,1);
				update(next,-1);
			}
		}
		if(nextf>n)
			nextf-=n;
		next=nextf;
	}
}