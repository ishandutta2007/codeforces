//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int n,q,a[100005],nx[100005][20],ls[100005],p[100005],pc;char v[100005];
vector<int>fc[100005];int vl[100005];
inline void init()
{
	v[1]=1;for(int i=1;i<=100000;i++)
	{
		if(!v[i]) p[++pc]=i,ls[i]=i;
		for(int j=1;j<=pc&&i*p[j]<=100000;j++) {ls[i*p[j]]=p[j],v[i*p[j]]=1;if(i%p[j]==0) break;}
	}
	for(int i=1;i<=pc;i++) for(int j=p[i];j<=100000;j+=p[i]) fc[j].push_back(i);
}
int main()
{
	read(n),read(q),init();for(int i=1;i<=n;i++) read(a[i]);
	int k=0;for(int i=1;i<=n;nx[i][0]=k--,i++)
	{
		if(i^1) for(int j:fc[a[i-1]]) vl[j]--;
		while(k<=n)
		{
			char fg=0;k++;if(k==n+1) break;
			for(int j:fc[a[k]]) vl[j]++;
			for(int j:fc[a[k]]) if(vl[j]==2) fg=1;
			if(fg) {for(int j:fc[a[k]]) vl[j]--;break;}
		}
	}
//	for(int i=1;i<=n;i++) printf("%d%c",nx[i][0],i==n?'\n':' ');
	nx[n+1][0]=n+1;for(int k=1;k<20;k++)
		{nx[n+1][k]=n+1;for(int i=1;i<=n;i++) nx[i][k]=nx[nx[i][k-1]][k-1];}
	for(int l,r,rs;q--;printf("%d\n",rs+1))
	{
		read(l),read(r),rs=0;int x=l;
		for(int k=19;~k;k--) if(nx[x][k]<=r) rs+=1<<k,x=nx[x][k];
	}
	return 0;
}