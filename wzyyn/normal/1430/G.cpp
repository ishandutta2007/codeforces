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
const int N=20;
int n,m,S,ind[N];
int e[1<<18|5];
int f[1<<18|5];
int fr[1<<18|5];
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		--x; --y;
		ind[y]|=1<<x;
		e[(1<<x)|(1<<y)]=w;
		S+=w;
	}
	For(i,0,n-1)
		For(S,0,(1<<n)-1)
			if (S&(1<<i))
				e[S]+=e[S^(1<<i)];
	memset(f,30,sizeof(f));
	f[0]=0;
	For(i,0,(1<<n)-1){
		//cerr<<i<<endl;
		f[i]+=S-e[i]-e[(1<<n)-1-i];
		int SS=0;
		For(j,0,n-1) if (!(i&(1<<j)))
			if ((ind[j]&i)==ind[j])
				SS|=1<<j;
		for (int j=SS;j;j=(j-1)&SS)
			if (f[i|j]>f[i]) f[i|j]=f[i],fr[i|j]=j;
	}
	int res[20];
	For(i,0,n-1) res[i]=0;
	int S=(1<<n)-1;
	for (;S;S-=fr[S]){
		//cout<<S<<' '<<fr[S]<<endl;
		For(i,0,n-1) if (S&(1<<i)) ++res[i];
	}
	For(i,0,n-1) cout<<res[i]<<' ';
}