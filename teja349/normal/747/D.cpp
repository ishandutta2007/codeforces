
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
int main(){
	int n,k,i,a[210000];
	vi vec;
	int val=0,summer=0,summ1=0,intial=0,flag=1;
	cin>>n>>k;
	rep(i,n){
		cin>>a[i];
		if(a[i]<0){
			val++;
		}
	}

	if(val>k){
		cout<<-1<<endl;
		return 0;
	}

	int prev=-1;
	rep(i,n){
		if(a[i]<0){
			if(flag){
				flag=0;
				intial=i-prev-1;
				prev=i;
				continue;
			}
			vec.pb(i-prev-1);
			prev=i;

		}
	}
	if(val==0){
		cout<<0<<endl;
		return 0;
	}
	//cout<<val<<"dda"<<endl;
	int last=n-prev-1;
	summer=n-val-intial;
	//cout<<val;
	val=k-val;
	//cout<<val<<endl;
	sort(vec.begin(),vec.end());
	summ1=summer-last;
	//cout<<summer<<endl;
	int counti1=1;
	i=(int)vec.size()-1;
	while(summ1>val&&i>=0){

		counti1+=2;
		summ1-=vec[i];
		i--;
	}
	if(summ1>val){
		counti1=inf;
	}
	summ1=summer;
	i=(int)vec.size()-1;
	int counti2=0;
	//cout<<summ1<<"  "<<val<<endl;
	while(summ1>val&&i>=0){

		counti2+=2;
		summ1-=vec[i];
		i--;
	}
	if(summ1>val){
		counti2=inf;
	}
	//cout<<counti2<<endl;
	cout<<min(counti1+1,counti2+1)<<endl;





}