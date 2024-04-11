#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
using namespace std;
long long s[1000020];
int c[1000020];
int l[1000020];
int r[1000020];
int N,n,i,j,k,m;
int x,y,z,o,csc;
int v[1000020];
int f[1000020];
void pd(int idx)
{
	if(idx>=N)
	{
		s[idx]=f[s[idx]];
		if (s[idx] <= 2) {
			c[idx] = 1;
		}
		return;
	}
	if(c[idx]==r[idx]-l[idx]+1)
		return;
	pd(idx*2);
	pd(idx*2+1);
	s[idx]=s[idx*2]+s[idx*2+1];
	c[idx]=c[idx*2]+c[idx*2+1];
}
long long qy(int idx)
{
	if(x<=l[idx]&&y>=r[idx])
		return s[idx];
	if(x>r[idx]||y<l[idx])
		return 0;
	return qy(idx*2)+qy(idx*2+1);
}
void ud(int idx)
{
	if(x<=l[idx]&&y>=r[idx])
	{
		pd(idx);
		return;
	}
	if(x>r[idx]||y<l[idx])
		return;
	ud(idx*2);
	ud(idx*2+1);
	s[idx]=s[idx*2]+s[idx*2+1];
	c[idx]=c[idx*2]+c[idx*2+1];
}
int main()
{
	for (int i = 2; i <= 1000000; i++) {
		if (v[i] > 0) {
			continue;
		}
		for (int j = i; j <= 1000000; j += i) {
			v[j] = i;
		}
	}
	f[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		if (v[i] == v[i / v[i]]) {
			f[i] = f[i / v[i]] * 2 - f[i / v[i] / v[i]];
		} else {
			f[i] = f[i / v[i]] * 2;
		}
	}
	scanf("%d%d", &n, &m);
	memset(s,0,sizeof(s));
	for(N=n;N!=(N&(-N));N+=(N&(-N)));
	for(i=N;i<N+n;i++)
		scanf("%lld",&s[i]);
	for(i=N;i<N*2;i++)
		r[i]=l[i]=i-N+1;
	for(i=N-1;i>0;i--)
	{
		s[i]=s[i*2]+s[i*2+1];
		l[i]=l[i*2];
		r[i]=r[i*2+1];
	}
	while(m--)
	{
		scanf("%d",&o);
		scanf("%d %d",&x,&y);
		if(x>y)
			swap(x,y);
		if(o==2)
			printf("%lld\n",qy(1));
		else
			ud(1);
	}
	return 0;
}