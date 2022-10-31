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
typedef pair<lli,lli> llp;

inline double POWER(double a) {return a*a;}
inline lli _abs(lli a) {return a<0?-a:a;}
inline int _abs(int a) {return a<0?-a:a;}
inline lli power(lli a) { return a*a; }
inline int power(int a) { return a*a; }
inline lli gcd(lli a,lli b) {while(b) {lli tmp=a%b;a=b;b=tmp;}return a;}
inline int gcd(int a,int b) {while(b) {int tmp=a%b;a=b;b=tmp;}return a;}
const double EPS=1e-9;
const int mod=9901;
const lli inf=3e15;
const int dy[4]={0,-1,0,1},dx[4]={1,0,-1,0};
const double PI=acos(-1);
const char DC[4]={'E','N','W','S'};

int n,m,ans[300001];
ip arr[300010];

int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&arr[i].first),arr[i].second=i;
	
	lli sum=0;
	priority_queue<ip> que;
	for(int i=1;i<=m;i++) {
		que.push(ip(arr[i]));
	}
	int i=m+1;
	while(!que.empty()) {
		if(i<=n) que.push(arr[i]);
		ip now=que.top();que.pop();
		sum+=(lli)now.first*(i-now.second);
		ans[now.second]=i;
		i++;
	}
	printf("%lld\n",sum);
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	
	return 0;
}