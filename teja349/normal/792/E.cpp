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
int a[1234],n;
unordered_map<int,int> acc;
ll mini;
int check(int val){
	int i;
	ll sumi=0,r;
	int lol;
	//cout<<val<<endl;
	rep(i,n){
		lol=a[i]/(val+1)-a[i]/val;
		if(a[i]%(val+1)==0)
			lol=1;
		if(lol==0)
			return 0;
		r=a[i]/(val+1);
		if(a[i]%(val+1)!=0)
			r++;
		sumi+=r;
	}
	mini=min(mini,sumi);
	return 0;
}
int update(int lol){
	int i;
	int val;
	vi vec;
	for(i=1;i*i<=lol+2;i++){
		val=lol/i;
		vec.pb(val);
		if(val*i==lol){
			
			vec.pb(val-1);
		}

	}
	for(i=1;i*i<=lol+3;i++){
		val=(lol/i)-(lol/(i+1));
		
		if(val>0)
			vec.pb(i);
		if(n%i==0){
			vec.pb(i-1);
		}


	}
	sort(vec.begin(),vec.end());
	vi::iterator it;
	//it=unique(vec.begin(),vec.end());
	//vec.resize(it-vec.begin());

	acc[vec[0]]++;
	f(i,1,vec.size()){
		if(vec[i]!=vec[i-1])
			acc[vec[i]]++;
	}
	//cout<<"asdas"<<endl;
	return 0;

}
int main(){
    //std::ios::sync_with_stdio(false);
	int i;
	cin>>n;
	rep(i,n){
		scanf("%d",&a[i]);
	}    
	mini=inf;
	mini*=inf;
	sort(a,a+n);
	rep(i,1){
		update(a[i]);
	}
	unordered_map<int,int>::iterator it;
	for(it=acc.begin();it!=acc.end();it++){
		//cout<<it->ff<<" "<<it->ss<<endl;
			
			//cout<<it->ff<<endl;
			if(it->ff!=0)
				check(it->ff);
		
	}
	cout<<mini<<endl;
    
}