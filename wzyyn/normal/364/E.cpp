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
const int N=2505;
char s[N][N];
int a[N][N],n,m,K;
int q1[N][10],q2[N][10];
int tQ1[10],tQ2[10],Q1[10],Q2[10];
ll ans;
void divide(int l,int r,int L,int R){
	if (l==r&&L==R)
		return ans+=(a[L][l]==K),void(0);
	if (R-L+1<=r-l+1){ 
		int mid=(l+r)/2,top=0;
		divide(l,mid,L,R);
		divide(mid+1,r,L,R);
		For(i,L,R){
			top=0; q1[i][0]=mid;
			Rep(j,mid,l) if (a[i][j]&&top<=K) q1[i][++top]=j;
			for (;top<=K;q1[i][++top]=l-1);
			top=0; q2[i][0]=mid+1;
			For(j,mid+1,r) if (a[i][j]&&top<=K) q2[i][++top]=j;
			for (;top<=K;q2[i][++top]=r+1);
		}
		For(i,L,R){
			Q1[0]=mid; Q2[0]=mid+1;
			For(j,1,K+1) Q1[j]=l-1,Q2[j]=r+1;
			For(j,i,R){
				int p1,p2,p3;
				For(k,1,K+1) tQ1[k]=Q1[k],tQ2[k]=Q2[k];
				for (p1=p2=p3=1;p3<=K+1;) Q1[p3++]=(tQ1[p1]>q1[j][p2]?tQ1[p1++]:q1[j][p2++]);
				for (p1=p2=p3=1;p3<=K+1;) Q2[p3++]=(tQ2[p1]<q2[j][p2]?tQ2[p1++]:q2[j][p2++]);
				For(k,0,K) ans+=(Q1[k]-Q1[k+1])*(Q2[K-k+1]-Q2[K-k]);
			}
		}
	}
	else{
		int mid=(L+R)/2,top=0;
		divide(l,r,L,mid);
		divide(l,r,mid+1,R);
		For(i,l,r){
			top=0; q1[i][0]=mid;
			Rep(j,mid,L) if (a[j][i]&&top<=K) q1[i][++top]=j;
			for (;top<=K;q1[i][++top]=L-1);
			top=0; q2[i][0]=mid+1;
			For(j,mid+1,R) if (a[j][i]&&top<=K) q2[i][++top]=j;
			for (;top<=K;q2[i][++top]=R+1);
		}
		For(i,l,r){
			Q1[0]=mid; Q2[0]=mid+1;
			For(j,1,K+1) Q1[j]=L-1,Q2[j]=R+1;
			For(j,i,r){
				int p1,p2,p3;
				For(k,1,K+1) tQ1[k]=Q1[k],tQ2[k]=Q2[k];
				for (p1=p2=p3=1;p3<=K+1;) Q1[p3++]=(tQ1[p1]>q1[j][p2]?tQ1[p1++]:q1[j][p2++]);
				for (p1=p2=p3=1;p3<=K+1;) Q2[p3++]=(tQ2[p1]<q2[j][p2]?tQ2[p1++]:q2[j][p2++]);
				For(k,0,K) ans+=(Q1[k]-Q1[k+1])*(Q2[K-k+1]-Q2[K-k]);
			}
		}
	}
	//if (r-l+1>=100)
	//	cout<<l<<' '<<r<<' '<<L<<' '<<R<<endl;
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d%d%d",&n,&m,&K);
	For(i,1,n) scanf("%s",s[i]+1);
	For(i,1,n) For(j,1,m) a[i][j]=s[i][j]-48;
	divide(1,m,1,n);
	printf("%lld\n",ans);
}