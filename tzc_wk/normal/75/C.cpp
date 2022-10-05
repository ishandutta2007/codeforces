#include <bits/stdc++.h>
using namespace std;
int a,b,d,T;
vector<int> g;
int main(){
	cin>>a>>b;
	d=__gcd(a,b);
	for(int i=1;i*i<=d;i++){
		if(d%i==0){
			g.push_back(-i);
			if(i!=d/i)	g.push_back(-d/i);
		}
	}
	sort(g.begin(),g.end());
	cin>>T;
	while(T--){
		int x,y;cin>>x>>y;
		int val=*lower_bound(g.begin(),g.end(),-y);
		if(-val<x)	puts("-1");
		else		cout<<-val<<endl;
	}
}