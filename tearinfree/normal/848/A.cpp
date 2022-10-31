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

//inline double POWER(double a) {return a*a;}
//inline lli abs(lli a) {return a<0?-a:a;}
//inline int abs(int a) {return a<0?-a:a;}
inline lli power(lli a) { return a*a; }
inline int power(int a) { return a*a; }
inline lli gcd(lli a,lli b) {while(b) {lli tmp=a%b;a=b;b=tmp;}return a;}
inline int gcd(int a,int b) {while(b) {int tmp=a%b;a=b;b=tmp;}return a;}
const double EPS=1e-9;
//const int mod=1e9+7,dy[4]={0,-1,0,1},dx[4]={1,0,-1,0};
//const lli inf=3e18;

int n;
int vis[27][100001];
ip pre[27][100001];
int cnt[27][100001];

void trace(ip now) {
	while(true) {
		int t=cnt[now.first][now.second];
		while(t--) printf("%c",now.first-1+'a');
		if(now.first==0) break;
		now=pre[now.first][now.second];
	}
}
int main() {
	vector<int> sa;
	scanf("%d",&n);
	if(n==0) {
		puts("a");
		return 0;
	}
	sa.push_back(0);
	for(int i=1;;i++) {
		int val=i+sa.back();
		if(val>n) break;
		sa.push_back(val);
	}
	bool flag=false;
	queue<ip> que;
	que.push(ip(0,0));
	while(!que.empty()) {
		ip now=que.front();que.pop();
		for(int i=0;i<sa.size();i++) {
			auto it=sa[i];
			if(now.second+it>n) break;
			if(!vis[now.first+1][now.second+it]) {
				ip nxt=ip(now.first+1,now.second+it);
				vis[now.first+1][now.second+it]=1;
				pre[now.first+1][now.second+it]=now;
				cnt[now.first+1][now.second+it]=i+1;
				if(nxt.first<26)que.push(nxt);
				
				if(now.second+it==n) {
					flag=true;
					trace(nxt);
					break;
				}
			}
			if(flag) break;
		}
		if(flag) break;
	}
	
	return 0;
}