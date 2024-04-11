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
int n,m,q,a[200005],rs;
int main()
{
	read(n),read(m),rs=n;
	for(int i=1,x,y;i<=m;i++) read(x),read(y),(x>y?swap(x,y),0:0),a[x]++,rs-=(a[x]==1);
	for(read(q);q--;)
	{
		int f,x,y;read(f);if(f^3) read(x),read(y),(x>y?swap(x,y),0:0);
		if(f==1) a[x]++,rs-=a[x]==1;
		if(f==2) a[x]--,rs+=a[x]==0;
		if(f==3) printf("%d\n",rs);
	}
	return 0;
}