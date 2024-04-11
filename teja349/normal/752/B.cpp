
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
	string s1;
	string s2;
	cin>>s1>>s2;
	int i,counti=0,a[12345]={0};
	rep(i,s1.length()){
		if(a[s1[i]]==0){
			a[s1[i]]=s2[i];
			if(a[s2[i]]==0)
				a[s2[i]]=s1[i];
			else if(a[s2[i]]!=s1[i])
			{
				cout<<-1<<endl;
				return 0;
			}
		}
		else if(a[s1[i]]!=s2[i]){
			cout<<-1<<endl;
			return 0;
		}

	}
	rep(i,26){
		if(a[i+'a']==0||a[i+'a']==i+'a')
			continue;
		counti++;
	}
	cout<<counti/2<<endl;
	rep(i,26){
		if(a[i+'a']==0||a[i+'a']==i+'a')
			continue;
		cout<<(char)a[i+'a']<<" "<<(char)(i+'a')<<endl;
		a[a[i+'a']]=0;
	}
}