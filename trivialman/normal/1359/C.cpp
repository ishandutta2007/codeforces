#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int,2> 
#define vs vector<string>
typedef long long LL;
const LL P = 998244353;
const int N = 531450;
mt19937 rng(time(0));

int T, n;
double h, c, t;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	cout<<fixed<<setprecision(3);
	
	cin>>T;
	while(T--){
		scanf("%lf%lf%lf", &h, &c, &t);
		double t1 = (h+c)/2.0, diff = h-c;
		if(t <= t1){
			cout<<"2\n"; continue;
		}
		
		int x = diff / (t-t1), y = (x-2)/4*4+2, z = y+4;
		//cout<<diff<<" "<<t1<<" "<<x<<" "<<y<<" "<<z<<endl;
		//cout<<t1+diff/y<<" "<<t1+diff/z<<endl;
		
		if (abs(t1+diff/y-t) <= abs(t1+diff/z-t))
			printf("%d\n", y/2);
		else printf("%d\n", z/2);
	}
	
	return 0;
}