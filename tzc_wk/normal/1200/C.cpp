#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,x;
signed main(){
	cin>>n>>m>>k;
	x=__gcd(n,m);
//	cout<<x<<endl;
	while(k--){
		int sx,sy,ex,ey;
		cin>>sx>>sy>>ex>>ey;
		int a,b;
		if(sx==1)	a=(sy-1)/(n/x);
		else		a=(sy-1)/(m/x);
		if(ex==1)	b=(ey-1)/(n/x);
		else		b=(ey-1)/(m/x);
		if(a==b)	puts("YES");
		else		puts("NO");
	}
	return 0;
}