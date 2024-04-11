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
const int N=500005;
int n,k,ans;
int a[N],b[N],q[N];
void solve(int l,int r){
	//cout<<l<<' '<<r<<' '<<a[l]<<' '<<a[r]<<endl;
	if (a[l]>a[r]){
		puts("-1");
		exit(0);
	}
	int mid=(l+r)/2;
	int top=0;
	For(i,l+1,r-1)
		if (a[l]<=a[i]&&a[i]<=a[r]){
			int pl=1,pr=top,pm=0;
			while (pl<=pr){
				int mid=(pl+pr)/2;
				if (q[mid]<=a[i])
					pm=mid,pl=mid+1;
				else pr=mid-1;
			}
			q[pm+1]=a[i];
			top=max(top,pm+1);
		}
	ans+=top;
}
int main(){
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,2,k+1) scanf("%d",&b[i]);
	b[1]=0; b[k+2]=n+1; ans=k;
	a[0]=-(1<<30); a[n+1]=1<<30;
	For(i,1,n+1) a[i]-=i;
	For(i,1,k+1) solve(b[i],b[i+1]);
	cout<<n-ans<<endl;
}