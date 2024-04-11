#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define X first
#define Y second
#define PB push_back
#define BK back()
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=100005,B=350,bs=19260817,P=998244853;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
int md(int k1){return k1+=k1>>31&P;}
int n,K,Q,a[N],bel[N],bl[N/B+5],br[N/B+5],pw[N];
struct ff{
	int id,l,r;
	int LEN(){return r-l+1;}
};
vector<ff>st;
bool put(ff);
bool pop(ff);
struct block{
	int id,l,r,mid;
	int need;
	bool err;
	vector<int>hs,hs2;
	block(){need=1;}
	int gt(int l,int r){return su(hs[l],mu(hs[r+1],pw[r-l+1]));}
	int gt2(int l,int r){
		if(l==0)return hs2[r];
		return su(hs2[r],mu(hs2[l-1],pw[r-l+1]));
	}
	void bud(int L,int R){
		err=0;
		need=0;
		vector<int>st;
		rep(i,L,R){
			if(a[i]>0)st.PB(a[i]);
			else{
				if(SZ(st)==0||st.BK<0){
					st.PB(a[i]);
				}else if(st.BK!=-a[i]){
					err=1;
					return;
				}else st.pop_back();
			}
		}
		hs.assign(SZ(st)+1,0);
		hs2.assign(SZ(st),0);
		per(i,SZ(st)-1,0){
			hs[i]=ad(mu(hs[i+1],bs),md(st[i]));
		}
		int lst=0;
		rep(i,0,SZ(st)-1){
			hs2[i]=ad(mu(lst,bs),md(st[i]));
			lst=hs2[i];
		}
		mid=-1;
		rep(i,0,SZ(st)-1){
			if(st[i]<0)mid=i;else break;
		}
	}
	bool ps(int L,int R){
		if(L>r||R<l)return 1;
		L=max(L,l),R=min(R,r);
		if(L==l&&R==r){
			if(need)bud(l,r);
		}else{
			bud(L,R);
			need=1;
		}
		if(err)return 0;
		return pop((ff){id,0,mid})&&put((ff){id,mid+1,SZ(hs)-2});
	}
}b[N/B+5];
bool put(ff x){
	if(x.l<=x.r)st.PB(x);
	return 1;
}
bool pop(ff x){
	if(x.l>x.r)return 1;
	while(SZ(st)){
		int len=min(st.BK.LEN(),x.LEN());
		if(b[st.BK.id].gt(st.BK.r-len+1,st.BK.r)!=su(0,b[x.id].gt2(x.l,x.l+len-1))){
			return 0;
		}else{
			st.BK.r-=len;
			x.l+=len;
			if(st.BK.LEN()<=0)st.pop_back();
			if(x.LEN()<=0)return 1;
		}
	}
	return 0;
}
bool chk(int l,int r){
	st.clear();
	rep(i,1,bel[n])
		if(!b[i].ps(l,r)){
			//D("%d\n",i);
			return 0;
		}
	return SZ(st)==0;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	pw[0]=1;
	rep(i,1,N-1)pw[i]=mu(pw[i-1],bs);
	scanf("%d%d",&n,&K);
	rep(i,1,n){
		scanf("%d",&a[i]);
		bel[i]=(i-1)/B+1;
		if(!b[bel[i]].l)b[bel[i]].l=i;
		b[bel[i]].r=i;
	}
	rep(i,1,bel[n])b[i].id=i,b[i].bud(b[i].l,b[i].r);
	scanf("%d",&Q);
	rep(_,1,Q){
		int o;
		scanf("%d",&o);
		if(o==1){
			int i,t;
			scanf("%d%d",&i,&t);
			a[i]=t;
			b[bel[i]].need=1;
		}else{
			int l,r;
			scanf("%d%d",&l,&r);
			puts(chk(l,r)?"Yes":"No");
		}
	}
	return 0;
}