#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,c[30],a[N],s[N],st[N],t,w,k,m;
char b[N];
void sol()
{
	scanf("%s",b+1);
	n=strlen(b+1);
	for(int i=0;i<26;i++)
		c[i]=0;
	t=m=w=k=0;
	for(int i=1;i<=n;i++)
	{
		s[i]=b[i]-'a';
		if(i>1&&s[i]==s[i-1])
			k++,c[s[i]]++;
	}
	for(int i=0;i<26;i++)
		m=max(m,c[i]);
	printf("%d\n",max((k+1)/2,m)+1);
	for(int i=1;i<=n;i++)
	{
		a[++w]=s[i];
		if(w<=1||a[w]!=a[w-1])
			continue;
		if(a[w]==a[st[t]]||!t)
		{
			st[++t]=w;
			continue;
		}
		m=0;
		for(int j=0;j<26;j++)
			if(c[j]>c[m])
				m=j;
		if(c[m]*2<k||m==a[w]||m==a[st[t]])
		{
			k-=2;
			c[a[w]]--;
			c[a[st[t]]]--;
			printf("%d %d\n",st[t],w-1);
			a[st[t]]=a[w];
			w=st[t];
			t--;
		}
		else
			st[++t]=w;
	}
	for(int l=w,i=w;i>=1;i--)
	{
		if(i==1||a[i-1]==a[i])
		{
			printf("%d %d\n",i,l);
			l=i-1;
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}