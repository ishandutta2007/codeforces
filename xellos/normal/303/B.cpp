// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define uint unsigned int
#define ff first
#define ss second
// mylittlepony
using namespace std;

long long GCD(long long a, long long b) {
	if(a > b) swap(a,b);
	if(a == 0) return b;
	return GCD(b%a,a);}

long long N,M,X,Y,A,B;

struct rect {
	long long x1,y1,x2,y2;
	
	rect(long long a, long long b, long long c, long long d) {
		x1 =a, y1 =b, x2 =c, y2 =d;}
	
	bool operator<(const rect &r) const {
		long long d1 =((y1+y2)-2*Y)*((y1+y2)-2*Y)+((x1+x2)-2*X)*((x1+x2)-2*X);
		long long d2 =((r.y1+r.y2)-2*Y)*((r.y1+r.y2)-2*Y)+((r.x1+r.x2)-2*X)*((r.x1+r.x2)-2*X);
		if(d1 != d2) return d1 < d2;
		if(x1 != r.x1) return x1 < r.x1;
		if(y1 != r.y1) return y1 < r.y1;
		if(x2 != r.x2) return x2 < r.x2;
		return y2 < r.y2;}
	};

int main() {
	cin >> N >> M >> X >> Y >> A >> B;
	long long d =GCD(A,B);
	A /=d, B /=d;
	
	long long kc =min(M/B,N/A);
	long long a =kc*A, b =kc*B;
	long long q =max(0LL,X-a+a/2), r =max(0LL,Y-b+b/2);
	if(q+a > N) q =N-a;
	if(r+b > M) r =M-b;
	rect r1(q,r,q+a,r+b);
	cout << r1.x1 << " " << r1.y1 << " " << r1.x2 << " " << r1.y2 << endl;
	return 0;}
        
// look at my code
// my code is amazing