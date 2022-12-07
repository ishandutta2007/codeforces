#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=100005;
char a[N],b[N];
int A[N],B[N],n,T=100000;
ll ans;
void work(int x,int d){
	if (d==-1){
		if (!A[x]||!A[x+1])
			work(x+1,1);
		if ((--T)>=0)
			printf("%d %d\n",x,-1);
		--A[x]; --A[x+1];
	}
	else{
		if (A[x]==9||A[x+1]==9)
			work(x+1,-1);
		if ((--T)>=0)printf("%d %d\n",x,1);
		++A[x]; ++A[x+1];
	}
}
int main(){
	scanf("%d%s%s",&n,a+1,b+1);
	For(i,1,n) A[i]=a[i]-'0',B[i]=b[i]-'0';
	For(i,1,n-1){
		int d=A[i]-B[i];
		A[i]-=d; A[i+1]-=d; ans+=(d<0?-d:d);
	}
	if (A[n]!=B[n])
		return puts("-1"),0;
	printf("%lld\n",ans);
	For(i,1,n) A[i]=a[i]-'0',B[i]=b[i]-'0';
	For(i,1,n-1)
		for (;A[i]!=B[i]&&T>0;)
			work(i,A[i]<B[i]?1:-1);
}