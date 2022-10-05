#include <bits/stdc++.h>
using namespace std;
const int p=1e9+7;
int n,l,r;
long long t[4],ans[4]={1},cnt[4];
int main()
{
//	freopen("C.in","r",stdin);
	scanf("%d%d%d",&n,&l,&r);
	int d=(r-l+1)/3;
	l+=d*3;
	cnt[0]+=d,cnt[1]+=d,cnt[2]+=d;
	for(int i=l;i<=r;i++) cnt[i%3]++;
	for(int i=1;i<=n;i++)
	{
		t[1]=(ans[0]*cnt[1]%p+ans[2]*cnt[2]%p+ans[1]*cnt[0]%p)%p;
		t[2]=(ans[1]*cnt[1]%p+ans[0]*cnt[2]%p+ans[2]*cnt[0]%p)%p;
		t[0]=(ans[0]*cnt[0]%p+ans[1]*cnt[2]%p+ans[2]*cnt[1]%p)%p;
		ans[1]=t[1];
		ans[2]=t[2];
		ans[0]=t[0];
	}
	printf("%d",ans[0]);
	return 0;
}