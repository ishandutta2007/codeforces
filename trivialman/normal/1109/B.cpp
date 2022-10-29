#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define repr(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 998244353;
const int N = 200010;

char s[5010];
int n=1;

bool check(char s[], int n){
	rep(i,1,n/2)if(s[n/2+1-i]!=s[(n+1)/2+i])return false;
	return true;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	scanf("%s",s+1);
	for(;s[n];++n);--n;
	
	bool flag = true;
	rep(i,2,n/2)if(s[i]!=s[i-1])flag=false;
	if(flag){
		printf("Impossible\n");
		return 0;
	}
	
	if(n%2){
		printf("2\n");
	}else{
		while(n%2==0 && check(s,n))n/=2;
		if(n%2==1 && check(s,n))printf("2\n");
		else printf("1\n");
	}
	return 0;
}