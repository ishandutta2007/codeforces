#include<bits/stdc++.h>
using namespace std;
int N,A,R,M;
const int max_N=1e5+5;
int h[max_N];
long long sum[max_N];
inline long long calc(int H)
{
	int p=upper_bound(h+1,h+N+1,H)-h-1;
	long long X=1ll*p*H-sum[p],Y=(sum[N]-sum[p])-1ll*(N-p)*H,c=min(X,Y);
	return A*(X-c)+R*(Y-c)+M*c;
}
int main()
{
	scanf("%d%d%d%d",&N,&A,&R,&M);
	M=min(M,A+R);
	for(int i=1;i<=N;++i)
		scanf("%d",h+i);
	sort(h+1,h+N+1);
	for(int i=1;i<=N;++i)
		sum[i]=sum[i-1]+h[i];
	int l=h[1],r=h[N];
	while(l<r)
	{
		int lmid=l+(r-l)/3,rmid=r-(r-l)/3;
		if(calc(lmid)<calc(rmid))
			r=rmid-1;
		else
			l=lmid+1;
	}
	printf("%lld\n",calc(l));
	return 0;
}