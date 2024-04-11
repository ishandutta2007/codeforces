#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fir first
#define sec second
#define all(x) x.begin(),x.end()
#define size(x) ((int)x.size())
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define inl inline
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define travel(i,u) for(int i=head[u];i;i=e[i].next)
#define lb(x) ((x)&(-(x)))
#define lson root<<1
#define rson root<<1|1
#define Mid (l+r>>1)
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
typedef long long ll;
const int MAXN = 1e5+10;
int cnt[4],quq[4],mjy[MAXN];
inl char read(){
	static const int IO_LEN=1024*1024;
	static char buf[IO_LEN],*ioh,*iot;
	if(ioh==iot){
		iot=(ioh=buf)+fread(buf,1,IO_LEN,stdin);
		if(ioh==iot) return -1;
	}
	return *ioh++;
}
template<class T>inl void read(T &x){
	static int iosig;static char ioc;
	for(iosig=0,ioc=read();!isdigit(ioc);ioc=read()) if(ioc=='-') iosig=1;
	for(x=0;isdigit(ioc);ioc=read())x=(x<<1)+(x<<3)+(ioc^'0');
	if(iosig) x=-x;
}
int main(){
	//freopen("in.txt","r",stdin);
	int start=clock();
	srand(time(NULL));
	read(cnt[0]),read(cnt[1]),read(cnt[2]),read(cnt[3]);
	int n=cnt[0]+cnt[1]+cnt[2]+cnt[3];
	rep(i,0,3) quq[i]=cnt[i];
	rep(i,0,3) if(cnt[i]) {
		int begin=i,flag=1;
		mjy[1]=begin;cnt[begin]--;
		rep(i,2,n){
			int Pos=mjy[i-1];
			if(Pos-1>=0 &&cnt[Pos-1]) mjy[i]=Pos-1,cnt[Pos-1]--;
			else if(Pos+1<=3 && cnt[Pos+1]) mjy[i]=Pos+1,cnt[Pos+1]--;
			else {flag=0;break;}
		}
		if(flag) {
			puts("YES");
			rep(i,1,n) printf("%d ",mjy[i]);
			return 0;
		}
		rep(i,0,3) cnt[i]=quq[i];
	}
	rep(i,0,3) if(cnt[i]) {
		int begin=i,flag=1;
		mjy[1]=begin;cnt[begin]--;
		rep(i,2,n){
			int Pos=mjy[i-1];
			if(Pos+1<=3 && cnt[Pos+1]) mjy[i]=Pos+1,cnt[Pos+1]--;
			else if(Pos-1>=0 &&cnt[Pos-1]) mjy[i]=Pos-1,cnt[Pos-1]--;
			else {flag=0;break;}
		}
		if(flag) {
			puts("YES");
			rep(i,1,n) printf("%d ",mjy[i]);
			return 0;
		}
		rep(i,0,3) cnt[i]=quq[i];
	}
	while((double)(clock()-start)/CLOCKS_PER_SEC<=0.97){
		rep(i,0,3) if(cnt[i]) {
		int begin=i,flag=1;
		mjy[1]=begin;cnt[begin]--;
		rep(i,2,n){
			int Pos=mjy[i-1];
			if(rand()&1){
				if(Pos-1>=0 &&cnt[Pos-1]) mjy[i]=Pos-1,cnt[Pos-1]--;
				else if(Pos+1<=3 && cnt[Pos+1]) mjy[i]=Pos+1,cnt[Pos+1]--;
				else {flag=0;break;}
			}else{
				if(Pos+1<=3 && cnt[Pos+1]) mjy[i]=Pos+1,cnt[Pos+1]--;
				else if(Pos-1>=0 &&cnt[Pos-1]) mjy[i]=Pos-1,cnt[Pos-1]--;
				else {flag=0;break;}
			}
		}
		if(flag) {
			puts("YES");
			rep(i,1,n) printf("%d ",mjy[i]);
			return 0;
		}
		rep(i,0,3) cnt[i]=quq[i];
	}
	}
	puts("NO");
	return 0;
}