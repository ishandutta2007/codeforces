#include<bits/stdc++.h>
using namespace std;
#define N 200010
#define MOD 998244353
#define LL long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)

int n;
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		if(x==180)cout<<-1<<endl;
		else if(180%(180-x)==0)cout<<180/gcd(x,180)*2<<endl;
		else cout<<180/gcd(x,180)<<endl;
	}
	return 0;
}