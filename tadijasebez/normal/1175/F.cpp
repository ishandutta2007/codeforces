#include <bits/stdc++.h>
using namespace std;
#define ll long long
void ckmx(int &x,int y){x=max(x,y);}
const int N=300050;
ll hsh[N],phs[N],lhs[N],rhs[N];
int a[N],ans;
void Solve(int l,int r){
	if(l==r){ans+=a[l]==1;return;}
	int mid=l+r>>1;
	lhs[mid+1]=0;
	for(int i=mid;i>=l;i--)lhs[i]=lhs[i+1]^hsh[a[i]];
	rhs[mid]=0;
	int mx=0;
	for(int i=mid+1;i<=r;i++)rhs[i]=rhs[i-1]^hsh[a[i]],ckmx(mx,a[i]),ans+=i-mx+1<=mid&&i-mx+1>=l&&phs[mx]==(rhs[i]^lhs[i-mx+1]);
	mx=0;
	for(int i=mid;i>=l;i--)ckmx(mx,a[i]),ans+=i+mx-1<=r&&i+mx-1>mid&&phs[mx]==(lhs[i]^rhs[i+mx-1]);
	Solve(l,mid);Solve(mid+1,r);
}
int main(){
	int n;
	scanf("%i",&n);
	mt19937_64 rng(time(0));
	for(int i=1;i<=n;i++)hsh[i]=rng(),phs[i]=phs[i-1]^hsh[i];
	for(int i=1;i<=n;i++)scanf("%i",&a[i]);
	Solve(1,n);
	printf("%i\n",ans);
	return 0;
}