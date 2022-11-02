#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200005;
mt19937 rd(time(0));
vector<int> v;
int n,a[N];
void solve(int x){
	if (x<=0)return;
	for (int i=2;i*i<=x;i++)
		if (x%i==0){
			while (x%i==0)x/=i;
			v.push_back(i);
		}
	if (x>1)v.push_back(x);
}
int calc(int x){
	int ans=0;
	for (int i=1;i<=n;i++)
		if (a[i]>=x)ans+=min(a[i]%x,x-a[i]%x);
		else ans+=x-a[i];
	return ans;
}
signed main(){
	scanf("%lld",&n);
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	int ans=n;
	for (int t=1;t<=20;t++){
		int x=rd()%n+1,y=rd()%n+1;
		if (a[x]==a[y]){
			solve(a[x]);
			solve(a[x]-1);
			solve(a[x]+1);
			continue;
		}
		int tt=abs(a[x]-a[y]);
		solve(tt);
		solve(tt+1);
		solve(tt+2);
		solve(tt-1);
		solve(tt-2);
	}
	sort(v.begin(),v.end());
	for (int i=0;i<v.size();i++)
		if (i!=0||v[i]!=v[i-1])ans=min(ans,calc(v[i]));
	printf("%lld\n",ans);
}