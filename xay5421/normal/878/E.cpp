#include<bits/stdc++.h>
#define EB emplace_back
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int N=100005,P=1e9+7,INF=0X3F3F3F3F;
int n,Q,a[N],pw[N],ipw[N],h[N],le[N],ans[N];
vector<int>q[N],sum,w;
vector<pair<int,int> >st;
int ask(int l,int r){
	return 1LL*(h[r]-h[l-1]+P)*ipw[l-1]%P;
}
int main(){
	pw[0]=1,ipw[0]=1;
	for(int i=1;i<N;++i)pw[i]=(pw[i-1]<<1)%P,ipw[i]=1LL*ipw[i-1]*((P+1)>>1)%P;
	scanf("%d%d",&n,&Q);
	rep(i,1,n)scanf("%d",a+i),h[i]=(h[i-1]+1LL*pw[i]*(a[i]+P))%P;
	rep(i,1,Q){
		int l,r;scanf("%d%d",&l,&r);
		le[i]=l,q[r].EB(i);
	}
	rep(i,1,n){
		st.EB(i,i);
		sum.EB(a[i]);
		while(SZ(st)>1){
			int shift=min(30,st.back().fi-st[SZ(st)-2].fi);
			if(sum.back()>0){
				int x=sum.back();
				sum.pop_back();
				sum.back()=min((LL)INF,(sum.back()+((LL)x<<shift)));
				st[SZ(st)-2].se=st.back().se;
				st.pop_back();
				w.pop_back();
			}else break;
		}
		if(SZ(w)){
			w.EB((w.back()+ask(st.back().fi,st.back().se))%P);
		}else{
			w.EB(ask(st.back().fi,st.back().se));
		}
		for(auto it:q[i]){
			int pos=upper_bound(st.begin(),st.end(),make_pair(le[it],INF))-st.begin()-1;
			ans[it]=((LL)w.back()+P-w[pos]+1LL*ask(le[it],st[pos].se)*((P+1)>>1)%P)%P;
		}
	}
	rep(i,1,Q)printf("%d\n",ans[i]);
	return 0;
}