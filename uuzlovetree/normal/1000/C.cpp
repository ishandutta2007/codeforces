#include<bits/stdc++.h>
#define maxn 400005
#define ll long long
using namespace std;
int n;
ll l[maxn],r[maxn];
ll num,b[maxn];
ll L[maxn],R[maxn];
ll c[maxn];
ll cnt[maxn];
ll A[maxn],B[maxn];
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)scanf("%I64d%I64d",&l[i],&r[i]),b[++num]=l[i],b[++num]=r[i];
	sort(b+1,b+num+1);
	num=unique(b+1,b+num+1)-b-1;
	for(int i=1;i<=n;++i)
	{
		L[i]=lower_bound(b+1,b+num+1,l[i])-b;
		R[i]=lower_bound(b+1,b+num+1,r[i])-b;
	}
	for(int i=1;i<=n;++i)c[L[i]]++,c[R[i]+1]--,A[L[i]]++,B[R[i]+1]++;
	for(int i=1;i<=num;++i)c[i]+=c[i-1];
	for(int i=1;i<=num;++i)
	{
		cnt[c[i]]+=1;
		cnt[c[i]-A[i]]+=b[i]-b[i-1]-1;
	}
	for(int i=1;i<=n;++i)printf("%I64d ",cnt[i]);
	return 0;
}