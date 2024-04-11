#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=30;
int n,allv,a[N*2],b[2][N],len[2];
bitset<50005*25>f[N*2][N];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	rep(i,1,n*2)scanf("%d",&a[i]);
	sort(a+1,a+1+n*2);
	b[0][1]=a[1],b[1][n]=a[2];
	len[0]=n,len[1]=0;
	rep(i,1,n*2-2)a[i]=a[i+2];
	a[n*2-1]=a[n*2]=0;
	int allv=0;
	rep(i,1,n*2-2){
		allv+=a[i];
	}
	f[0][0].set(0);
	rep(i,1,n*2-2){
		f[i][0].set(0);
		rep(j,1,n-1){
			f[i][j]=f[i-1][j]|(f[i-1][j-1]<<a[i]);
		}
	}
	/*auto output=[&](bitset<50005*25>&t){
		rep(i,0,50005*25-1)if(t[i])D("%d ",i);
		D("\n");
	};*/
	int nowt=n-1;
	int nowv=allv/2;
	while(!f[n*2-2][nowt][nowv]){
		--nowv;
	}
	per(i,n*2-2,1){
		if(nowt&&a[i]<=nowv&&f[i-1][nowt-1][nowv-a[i]]){
			b[0][len[0]--]=a[i];
			nowv-=a[i];
			--nowt;
		}else{
			b[1][++len[1]]=a[i];
		}
	}
	rep(i,0,1)rep(j,1,n)printf("%d%c",b[i][j],j==n?'\n':' ');
	return 0;
}