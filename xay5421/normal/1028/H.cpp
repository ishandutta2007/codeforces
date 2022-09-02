// author: xay5421
// created: Fri Oct 29 21:48:41 2021
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=200005,M=5100005;
int n,Q,a[N],ans[15],pos[M][8],res[1100005];
vector<pair<int,int> >qs[N];
bool ban[M];
int p[M/10],mind[M],f[M]; // f[x]  miu(x)!=0 x 
void sieve(){
	ban[0]=ban[1]=1,mind[1]=1,f[1]=0;
	for(int i=2;i<M;++i){
		if(!ban[i]){
			p[++*p]=i,mind[i]=i,f[i]=1;
		}
		for(int j=1;j<=*p&&i*p[j]<M;++j){
			ban[i*p[j]]=1,mind[i*p[j]]=p[j];
			if(i%p[j]==0)break;
			f[i*p[j]]=f[i]+1;
		}
	}
}
int main(){
	sieve();
	rd(n),rd(Q);
	rep(i,1,n)rd(a[i]);
	rep(i,1,Q){
		int l,r;
		rd(l),rd(r);
		qs[r].eb(l,i);
	}
	rep(i,1,n){
		vector<int>ds;
		int x=a[i];
		a[i]=1;
		while(x>1){
			int v=mind[x],cnt=0;
			while(x%v==0){
				x/=v;
				++cnt;
			}
			if(cnt&1)ds.pb(v),a[i]*=v;
		}
		int mask=0,val=1;
		rep(_,0,(1<<SZ(ds))-1){
			if(_){
				int pos=__builtin_ctz(_);
				if(mask>>pos&1){
					val/=ds[pos];
				}else{
					val*=ds[pos];
				}
				mask^=1<<pos;
			}
			int tmp=f[a[i]]-2*f[val];
			rep(j,0,7){
				ans[j+tmp]=max(ans[j+tmp],pos[val][j]);
			}
			pos[val][f[a[i]]]=i;
		}
		for(auto x:qs[i]){
			rep(i,0,14)if(ans[i]>=x.first){res[x.second]=i;break;}
		}
	}
	rep(i,1,Q)pt(res[i],'\n');
	return 0;
}