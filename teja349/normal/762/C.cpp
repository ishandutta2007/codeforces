
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
string a,b;
int ans=0;
int flag=-1;
vi arr(123456),arev(123456);
int computestart(){
	int i=0,j=0;
	while(i<a.length() && j<b.length()){

		if(a[i]==b[j]){
			arr[j]=i;
			i++;
			j++;
		}
		else{
			i++;
		}
	}
	if(j!=0)
		flag=0;
	ans=j;
	f(i,j,b.length()){
		arr[j]=-1;
	}
}
int computelast(){
	int i=a.length()-1;
	int j=b.length()-1;
	while(i>=0 && j>=0){

		if(a[i]==b[j]){
			arev[j]=i;
			i--;
			j--;
			//cout<<"SFDsdf";
		}
		else{
			i--;
		}
	}
	if(ans < b.length()-j-1){
		//cout<<"DSas";
		flag=2;
	}
	ans=max(ans,(int)b.length()-j-1);
	fd(i,j,0){
		arev[j]=-1;
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	
	cin>>a>>b;
	int i;
	computestart();
	computelast();
	int valst;
	int valend;
	int n=b.length();
	
	//cout<<arr[0]<<endl;
	rep(i,b.length()){
		if(arr[i]==-1){
			break;
		}

		vi::iterator it;
		it=upper_bound(arev.begin(),arev.begin()+b.length(),arr[i]);

		int value= it - arev.begin();
		if(ans<i+1+n-value){
			//cout<<"fdsdfs";
			flag=1;
			ans=i+1+n-value;
			valst=i;
			valend=value;

		}


	}
	if(flag==0){
		cout<<b.substr(0,ans);
		return 0;
	}
	else if(flag==2){

		cout<<b.substr(n-ans)<<endl;
		return 0;
	}
	if(ans==0){
		cout<<"-"<<endl;
	}
	else if(ans>=n){
		cout<<b<<endl;
	}
	else{
		cout<<b.substr(0,valst+1);
		cout<<b.substr(valend)<<endl;
	}
}