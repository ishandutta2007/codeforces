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
int dp[3003][3003]={0},haha[3003][3003];
viii vec;
int n,p,s;
int cmp(tri i,tri j){
	return (j<i);
}
int compute(int pos,int num1,int num2);
int main(){
	std::ios::sync_with_stdio(false);
	int i,val;
	cin>>n>>p>>s;
	rep(i,n){
		cin>>val;
		vec.pb(mp(val,mp(0,i)));
	}
	rep(i,n){
		cin>>val;
		vec[i].ss.ff=val;
	}
	sort(vec.begin(),vec.end(),cmp);
	cout<<compute(0,s,p)<<endl;
	vi vec1,vec2;
	int pos=0,num1=s;
	while(pos!=n){
		if(haha[pos][num1]==1){
			vec1.pb(vec[pos].ss.ss + 1);
		}
		else if(haha[pos][num1]==2){
			vec2.pb(vec[pos].ss.ss + 1);
			num1--;
		}
		pos++;

	}
	rep(i,vec1.size()){
		cout<<vec1[i]<<" ";
	}
	cout<<endl;
	rep(i,vec2.size()){
		cout<<vec2[i]<<" ";
	}
	cout<<endl;
}

int compute(int pos,int num1,int num2){
	//cout<<"Gdg";
	int i=pos;
	if(num1<0 || num2<0)
		return -inf;
	//cout<<n<<endl;
	if(pos==n && ((num1!=0)||(num2!=0))){
		return -inf;
	}
	else if(pos==n){
		return 0;
	}

	if(dp[pos][num1]!=0)
		return dp[pos][num1];
	//cout<<"fsdsfd";
	if(num2!=0){
		int ans1=compute(pos+1,num1,num2-1)+vec[i].ff;
		int ans2=compute(pos+1,num1-1,num2)+vec[i].ss.ff;
		//cout<<ans1<<"   "<<ans2<<endl;
		if(ans1>ans2){
			dp[pos][num1]=ans1;
			haha[pos][num1]=1;
		}
		else{
			dp[pos][num1]=ans2;
			haha[pos][num1]=2;
		}
	}
	else{
		int ans1=compute(pos+1,num1,num2);
		int ans2=compute(pos+1,num1-1,num2)+vec[i].ss.ff;
		if(ans1>ans2){
			dp[pos][num1]=ans1;
			haha[pos][num1]=-1;
		}
		else{
			dp[pos][num1]=ans2;
			haha[pos][num1]=2;
		}
	}
	return dp[pos][num1];

}