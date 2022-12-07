#include<bits/stdc++.h>

using namespace std;

const int N=200005;
int n,a[N];
void solve(){
	int x,y;
	scanf("%d%d",&x,&y);
	int ans;
	if (y<x) ans=x+y;
	else if (y==x) ans=x;
	else{
		int v=y/x*x;
		ans=(v+y)/2;
	}
	assert(ans%x==y%ans);
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}