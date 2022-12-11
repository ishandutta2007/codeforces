#include<bits/stdc++.h>
#define ll long long
#define maxn 100005
using namespace std;
int n;
struct data
{
	int a,b,c;
}A[maxn];
bool operator < (data A,data B)
{
	return A.c>B.c;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&A[i].a,&A[i].b),A[i].c=A[i].a-A[i].b;
	sort(A+1,A+n+1);
	ll ans=0;
	for(int i=1;i<=n;++i)ans+=1ll*A[i].c*i+1ll*A[i].b*n-1ll*A[i].a;
	cout<<ans<<endl;
	return 0;
}