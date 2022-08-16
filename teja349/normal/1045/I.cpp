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
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

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
#define flush fflush(stdout) 
#define primeDEN 727999983
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template <typename T>
void printvec(vector<T>& vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}



int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    int i,j,k;
    vector<string> inp(n);
    for(i=0;i<n;i++){
    	cin>>inp[i];
    }
    map<set<int>,ll> mapp;
    for(i=0;i<n;i++){
    	vi freq(26,0);
    	for(j=0;j<inp[i].length();j++){
    		freq[inp[i][j]-'a']++;
    	}
    	set<int> temp;
    	for(j=0;j<26;j++){
    		if(freq[j]%2==1) temp.insert(j);
    	}
    	mapp[temp]++;
    }
    ll ans=0;
    map<set<int>,ll>::iterator it;
    set<int>::iterator setit;
    for(it=mapp.begin();it!=mapp.end();it++){
    	set<int> sett=(it->ff);
    	set<int> sett2=sett;
    	ll prefreq=(it->ss);
    	//cout<<mapp[it->ff]<<endl;
    	ans+=(prefreq*(prefreq-1));
    	for(setit=sett2.begin();setit!=sett2.end();setit++){
    		sett.erase(*setit);
    		if(mapp.find(sett)!=mapp.end()) ans+=(prefreq*mapp[sett]);
    		sett.insert(*setit);
    	}
    	for(i=0;i<26;i++){
    		if(sett2.find(i)!=sett2.end()) continue;
    		sett.insert(i);
    		if(mapp.find(sett)!=mapp.end()) ans+=(prefreq*mapp[sett]);
    		sett.erase(i);
    	}
    }
    ans=ans/2;
    cout<<ans;
    return 0;   
}