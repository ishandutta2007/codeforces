#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define D(...) fprintf(stderr,__VA_ARGS__)
//#define int long long
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
int n,q;char s[N];
struct data{
	int mx[2],lmx[2],llen[2],rmx[2],rlen[2],tag,len;
}t[N*4];
void mer(data&k3,data k1,data k2){
	k3.tag=0;
	k3.len=k1.len+k2.len;
	rep(i,0,1){
		k3.mx[i]=max({k1.mx[i],k2.mx[i],k1.rmx[i]+k2.llen[i],k1.rlen[i]+k2.lmx[i]});
		k3.lmx[i]=k1.lmx[i];
		if(k1.lmx[i]==k1.len){
			if(k1.llen[i^1]==k1.len){
				k3.lmx[i]+=k2.lmx[i];
			}else{
				k3.lmx[i]+=k2.llen[i];
			}
		}
		k3.rmx[i]=k2.rmx[i];
		if(k2.rmx[i]==k2.len){
			if(k2.rlen[i^1]==k2.len){
				k3.rmx[i]+=k1.rmx[i];
			}else{
				k3.rmx[i]+=k1.rlen[i];
			}
		}
		k3.llen[i]=k1.llen[i];
		if(k1.llen[i]==k1.len){
			k3.llen[i]+=k2.llen[i];
		}
		k3.rlen[i]=k2.rlen[i];
		if(k2.rlen[i]==k2.len){
			k3.rlen[i]+=k1.rlen[i];
		}
	}
}
void bud(int k1,int k2,int k3){
	t[k1].len=k3-k2+1;
	if(k2==k3){
		if(s[k2]=='<'){
			t[k1].mx[0]=t[k1].mx[1]=1;
			t[k1].lmx[1]=t[k1].rmx[0]=1;
			t[k1].lmx[0]=t[k1].rmx[1]=1;
			t[k1].llen[0]=t[k1].rlen[1]=1;
			t[k1].llen[1]=t[k1].rlen[0]=0;
		}else{
			t[k1].mx[0]=t[k1].mx[1]=1;
			t[k1].lmx[1]=t[k1].rmx[0]=1;
			t[k1].lmx[0]=t[k1].rmx[1]=1;
			t[k1].llen[0]=t[k1].rlen[1]=0;
			t[k1].llen[1]=t[k1].rlen[0]=1;
		}
		return;
	}
	int mid=(k2+k3)>>1;
	bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
//	if(k1==4){
//		D("233\n");
//	}
	mer(t[k1],t[k1*2],t[k1*2+1]);
}
data ans;bool fir;
void pst(int k1){
#define SWAP(a) swap(t[k1].a[0],t[k1].a[1])
	SWAP(mx),SWAP(lmx),SWAP(llen),SWAP(rmx),SWAP(rlen);
	t[k1].tag^=1;
#undef SWAP
}
void psd(int k1){
	if(t[k1].tag){
		pst(k1*2);
		pst(k1*2+1);
		t[k1].tag^=1;
	}
}
void mdf(int k1,int k2,int k3,int k4,int k5){
	if(k2>k5||k3<k4){
		return;
	}
	if(k4<=k2&&k3<=k5){
		pst(k1);
		if(fir)ans=t[k1],fir=0;
		else mer(ans,ans,t[k1]);
		return;
	}
	psd(k1);
	int mid=(k2+k3)>>1;
	mdf(k1*2,k2,mid,k4,k5),mdf(k1*2+1,mid+1,k3,k4,k5);
	mer(t[k1],t[k1*2],t[k1*2+1]);
}
signed main(){
	rd(n),rd(q);
	scanf("%s",s+1);
	bud(1,1,n);
	while(q--){
		int l,r;rd(l),rd(r);
		fir=1;
		mdf(1,1,n,l,r);
		pt(ans.mx[0],'\n');
	}
	return 0;
}