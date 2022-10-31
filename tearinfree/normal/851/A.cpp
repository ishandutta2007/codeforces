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
const int mod=1e9+7;
const lli inf=3e15;
const int dy[4]={-1,-1,1,1},dx[4]={-1,1,-1,1};

int n,k,c;
int main() {
	scanf("%d%d%d",&n,&k,&c);
	if(c>=k&&c<=n) {
		printf("%d\n",k);
	}
	else if(c<k) {
		printf("%d\n",c);
	}
	else {
		printf("%d\n",max(0,k-(c-n)));
	}
	
	return 0;
}