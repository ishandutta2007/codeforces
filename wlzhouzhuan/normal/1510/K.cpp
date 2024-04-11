#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull base=1145141;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n;
vector<int> pre,ori;
queue<pair<vector<int>,int> > q;
unordered_set<ull> vis;
inline ull H(vector<int> &v){
	ull t=0;
	for(auto x:v){
		t=t*base+x;	
	}	
	return t;
}
int main(){
	n=read();
	for(int i=1;i<=(n<<1);++i){
		pre.push_back(read());
		ori.push_back(i);
	}
	ull goal=H(ori);
	q.push({pre,0});
	vis.insert(H(pre));
	while(!q.empty()){
		auto [u,step]=q.front();
		if(H(u)==goal){
			printf("%d\n",step);
			return 0;
		}
		q.pop();
		auto v=u;
		for(int i=0;i<n;++i){
			swap(v[i],v[i+n]);
		}
		ll t=H(v);
		if(vis.find(t)==vis.end()){
			vis.insert(t);
			q.push({v,step+1});
		}
		v=u;
		for(int i=0;i<(n<<1);i+=2){
			swap(v[i],v[i+1]);	
		}
		t=H(v);
		if(vis.find(t)==vis.end()){
			vis.insert(t);
			q.push({v,step+1});
		}
	}
	puts("-1");
	return 0;
}