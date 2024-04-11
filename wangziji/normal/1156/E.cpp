#include <iostream>
#include <cstdio>
using namespace std;
int a[200005],l[200005],r[200005],s[200005],cnt,s2[200005],b[200005],pos[200005];
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		pos[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		while(cnt&&s[cnt]<a[i])
			--cnt;
		l[i]=s2[cnt];
		s[++cnt]=a[i];
		s2[cnt]=i;
	}
	cnt=0;
	for(int i=n;i>=1;i--)
	{
		while(cnt&&s[cnt]<a[i])
			--cnt;
		r[i]=s2[cnt];
		s[++cnt]=a[i];
		s2[cnt]=i;
		if(!r[i])
			r[i]=n+1;
		++l[i],--r[i];
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		if(i-l[i]<r[i]-i)
		{
			for(int j=i;j>=l[i];j--)
				ans+=(pos[a[i]-a[j]]<=r[i]&&pos[a[i]-a[j]]>i);
		}
		else
		{
			for(int j=r[i];j>=i;j--)
				ans+=(pos[a[i]-a[j]]<=i&&pos[a[i]-a[j]]>=l[i]);
		}
	}
	cout << ans;
	return 0;
}