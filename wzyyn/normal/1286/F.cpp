#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=22,M=(1<<20)+5;
ll a[N],S[M];
ll A[2005],B[2005];
ll q1[2005],q2[2005];
int n,ans,bit[M];
int f[M],ok[M],q[N];
void getque(int x,int y,ll *qq){
	int l=1; qq[1]=0;
	For(i,x,y){
		For(j,1,l){
			A[j]=qq[j];
			B[j]=qq[j]+2*a[q[i]];
		}
		int p1=1,p2=1,p3=0;
		for (;p1<=l||p2<=l;)
			if (p2>l||(p1<=l&&A[p1]<B[p2]))
				qq[++p3]=A[p1++];
			else qq[++p3]=B[p2++];
		l*=2;
	}
	qq[0]=l;
}
bool check(int x){
	if ((S[x]+bit[x]+1)&1) return 0;
	if (bit[x]<=1) return 0;
	*q=*q1=*q2=0;
	For(i,0,n-1) if (x&(1<<i)) q[++*q]=i;
	getque(1,(*q)/2,q1);
	getque((*q)/2+1,*q,q2);
	int sum=(abs(S[x])<bit[x])?-2:0;
	ll lo=S[x]-bit[x],ri=S[x]+bit[x];
	int l1=q1[0],l2=q2[0],h=1,t=0;
	for (int i=l1;i>=1&&sum<=0;--i){
		for (;t!=l2&&q2[t+1]+q1[i]<ri;++t);
		for (;h<=t&&q2[h]+q1[i]<=lo;++h);
		sum+=t+1-h;
	}
	return sum>0;
}
int main(){
	scanf("%d",&n);
	For(i,0,n-1){
		scanf("%lld",&a[i]);
		if (!a[i]) --n,--i;
	}
	For(i,0,(1<<n)-1) bit[i]=bit[i/2]+(i&1);
	For(i,0,(1<<n)-1) For(j,0,n-1)
		if (i&(1<<j)) S[i]+=a[j];
	For(i,1,(1<<n)-1) if (!f[i]&&check(i)){
		f[i]=1;
		int j=(1<<n)-1-i;
		for (int jj=j;jj;(--jj)&=j)
			f[i|jj]=max(f[i|jj],f[jj]+1);
	}
	printf("%d\n",n-f[(1<<n)-1]);
}