#include<bits/stdc++.h>
using namespace std;

const int N=200005;
int n,l,r,ans;
int a[N],s1[N],s2[N];
vector<int> v1,v2;
void solve(){
	scanf("%d%d%d",&n,&l,&r);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	
	v1.resize(0);
	v2.resize(0);
	for (int i=1;i<=n;i++)
		if (i<=l) v1.push_back(a[i]);
		else v2.push_back(a[i]);
	
	if (v1.size()<v2.size())
		swap(v1,v2);
	for (int i=1;i<=n;i++)
		s1[i]=s2[i]=0;
	for (auto i:v1)
		++s1[i];
	for (auto i:v2)
		++s2[i];
	int ans=0;
	int delta=v1.size()-v2.size();
	for (int i=1;i<=n;i++)
		for (;s1[i]-s2[i]>=2&&delta;)
			--s1[i],++s2[i],delta-=2,++ans;
	for (int i=1;i<=n;i++)
		for (;s1[i]-s2[i]>=1&&delta;)
			--s1[i],++s2[i],delta-=2,++ans;
	ans+=n/2;
	for (int i=1;i<=n;i++)
		ans-=min(s1[i],s2[i]);
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}