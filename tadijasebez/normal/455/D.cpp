#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,avx,mmx,popcnt,tune=native")
#include <stdio.h>
#include <deque>
using namespace std;
const int S=317;
const int N=100050;
int Cnt[S][N],n,a[N];
deque<int> q[S];
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
void Clear(int B)
{
	int l=max(1,B*S),i;
	int r=min(n,B*S+S-1);
	for(i=l;i<=r;i++) a[i]=q[B].front(),q[B].pop_front(),Cnt[B][a[i]]--;
}
void Build(int B)
{
	int l=max(1,B*S),i;
	int r=min(n,B*S+S-1);
	for(i=l;i<=r;i++) q[B].push_back(a[i]),Cnt[B][a[i]]++;
}
void Swap(int &a, int &b){ a^=b;b^=a;a^=b;}
int main()
{
	int t,l,r,k,x,i,j=0;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=0;i*S<=n;i++) Build(i);
	scanf("%i",&k);
	int last=0;
	while(k--)
	{
		scanf("%i %i %i",&t,&l,&r);
		l=(l+last-1)%n+1;r=(r+last-1)%n+1;
		if(l>r) Swap(l,r);
		int L=l/S;
		int R=r/S;
		if(t==1)
		{
			if(L==R)
			{
				Clear(L);
				int tmp=a[r];
				for(i=r;i>l;i--) a[i]=a[i-1];
				a[l]=tmp;
				Build(L);
			}
			else
			{
				Clear(L);
				int las=L*S+S-1;
				int tmp=a[las];
				for(i=las;i>l;i--) a[i]=a[i-1];
				Clear(R);
				a[l]=a[r];
				Build(L);
				for(i=L+1;i<R;i++)
				{
					Cnt[i][tmp]++;
					q[i].push_front(tmp);
					tmp=q[i].back();
					Cnt[i][tmp]--;
					q[i].pop_back();
				}
				for(i=r;i>R*S;i--) a[i]=a[i-1];
				a[R*S]=tmp;
				Build(R);
			}
		}
		else
		{
			j++;
			scanf("%i",&x);x=(x+last-1)%n+1;
			last=0;
			if(L==R)
			{
				Clear(L);
				Build(L);
				for(i=l;i<=r;i++) if(a[i]==x) last++;
			}
			else
			{
				Clear(L);
				Build(L);
				for(i=l;i<(L+1)*S;i++) if(a[i]==x) last++;
				for(i=L+1;i<R;i++) last+=Cnt[i][x];
				Clear(R);
				Build(R);
				for(i=R*S;i<=r;i++) if(a[i]==x) last++;
			}
			printf("%i\n",last);
		}
	}
	return 0;
}