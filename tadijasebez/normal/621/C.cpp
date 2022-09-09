#include <bits/stdc++.h>
using namespace std;
#define ldb long double
const int N=100050;
int l[N],r[N];
ldb p[N],ans;
void Solve(int x, int y)
{
	ans+=1000*(1-(1-p[x])*(1-p[y]));
}
int main()
{
	int n,P,i;
	scanf("%i %i",&n,&P);
	for(i=1;i<=n;i++)
	{
		scanf("%i %i",&l[i],&r[i]);
		int L=l[i],R=r[i]-r[i]%P;
		if(L%P) L+=P-L%P;
		int cnt=(R-L+1+P-1)/P;
		//printf("%i:%i\n",i,cnt);
		p[i]=(ldb)cnt/(r[i]-l[i]+1);
	}
	for(i=1;i<=n;i++) Solve(i,i==n?1:i+1);
	cout<<fixed<<setprecision(12)<<ans*2<<"\n";
	return 0;
}