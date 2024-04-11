//
//%4
//
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
const int vl[16][3]={{0,0,0},{0,0,1},{0,0,2},{0,0,3},{0,1,1},{0,2,2},{0,3,3},{1,1,1},{1,1,2},{1,1,3},{1,2,2},{1,3,3},{2,2,2},{2,2,3},{2,3,3},{3,3,3}};
int n;ll a[10005],b[10005][2],res;
signed main()
{
	read(n);for(int i=1;i<=n;i++) read(b[i][0]),read(b[i][1]),a[b[i][0]/2%2*2+b[i][1]/2%2]++;
	for(int i=0;i<16;i++)
	{
		if(vl[i][0]==vl[i][1]&&vl[i][1]==vl[i][2]) res+=1ll*a[vl[i][0]]*(a[vl[i][0]]-1)*(a[vl[i][0]]-2)/6;
		else if(vl[i][0]==vl[i][1]) res+=1ll*a[vl[i][0]]*(a[vl[i][0]]-1)/2*a[vl[i][2]];
		else if(vl[i][1]==vl[i][2]) res+=1ll*a[vl[i][1]]*(a[vl[i][1]]-1)/2*a[vl[i][0]];
		else res+=1ll*a[vl[i][0]]*a[vl[i][1]]*a[vl[i][2]];
	}
	return printf("%lld\n",res),0;
}