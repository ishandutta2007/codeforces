#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")

#define f first
#define s second
#define pb push_back
#define endl '\n'

map<vector<int>, int>ma;
map<vector<int>, bool>che;


main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	queue<vector<int>>q;
	vector<int>v;
	int n;
	cin>>n;
	
	for(int i=1; i<=2*n; i++){
		v.pb(i);
	}
	q.push(v);
	
	ma[v]=0;
	while(!q.empty()){
		vector<int>u=q.front();
		q.pop();
		if(che[u]){
			continue;
		}
		che[u]=1;
		vector<int>v1;
		vector<int>v2;
		v1.resize(2*n);
		v2.resize(2*n);
		for(int i=0; i<u.size(); i++){
			if(i%2==0){
				v1[i+1]=u[i];
			}
			else{
				v1[i-1]=u[i];
			}
		}
		for(int i=0; i<n; i++){
			v2[i+n]=u[i];
		}
		for(int i=n; i<2*n; i++){
			v2[i-n]=u[i];
		}
		
		int d1=ma[u];
		int d2=ma[v1];
		int d3=ma[v2];
		if(d2>1+d1 || !che[v1]){
			ma[v1]=1+d1;
			q.push(v1);
		}
		if(d3>1+d1 || !che[v2]){
			ma[v2]=1+d1;
			q.push(v2);
		}
		
	}
	vector<int>vec;
	for(int i=1; i<=2*n; i++){
		int x;
		cin>>x;
		vec.pb(x);
	}
	if(!che[vec]){
		cout<<-1;
	}
	else{
		cout<<ma[vec];
	}
	return 0;
}