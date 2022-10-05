#include <bits/stdc++.h>
using namespace std;
const int Maxn=100005;
int n,a[Maxn],sam[Maxn],tot[Maxn],b[Maxn],ct;
vector <int> Ve[Maxn];
int main()
{
//	freopen("B.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sam[i]=n-a[i];
		tot[sam[i]]++;
		Ve[sam[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		if(!tot[i]) continue;
		if(tot[i]%i)
		{
			printf("Impossible");
			return 0;
		}
		else
		{
			int cnt=0;
			ct++;
			for(vector <int>::iterator it=Ve[i].begin();it!=Ve[i].end();it++)
			{
				if(cnt==i) cnt=0,ct++;
				b[*it]=ct;
				cnt++;
			}
		}
	}
	printf("Possible\n");
	for(int i=1;i<=n;i++)
		printf("%d ",b[i]);
	return 0;
}