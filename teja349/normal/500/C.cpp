
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
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

int weight[10000],b[10000];
int main()
{
	int n,m;
	cin>>n>>m;

	for(int i=0;i<n;++i)
	{
		cin>>weight[i];
	}

	for(int i=0;i<m;++i)
	{
		cin>>b[i];
	}

	ll answer = 0;

	for(int i=0;i<m;++i)
	{	
		set<int> set1;
		for(int j=i-1;(b[j]!=b[i])&&(j>=0);j--)
		{
			if(set1.find(b[j]) == set1.end())
			{
				set1.insert(b[j]);
				answer = answer + weight[b[j]-1];
			}
		}
	}


	cout<<answer<<"\n";
}