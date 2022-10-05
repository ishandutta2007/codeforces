#include<bits/stdc++.h>
using namespace std;
const int N=1<<18;
int segmax[2*N],segmin[2*N],n,a[N],b[N];
void buildmax()
{
	int i;
	for (i=N+n-1;i>=N;i--)
		segmax[i]=a[i-N+1];
	for (i=N-1;i>=1;i--)
		segmax[i]=max(segmax[i*2],segmax[i*2+1]);
}
void buildmin()
{
	int i;
	for (i=N+n-1;i>=N;i--)
		segmin[i]=b[i-N+1];
	for (i=N-1;i>=1;i--)
		segmin[i]=min(segmin[i*2],segmin[i*2+1]);
}
int searchmax(int left,int right)
{
	int m=INT_MIN,l,r;
	for (l=N+left-1,r=N+right;l<r;l/=2,r/=2)
	{
		if (l%2)
			m=max(m,segmax[l++]);
		if (r%2)
			m=max(m,segmax[--r]);
	}
	/*cout<<left<<" max "<<right<<endl;
	cout<<m<<endl;*/
	return m;
}
int searchmin(int left,int right)
{
	int m=INT_MAX,l,r;
	for (l=N+left-1,r=N+right;l<r;l/=2,r/=2)
	{
		if (l%2)
			m=min(m,segmin[l++]);
		if (r%2)
			m=min(m,segmin[--r]);
	}
	/*cout<<left<<" min "<<right<<endl;
	cout<<m<<endl;*/
	return m;
}
int main()
{
	int i,j,l,r,mid,left,right;
	long long ans=0;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for (i=1;i<N<<1;i++)
	{
		segmax[i]=INT_MIN;
		segmin[i]=INT_MAX;
	}
	buildmax();
	buildmin();
	for (i=1;i<=n;i++)
	{
		l=i;
		r=n;
		while (l<r)
		{
			mid=(l+r)/2+1;
			if (searchmax(i,mid)<searchmin(i,mid))
				l=mid;
			else
				r=mid-1;
		}
		if (searchmax(i,l)>=searchmin(i,l))
			l--;
		left=l;
		//cout<<left<<endl;
		l=i;
		r=n;
		while (l<r)
		{
			mid=(l+r)/2;
			if (searchmax(i,mid)>searchmin(i,mid))
				r=mid;
			else
				l=mid+1;
		}
		if (searchmax(i,l)<=searchmin(i,l))
			l++;
		right=l;
		//cout<<right<<endl;
		ans+=right-left-1;
	}
	printf("%I64d",ans);
	return 0;
}