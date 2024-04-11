#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
typedef long long LL;
const LL P = 1e9+7;
const int N = 2e5+5;
const int INF = 1e9;
const double pi = acos(-1);
mt19937 rng(time(0));

LL a, b, c, y;
int id;

LL calc(LL a, LL b, LL c){
	LL x[4];
	x[1] = a, x[2] = b, x[3] = c;
	sort(x+1,x+4);
	if(x[3]-x[2] == x[2]-x[1]){
		return x[3]-x[2];
	}
	
	LL ma = max(max(a, b), c);
	return ma * 3 - a - b - c;
}

void add(int id, LL &a, LL &b, LL &c, LL y){
	if (id==1) a += y;
	if (id==2) b += y;
	if (id==3) c += y;
}

int main(){
	#ifndef ONLINE_JUDGE
	//freopen("test.in","r",stdin);
	#endif
	
	cin>>a>>b>>c;
	cout<<"First"<<endl;
	
	rep(i,1,3){
		y = calc(a,b,c); 
		cout<<y<<endl;
		cin>>id;
		if (!id) break;
		add(id, a, b, c, y);
	}
	
	return 0;
}