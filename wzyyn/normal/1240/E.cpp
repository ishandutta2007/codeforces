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
#define y1 fdhjksa
using namespace std;
const int N=500005;
int n,mx;
int a[N],S[N];
ll ans;
ll DIF1(int x,int y){
	int S1=0,S2=0;
	For(i,0,mx/y){
		int l=max(x,i*y);
		int r=min((i+1)*y-1,mx);
		if (l>r) continue;
		int m=min(x%y+i*y,mx+1);
		S1+=S[m-1]-S[l-1];
		if (m<=r) S2+=S[r]-S[m-1];
	}
	if (S1+S2<2) return 1ll<<60;
	else return x/y*2+2-min(S2,2);
}
ll DIF2(int x,int y){
	x*=2;
	int S1=0,S2=0;
	For(i,0,mx/y){
		int l=max(x,i*y);
		int r=min((i+1)*y-1,mx);
		if (l>r) continue;
		int m=min(x%y+i*y,mx+1);
		S1+=S[m-1]-S[l-1];
		if (m<=r) S2+=S[r]-S[m-1];
	}
	if (S1+S2<1) return 1ll<<60;
	else return x/y+1-min(S2,1);
}
void update(int y){
	ll sum=0;
	For(i,1,mx/y){
		int l=i*y,r=min(l+y-1,mx);
		sum+=1ll*i*(S[r]-S[l-1]);
	}
	//if (y==9) printf("%lld\n",sum);
	int l=2,r=mx,v=0;
	while (l<=r){
		int mid=(l+r)/2;
		if (sum-min(DIF1(mid,y),DIF2(mid,y))>=mid)
			v=mid,l=mid+1;
		else r=mid-1;
	}
	ans=max(ans,1ll*v*y);
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		scanf("%d",&a[i]);
		mx=max(mx,a[i]);
		S[a[i]]++;
	}
	For(i,1,mx) S[i]+=S[i-1];
	For(i,2,mx) update(i);
	printf("%lld\n",ans);
}