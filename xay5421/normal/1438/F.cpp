#include<bits/stdc++.h>
#define X first
#define Y second
#define PB push_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
const int N=(1<<18)+5;
int h,n,lim=420;
map<int,int>mp;
int ask(int k1,int k2,int k3){
	--lim;
	printf("? %d %d %d\n",k1,k2,k3);
	fflush(stdout);
	int k4;
	scanf("%d",&k4);
	return k4;
}
void report(int k1){
	printf("! %d\n",k1);
	fflush(stdout);
	exit(0);
}
int main(){
	scanf("%d",&h);
	n=(1<<h)-1;
	rep(i,1,420){
		int k1=rng()%n+1,k2=rng()%n+1,k3=rng()%n+1;
		while(k1==k2||k1==k3||k2==k3)k1=rng()%n+1,k2=rng()%n+1,k3=rng()%n+1;
		int t=ask(k1,k2,k3);
		if(t!=k1&&t!=k2&&t!=k3){
			++mp[t];
		}
	}
	vector<pair<int,int> >v;
	for(auto x:mp)v.PB({-x.Y,x.X});
	sort(v.begin(),v.end());
	pair<int,int>res{v[0].Y,v[1].Y};
	rep(i,1,n)if(i!=res.X&&i!=res.Y&&ask(res.X,res.Y,i)==i)report(i);
	return 0;
}