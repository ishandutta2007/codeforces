#include<bits/stdc++.h>
#define int long long
#define LL long long
#define MP make_pair
#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef pair<int,int>pii;typedef vector<int>VI;typedef vector<pii>VP;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=300005;
int n,p[N],id[N],q[N],mn[N*4],tg[N*4];
bool cmp(int x,int y){return p[x]>p[y];}
void pst(int k1,int k2){
	mn[k1]+=k2,tg[k1]+=k2;
}
void psd(int k1){
	if(tg[k1]){
		pst(k1*2,tg[k1]);
		pst(k1*2+1,tg[k1]);
		tg[k1]=0;
	}
}
void upd(int k1){
	mn[k1]=min(mn[k1*2],mn[k1*2+1]);
}
void mdf(int k1,int k2,int k3,int k4,int k5,int k6){
	if(k2>k5||k3<k4)return;
	if(k4<=k2&&k3<=k5){
		pst(k1,k6);
		return;
	}
	psd(k1);
	int mid=(k2+k3)>>1;
	mdf(k1*2,k2,mid,k4,k5,k6),mdf(k1*2+1,mid+1,k3,k4,k5,k6);
	upd(k1);
}
signed main(){
	rd(n);
	rep(i,1,n)rd(p[i]),id[i]=i;rep(i,1,n)rd(q[i]);
	sort(id+1,id+1+n,cmp);
	int now=1;mdf(1,1,n,1,id[1],-1);
	rep(i,1,n){
		pt(p[id[now]],' ');
		if(i==n)break;
		mdf(1,1,n,1,q[i],1);
		while(mn[1]>=0){
			++now;
			mdf(1,1,n,1,id[now],-1);
		}
	}
	return 0;
}