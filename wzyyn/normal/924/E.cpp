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
const int N=10005;
int n,L,R,S,a[N],b[N];
int s1[N],s2[N],f[N];
int main(){
	scanf("%d%d%d",&n,&L,&R);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) scanf("%d",&b[i]);
	For(i,1,n)
		if (!b[i]) ++s1[a[i]];
		else ++s2[a[i]];
	For(i,1,n) S+=a[i];
	swap(L,R); L=S-L; R=S-R;
	R=min(R,S); L=max(L,0);
	//cout<<L<<' '<<R<<endl; 
	memset(f,233,sizeof(f)); f[0]=0;
	For(i,1,S) if (s1[i]){
		int rem=s1[i],j=1;
		for (;rem;rem-=min(rem,j),j*=2){
			int t=min(rem,j);
			Rep(k,R,i*t) f[k]=max(f[k],f[k-i*t]);
		}
	}
	//cout<<l<<' '<<r<<endl;
	Rep(i,S,1) if (s2[i]){
		int rem=s2[i],j=1;
		for (;rem;rem-=min(rem,j),j*=2){
			int t=min(rem,j);
			Rep(k,R,i*t){
				int sum=max(0,min(k-L+1,i*t));
				f[k]=max(f[k],f[k-i*t]+sum/i+(sum%i!=0));
			}
			//For(k,0,R) cout<<f[k]<<' '; cout<<endl;
		}
	}
	int ans=0;
	For(i,L,R) ans=max(ans,f[i]);
	printf("%d\n",ans);
}
/*
10 71 286
61 59 99 33 2 19 72 59 45 96
1 1 0 0 1 0 1 1 1 1
*/