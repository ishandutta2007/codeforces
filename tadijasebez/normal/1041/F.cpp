#include <bits/stdc++.h>
using namespace std;
const int N=100050;
const int inf=1e9+7;
int a[N],b[N];
map<int,int> cnt;
int Try(int mod, int n, int m)
{
	int ans=0;cnt.clear();
	for(int i=1;i<=n;i++) cnt[a[i]%mod]++,ans=max(ans,cnt[a[i]%mod]);
	for(int i=1;i<=m;i++) cnt[(b[i]+mod/2)%mod]++,ans=max(ans,cnt[(b[i]+mod/2)%mod]);
	//printf("%i -> %i\n",mod,ans);
	return ans;
}
int main()
{
    int n,m,i,y;
    scanf("%i %i",&n,&y);
    for(i=1;i<=n;i++) scanf("%i",&a[i]);
    scanf("%i %i",&m,&y);
    for(i=1;i<=m;i++) scanf("%i",&b[i]);
    int sol=2;
    for(i=2;i<inf;i*=2) sol=max(sol,Try(i,n,m));
    sol=max(sol,Try(i,n,m));
    cnt.clear();
    for(i=1;i<=n;i++) cnt[a[i]&1]++;
    for(i=1;i<=m;i++) cnt[(b[i]&1)^1]++;
    sol=max(sol,cnt[0]);
    sol=max(sol,cnt[1]);
	printf("%i\n",sol);
	return 0;
}