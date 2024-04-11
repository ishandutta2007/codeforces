#include <bits/stdc++.h>
using namespace std;
inline void solve(){
	int a,b,c;cin>>a>>b>>c;
	if(a>b+c)		printf("%d\n",c+1);
	else if(b>a+c)	puts("0");
	else{
		int n=(b+c-a)/2+1;
		cout<<(c-n+1)<<endl;
		//a+x>b+c-x
		//2*x>b+c-a
	}
}
int main(){
	int T;cin>>T;
	while(T--)	solve();
	return 0;
}