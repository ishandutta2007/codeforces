#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int gcd(int a,int b) {
	if(b==0) return a;
	return gcd(b,a%b);
}
int lap(int x1,int y1,int x2,int y2) {
	if(y1<x2 || y2<x1) return 0;
	return min(y1,y2) - max(x1,x2) + 1;
}
int main() {
	//freopen("in.txt","r",stdin);
	int l1,r1,t1,l2,r2,t2;
	cin>>l1>>r1>>t1>>l2>>r2>>t2;
	int k = gcd(t1,t2);
	int la = l1 % k, ra = la + r1 - l1;
	int lb = l2 % k, rb = lb + r2 - l2;
	int res = 0;
	res = max(res,lap(la,ra,lb,rb));
	res = max(res,lap(la+k,ra+k,lb,rb));
	res = max(res,lap(la-k,ra-k,lb,rb));
	cout << res << endl;
}