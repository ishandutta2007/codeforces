#include <iostream>
using namespace std;
int a[1005],qzh[1005],q[2005],head,tail,n;
inline int cal()
{
	for(int i=1;i<=n*2;i++)
		qzh[i]=qzh[i-1]+a[i];
	head=1,tail=0;
	int rtn=0;
	for(int i=1;i<=n;i++)
	{
		while(head<=tail&&qzh[q[tail]]>qzh[i]) --tail;
		q[++tail]=i;
	}
	for(int i=n+1;i<=n*2;i++)
	{
		while(head<=tail&&qzh[q[tail]]>qzh[i]) --tail;
		while(head<=tail&&q[head]<=i-n) ++head;
		q[++tail]=i;
		if(head<=tail&&qzh[q[head]]-qzh[i-n]==0&&qzh[i]-qzh[i-n]==0)++rtn;
	}
	return rtn;
}
int main(int argc, char** argv) {
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		char x;
		cin >> x;
		if(x=='(')
			a[i]=1;
		else
			a[i]=-1;
	}
	for(int i=n+1;i<=n*2;i++)
		a[i]=a[i-n];
	int ans=cal(),l=1,r=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]==a[j])
				continue;
			swap(a[i],a[j]);
			swap(a[i+n],a[j+n]);
			int t=cal();
			if(t>ans) ans=t,l=i,r=j;
			swap(a[i],a[j]);
			swap(a[i+n],a[j+n]);
		}
	}
	cout << ans << " " << l << " " << r;
	return 0;
}