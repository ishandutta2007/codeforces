#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=300005;
int n,a[N],b[N],A[N];
int t[N],nx[N],lg[N];
int st[N][19];
void change(int x,int v){
	for (;x<=n;x+=x&(-x)) t[x]=min(t[x],v);
}
int ask(int x){
	int ans=1<<30;
	for (;x;x-=x&(-x)) ans=min(ans,t[x]);
	return ans;
}
int ask(int l,int r){
	int k=lg[r-l+1];
	return min(st[l][k],st[r-(1<<k)+1][k]);
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		scanf("%d",&a[i]);
		A[i]=a[i];
	}
	sort(A+1,A+n+1);
	For(i,1,n){
		b[i]=b[i+n]=b[i+2*n]=upper_bound(A+1,A+n+1,(a[i]-1)/2)-A-1;
		a[i]=a[i+n]=a[i+2*n]=upper_bound(A+1,A+n+1,a[i])-A-1;
	}
	For(i,1,n) t[i]=1<<30;
	Rep(i,3*n,1){
		change(a[i],i);
		nx[i]=ask(b[i]);
	}
	For(i,1,3*n) st[i][0]=nx[i];
	For(i,2,3*n) lg[i]=lg[i/2]+1;
	For(i,1,18) For(j,1,3*n-(1<<i)+1)
		st[j][i]=min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
	For(i,1,n){
		int l=i,r=i+2*n-1,ans=-1;
		while (l<=r){
			int mid=(l+r)/2;
			if (ask(i,mid)>mid)
				ans=mid,l=mid+1;
			else r=mid-1;
		}
		printf("%d ",ans==i+2*n-1?-1:ans-i+1);
	}
}