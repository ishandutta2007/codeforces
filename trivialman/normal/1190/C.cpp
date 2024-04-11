#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 998244353;
const int N = 1e5+10;

int n,k,a[N],b[N],s[N];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%d%d\n",&n,&k);
	rep(i,1,n)scanf("%c",a+i);
	rep(i,1,n)a[i]-=48;
	s[0]=0;
	rep(i,1,n)s[i]=s[i-1]+a[i];
	bool flag = false;
	rep(i,1,n-k+1){
		int sum = s[n]-s[i+k-1] + s[i-1];
		if(sum==0||sum==n-k)flag = true;
	}
	if(flag){
		printf("tokitsukaze\n");
		return 0;
	}
	
	int l0=n,l1=n,r0=1,r1=1;
	rep(i,1,n)
		if(a[i]==0){
			l0=min(i,l0);
			r0=max(i,r0);
		}else{
			l1=min(i,l1);
			r1=max(i,r1);
		}
	if(r0-l0<=k && r1-l1<=k &&(l0<r1 && l1<r0)){
		printf("quailty\n");
		return 0;
	}
	
	printf("once again\n");
	return 0;
}