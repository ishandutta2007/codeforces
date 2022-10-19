#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
using namespace std;
int a[1001000],b[1000005],buf[1000005];
long long cnt_inv(int* f,int l,int r)
{
	if(r-l<=1) return 0;
	int m=(l+r)/2;
	long long ans=cnt_inv(f,l,m)+cnt_inv(f,m,r);
	int tl=l,tm=m,s=l;
	while(s<r){
		if(tl<m && (tm==r || f[tl]<=f[tm]))
		{
			ans+=tm-m;
			buf[s++]=f[tl++];
		}
		else buf[s++]=f[tm++];
	}
	for(int i=l;i<r;i++) f[i]=buf[i]; 
	return ans;
}
int main(){
	int t;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		int n,m;
		n=read();
		m=read();
		for(int i=0;i<n;i++)a[i]=read();
		for(int i=0;i<m;i++)b[i]=read();
		sort(b,b+m);
		priority_queue<int> pq;
		long long ans=0;
		for(int i=0;i<n;i++)
		{
			int l=lower_bound(b,b+m,a[i])-b;
			int r=upper_bound(b,b+m,a[i])-b;
			ans+=l;
			pq.push(l);
			pq.push(r);
			pq.pop();
		}
		for(int i=0;i<n;i++)
		{
			ans-=pq.top();
			pq.pop();
		}
		ans+=cnt_inv(a,0,n);
		printf("%lld\n",ans);
	}
	return 0;
}