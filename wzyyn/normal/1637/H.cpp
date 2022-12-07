#include<bits/stdc++.h>

using namespace std;

const int N=500005;
int n,a[N],t[N],c[N];
void change(int x,int v){
	for (;x<=n;x+=x&(-x)) t[x]+=v;
}
int ask(int x){
	int s=0;
	for (;x;x-=x&(-x)) s+=t[x];
	return s;
}
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		t[i]=0;
	long long bas=0;
	for (int i=1;i<=n;i++){
		int v=ask(a[i]);
		int dfr=(i-1-v)-v;
		int dback=2*(a[i]-1-v);
		c[i]=dfr-dback;
		bas+=i-1-v;
		change(a[i],1);
		//cout<<i<<' '<<c[i]<<' '<<i-2*a[i]+1<<endl;
	}
	sort(c+1,c+n+1,greater<int>());
	printf("%lld ",bas);
	for (int i=1;i<=n;i++){
		bas=bas-c[i]-(i-1);
		printf("%lld%c",bas,i==n?'\n':' ');
	}
	
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
(i,pi)->(j,pj)
*/