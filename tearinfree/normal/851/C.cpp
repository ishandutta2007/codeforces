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
const double PI=acos(-1);

struct vec{
	lli x[5];
	vec() {}
	vec(lli xx[5]) {
		for(int i=0;i<5;i++) x[i]=xx[i];
	}
	vec operator-(const vec &rhs) const {
		vec res;
		for(int i=0;i<5;i++) res.x[i]=x[i]-rhs.x[i];
		return res;
	}
	lli inner(const vec &rhs) const {
		lli res=0;
		for(int i=0;i<5;i++) res+=x[i]*rhs.x[i];
		return res;
	}
	lli length() {
		lli res=0;
		for(int i=0;i<5;i++) res+=x[i]*x[i];
		return sqrt(res);
	}
}arr[1000];
int n;
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		for(int j=0;j<5;j++) {
			scanf("%lld",&arr[i].x[j]);
		}
	}
	if(n>15) {
		puts("0");
		return 0;
	}
	vector<int> res;
	for(int i=0;i<n;i++) {
		bool flag=true;
		for(int j=0;j<n;j++) {
			if(i==j) continue;
			for(int k=0;k<n;k++) {
				if(i==k||j==k) continue;
				vec v1=arr[k]-arr[i], v2=arr[j]-arr[i];
				lli val=v1.inner(v2);
				if(val>0) {
					flag=false;
					break;
				}
			}
			if(!flag) break;
		}
		if(flag) res.push_back(i+1);
	}
	int s=(int)res.size();
	printf("%d\n",s);
	for(auto &it:res) printf("%d ",it);
	
	return 0;
}