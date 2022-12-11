#include<bits/stdc++.h>
using namespace std;
int x,y;
int exgcd(int a,int b)
{
	if(!b)
	{
		x=1,y=0;
		return a;
	}
	int d=exgcd(b,a%b);
	int p=y,q=x-a/b*y;
	x=p,y=q;
	return d;
}
const int num=1e6;
const int max_num=1e6+5;
int pos_a[max_num],pos_b[max_num];
int main()
{
	int n,m;
	long long k;
	scanf("%d%d%lld",&n,&m,&k);
	for(int i=1;i<=n;++i)
	{
		int a;
		scanf("%d",&a);
		pos_a[a]=i;
	}
	for(int i=1;i<=m;++i)
	{
		int b;
		scanf("%d",&b);
		pos_b[b]=i;
	}
	int d=exgcd(n,m);
//	fprintf(stderr,"d=%d\n",d);
	int P=m/d;
//	fprintf(stderr,"x=%d y=%d\n",x,y);
	x=(x%P+P)%P;
	long long LCM=1ll*n/d*m;
//	fprintf(stderr,"LCM=%lld\n",LCM);
	vector<long long> t;
	for(int i=1;i<=num;++i)
	{
		int p=pos_a[i],q=pos_b[i]; 
		if(p&&q&&(q-p)%d==0)
		{
			long long X=1ll*(q-p)/d*x;
			X=(X%P+P)%P;
//			fprintf(stderr,"i=%d p=%d q=%d X=%lld\n",i,p,q,X);
			t.push_back(X*n+p);
		}
	}
	long long cnt=LCM-int(t.size());
	long long ans=k/cnt*LCM;
	k%=cnt;
	if(k==0)
	{
		k=cnt;
		ans-=LCM;
	}
	t.push_back(0);
	t.push_back(1ll*n*m+1);
	sort(t.begin(),t.end());
//	for(int i=0;i<int(t.size());++i)
//		printf("%lld%c",t[i],i+1<int(t.size())?' ':'\n');
	assert(t[0]==0&&t.back()==1ll*n*m+1);
	for(int i=0;i+1<int(t.size());++i)
	{
		long long l=t[i]+1,r=t[i+1]-1;
		if(k<=r-l+1)
		{
			printf("%lld\n",ans+l+k-1);
			return 0;
		}
		k-=r-l+1;
	}
	assert(false);
    return 0;
}