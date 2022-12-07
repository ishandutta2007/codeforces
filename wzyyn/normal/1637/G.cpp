#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int> > ans;
int a[25],n;
void solve(int n,int d){
	if (!n)
		return;
	int D=0;
	for (;(1<<D)<n;D++);
	if (n==(1<<D)){
		++a[d+D];
		solve(n-1,d);
		return;
	}
	--D;
	++a[d+D]; //(1<<D);
	for (int i=(1<<D)+1;i<=n;i++){
		int j=(2<<D)-i;
		ans.push_back(pair<int,int>(i<<d,j<<d));
		++a[d+1+D];
	}
	solve((2<<D)-(n+1),d);
	solve(n-(1<<D),d+1);
}
void solve(){
	scanf("%d",&n);
	if (n==2) return puts("-1"),void(0);
	ans.resize(0);
	for (int i=0;i<=20;i++) a[i]=0;
	solve(n,0);
	int d=0;
	for (;a[d]<2;++d);
	assert((1<<d)<n);
	ans.push_back(pair<int,int>(1<<d,1<<d));
	a[d]-=2; ++a[d+1];
	for (d=0;(1<<d)<n;d++);
	for (int i=0;i<d;i++)
		for (;a[i];){
			ans.push_back(pair<int,int>(0,1<<i));
			ans.push_back(pair<int,int>(1<<i,1<<i));
			--a[i]; ++a[i+1];
		}
	ans.push_back(pair<int,int>(0,1<<d));
	printf("%d\n",ans.size());
	for (auto i:ans)
		printf("%d %d\n",i.first,i.second);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
7
1 2 3 4 5 6 7
(4) + (8 8 8) + (2 4 6)
8 8 8 8 4 4 4 
*/