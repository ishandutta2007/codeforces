#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int mod=998244353;
template<int mod=::mod>ll quickpow(ll x,int k,ll ret=1){
	for(; k; k>>=1,x=x*x%mod)
		(k&1)&&(ret=ret*x%mod);
	return ret;
}
constexpr int max_n=200000;
vector<int> a[max_n+1];
void test(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i){
		a[i].resize(m+1);
		for(int j=1; j<=m; ++j)
			scanf("%d",&a[i][j]);
	}
	int lft=0,rgt=0;
	vector<int>t;
	for(int i=1; i<=n; ++i){
		t=a[i];
		sort(t.data()+1,t.data()+m+1);
		int l=0,r=0;
		for(int j=1; j<=m; ++j)
			if(a[i][j]!=t[j]){
				if(l)
					if(r){
						puts("-1");
						return;
					}
					else
						r=j;
				else
					l=j;
			}
		if(l){
			a[i][0]=0;
			if(lft){
				if(l!=lft||r!=rgt){
					puts("-1");
					return;
				}
			}
			else
				lft=l,rgt=r;
		}
		else
			a[i][0]=1;
	}
	if(lft){
		for(int i=1; i<=n; ++i)
			if(a[i][0]&&a[i][lft]!=a[i][rgt]){
				puts("-1");
				return;
			}
	}
	else
		lft=1,rgt=1;
	printf("%d %d\n",lft,rgt);
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}