#include <stdio.h>
const int N=200050;
const int M=200*N;
int sum[M],ls[M],rs[M],clock,root[N];
void Set(int &c, int ss, int se, int qi, int val)
{
	if(!c) c=++clock;
	sum[c]+=val;
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
}
void Set(int x, int y, int val){ for(;x<N;x+=x&-x) Set(root[x],1,N,y,val);}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se) return sum[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
int Get(int x, int qs, int qe){ int ret=0;for(;x;x-=x&-x) ret+=Get(root[x],1,N,qs,qe);return ret;}
int Get(int x1, int y1, int x2, int y2){ return Get(x2,y1,y2)-Get(x1-1,y1,y2);}
#define ll long long
ll sol;
int p[N];
void Swap(int &a, int &b){ a^=b;b^=a;a^=b;}
int main()
{
	int n,i,q,a,b;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++) Set(i,i,1),p[i]=i;
	while(q--)
	{
		scanf("%i %i",&a,&b);
		if(a==b)
		{
			printf("%lld\n",sol);
			continue;
		}
		if(a>b) Swap(a,b);
		sol-=Get(1,p[a]+1,a-1,N);
		sol-=Get(a+1,1,N,p[a]-1);
		sol-=Get(1,p[b]+1,b-1,N);
		sol-=Get(b+1,1,N,p[b]-1);
		if(p[a]>p[b]) sol++;
		Set(a,p[a],-1);
		Set(b,p[b],-1);
		Set(b,p[a],1);
		Set(a,p[b],1);
		Swap(p[a],p[b]);
		sol+=Get(1,p[a]+1,a-1,N);
		sol+=Get(a+1,1,N,p[a]-1);
		sol+=Get(1,p[b]+1,b-1,N);
		sol+=Get(b+1,1,N,p[b]-1);
		if(p[a]>p[b]) sol--;
		printf("%lld\n",sol);
	}
	return 0;
}