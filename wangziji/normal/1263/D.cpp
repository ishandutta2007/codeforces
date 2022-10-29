#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[1000005],fa[2000005],cnt[2000005],b[50],c[2000005];
char s[1000005];
inline int ff(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=ff(fa[x]);
}
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=0;i<=n+200;i++) fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		int l=strlen(s),f=0;
		for(int j=0;j<l;j++)
		{
			fa[ff(s[j]-'a')]=ff(i+100);
			cnt[s[j]-'a']=1;
		}
	}
	int ans=0;
	for(int i=0;i<=n+200;i++)
	{
		if(cnt[i]) ans+=!c[ff(i)],c[ff(i)]=1;
	}
	cout << ans;
	return 0;
}