#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#define NDEBUG
#endif
#include<bits/stdc++.h>
#define int long long
#define LL long long
#define MP make_pair
#define PB push_back
#define fi first
#define se second
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef pair<int,int>PII;typedef vector<int>VI;typedef vector<PII>VII;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=500005;
int n,t[N*4],mn[N*4],clr[N*4];
char s[N];
void pst_clr(int k1,int k2,int k3){
	t[k1]=1LL*k2*k3;
	clr[k1]=k2;
	mn[k1]=k2;
}
void psd(int k1,int k2){
	if(clr[k1]){
		pst_clr(k1*2,clr[k1],(k2+1)>>1);
		pst_clr(k1*2+1,clr[k1],k2>>1);
		clr[k1]=0;
	}
}
void upd(int k1){
	t[k1]=t[k1*2]+t[k1*2+1];
	mn[k1]=min(mn[k1*2],mn[k1*2+1]);
}
void mdf(int k1,int k2,int k3,int k4,int k5,int k6){
	if(k2>k5||k3<k4)return;
	if(k4<=k2&&k3<=k5){
		D("clr %lld %lld %lld\n",k2,k3,k6);
		pst_clr(k1,k6,k3-k2+1);
		return;
	}
	psd(k1,k3-k2+1);
	int mid=(k2+k3)>>1;
	mdf(k1*2,k2,mid,k4,k5,k6);
	mdf(k1*2+1,mid+1,k3,k4,k5,k6);
	upd(k1);
}
int pos;
void ask(int k1,int k2,int k3,int k4){
	if(k2==k3){
		if(mn[k1]<=k4)pos=k2;
		return;
	}
	psd(k1,k3-k2+1);
	int mid=(k2+k3)>>1;
	if(mn[k1*2]<=k4)ask(k1*2,k2,mid,k4);
	else ask(k1*2+1,mid+1,k3,k4);
}
signed main(){
	rd(n);
	scanf("%s",s+1);
	int tot=0,ans=0;
	rep(r,1,n){
		D("r=%lld\n",r);
		if(s[r]=='1'){
			++tot;
			ans+=1LL*tot*(tot+1)/2;
			if(r-tot>0){
				pos=-1;
				ask(1,1,n,tot);
				D("pos=%lld\n",pos);
				if(pos!=-1&&pos<=r-tot)mdf(1,1,n,pos,r-tot,tot);
			}
		}else{
			rep(i,1,tot){
				mdf(1,1,n,r-i,r-i,i);
			}
			tot=0;
		}
		D("nowans=%lld\n",t[1]);
		ans+=t[1];
	}
	pt(ans,'\n');
	return 0;
}