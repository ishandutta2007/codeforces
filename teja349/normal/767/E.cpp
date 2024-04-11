//copied
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
#define pqueue priority_queue< pii >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);   
int cost[123456],worry[123456],notes[123456],coins[123456];
pqueue pq;
int penalty(int i){
	return (100-(cost[i]%100))*worry[i];
}
int main(){
	std::ios::sync_with_stdio(false);
	int n,i,j,m;
	cin>>n>>m;
	rep(i,n){
		cin>>cost[i];
	}
	rep(i,n){
		cin>>worry[i];
	}
	rep(i,n){
		if(cost[i]%100==0){
			notes[i]=cost[i]/100;
			coins[i]=0;
		}
		else if(cost[i]%100<=m){
			notes[i]=cost[i]/100;
			coins[i]=cost[i]%100;
			m-=coins[i];
			pq.push(mp(-1*penalty(i),i));
		}
		else{
			if(!pq.empty()&&penalty(pq.top().ss)<penalty(i)){
				int id=pq.top().ss;
				pq.pop();
				notes[id]+=1;
				coins[id]=0;
				m+=100;
				notes[i]=cost[i]/100;
				coins[i]=cost[i]%100;
				m-=coins[i];
				pq.push(mp(-1*penalty(i),i));

			}
			else{
				notes[i]=cost[i]/100+1;
				coins[i]=0;
				m+=100-cost[i]%100;
			}
		}


	}
	ll superpen=0;
	rep(i,n){
		if(cost[i]%100!=0 && coins[i]==0){
			superpen+=penalty(i);
			//cout<<penalty(i)<<"  "<<cost[i]<<endl;
		}
	}
	cout<<superpen<<endl;
	rep(i,n){
		cout<<notes[i]<<" "<<coins[i]<<endl;
	}
	return 0;
}