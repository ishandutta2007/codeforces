#include <bits/stdc++.h>
using namespace std;
int n,k,l,a[100005],pnt,qu,cnt; 
int main()
{
	//freopen("C.in","r",stdin);
	scanf("%d%d%d",&n,&k,&l);
	for(int i=1;i<=n*k;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n*k);
	for(int i=2;i<=n;i++)
		if(a[i]-a[1]>l){printf("0");return 0;} 
	for(int i=1;i<=n*k;i++)
		if(a[i]-a[1]<=l){pnt=i;}
		else break;
	qu=pnt-n;
	cnt=n;
	long long ans=0;
	for(int i=1;i<=pnt;i++)
	{
		ans+=a[i];
		cnt--;
		if(pnt-(i+k-1)>cnt) i+=k-1;
		else 
			for(int j=pnt;j>=1;j--)
			{
				if(cnt>0) ans+=a[j];
				else goto A;
				cnt--;
			}
	}
	A:printf("%I64d",ans);
	return 0;
}