#include<bits/stdc++.h>
using namespace std;
#define N 200010
#define LL long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)

int n;
int a[N];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",a+i);
	sort(a+1,a+n+1);
	cout<<min(a[n]-a[2],a[n-1]-a[1])<<endl;
	return 0;
}