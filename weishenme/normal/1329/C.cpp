#include<bits/stdc++.h>
using namespace std;
const int N=21;
int a[1<<N|1],T,n,m;
vector<int> ans;
int check(int x){
	if (!a[x<<1]&&!a[x<<1|1])return (x>=(1<<(m)));
	if (a[x<<1]>a[x<<1|1])return check(x<<1);
	return check(x<<1|1);
}
void del(int x){
	a[x]=0;
	if (!a[x<<1]&&!a[x<<1|1])return;
	if (a[x<<1]>a[x<<1|1])a[x]=a[x<<1],del(x<<1);
	else a[x]=a[x<<1|1],del(x<<1|1);
}
void solve(int x){
	while (check(x))ans.push_back(x),del(x);
	if (x>=(1<<(m-1)))return;
	solve(x<<1);solve(x<<1|1);
}
int main(){
	scanf("%d",&T);
	while (T--){
		ans.clear();
		scanf("%d%d",&n,&m);
		for (int i=1;i<1<<n;i++)scanf("%d",&a[i]);
		solve(1);
		long long s=0;
		for (int i=1;i<1<<m;i++)s+=a[i];
		printf("%lld\n",s);
		for (int i:ans)printf("%d ",i);
		puts("");
		for (int i=1;i<1<<n;i++)a[i]=0;
	}
}