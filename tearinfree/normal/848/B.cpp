#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <queue>
#include <stack>
#include <functional>
#include <set>
#include <map>
#include <cassert>
#include <cmath>
#include <cstdlib>

using namespace std;
typedef long long lli;
typedef pair<int,int> ip;
typedef pair<lli,int> lip;

inline double POWER(double a) {return a*a;}
inline lli _abs(lli a) {return a<0?-a:a;}
inline int _abs(int a) {return a<0?-a:a;}
inline lli power(lli a) { return a*a; }
inline int power(int a) { return a*a; }
inline lli gcd(lli a,lli b) {while(b) {lli tmp=a%b;a=b;b=tmp;}return a;}
inline int gcd(int a,int b) {while(b) {int tmp=a%b;a=b;b=tmp;}return a;}
const double EPS=1e-9;
const int mod=1e9+7,dy[4]={0,-1,0,1},dx[4]={1,0,-1,0};
const lli inf=3e18;

int n,w,h;
struct data{
	int ty,x,y,t;
	data() {}
	data(int ty,int p,int t):ty(ty),t(t) {
		if(ty==1) x=p,y=0;
		else y=p,x=0;
	}
	void init(int p) {
		if(ty==1) x=p,y=0;
		else y=p,x=0;
	}
	ip result() {
		if(ty==1) return ip(x,h);
		else return ip(w,y);
	}
};

data arr[100000];
int ans[100000];
int main() {
	int ty,p,t;
	scanf("%d%d%d",&n,&w,&h);
	for(int i=0;i<n;i++) {
		scanf("%d%d%d",&ty,&p,&t);
		arr[i].ty=ty; arr[i].t=t;
		arr[i].init(p);
	}
	
	vector<ip> ya,xa;
	for(int i=0;i<n;i++) {
		if(arr[i].ty==1) xa.push_back(ip(arr[i].t-arr[i].x,i));
		else ya.push_back(ip(arr[i].t-arr[i].y,i));
	}
	if(ya.size()==0||xa.size()==0) {
		for(int i=0;i<n;i++) {
			ip res=arr[i].result();
			printf("%d %d\n",res.first,res.second);
		}
		return 0;
	}
	sort(ya.begin(),ya.end());sort(xa.begin(),xa.end());
	auto xx=xa.begin(),yy=ya.begin();
	int dif=min(xx->first,yy->first);
	while(xx!=xa.end()||yy!=ya.end()) {
		vector<ip> tx,ty;
		while(xx!=xa.end()&&xx->first==dif) tx.push_back(ip(arr[xx->second].x,xx->second)),xx++;
		while(yy!=ya.end()&&yy->first==dif) ty.push_back(ip(arr[yy->second].y,yy->second)),yy++;
		sort(tx.begin(),tx.end()); sort(ty.begin(),ty.end());
		reverse(ty.begin(),ty.end());
		int id=0,idx=0;
		if(id==0&&idx==(int)tx.size()) id=1,idx=0;
		for(auto &it:ty) {
			if(id==0)ans[it.second]=tx[idx].second;
			else ans[it.second]=ty[idx].second;
			idx++;
			if(id==0&&idx==(int)tx.size()) id=1,idx=0;
		}
		for(auto &it:tx) {
			if(id==0)ans[it.second]=tx[idx].second;
			else ans[it.second]=ty[idx].second;
			idx++;
			if(id==0&&idx==(int)tx.size()) id=1,idx=0;
		}
		
		if(xx==xa.end()&&yy==ya.end()) break;
		if(xx==xa.end()) dif=yy->first;
		else if(yy==ya.end()) dif=xx->first;
		else dif=min(xx->first,yy->first);
	}
	for(int i=0;i<n;i++) {
		ip res=arr[ans[i]].result();
		printf("%d %d\n",res.first,res.second);
	}

	return 0;
}