#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=200005,INF=0X3F3F3F3F;
int T,n;
char s[N];
struct segTree{
	int sum[N*4],tg[N*4];
	void upd(int k1){
		sum[k1]=sum[k1*2]+sum[k1*2+1];
	}
	void pst(int k1){
		tg[k1]=1;
		sum[k1]=0;
	}
	void psd(int k1){
		if(tg[k1]){
			pst(k1*2);
			pst(k1*2+1);
			tg[k1]=0;
		}
	}
	void bud(int k1,int k2,int k3){
		tg[k1]=0,sum[k1]=k3-k2+1;
		if(k2==k3){
			return;
		}
		int mid=(k2+k3)>>1;
		bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
	}
	void set0(int k1,int k2,int k3,int k4,int k5){
		if(k2>k5||k3<k4)return;
		if(k4<=k2&&k3<=k5){
			pst(k1);
			return;
		}
		psd(k1);
		int mid=(k2+k3)>>1;
		set0(k1*2,k2,mid,k4,k5);
		set0(k1*2+1,mid+1,k3,k4,k5);
		upd(k1);
	}
	int query(int k1,int k2,int k3,int k4,int k5){
		if(k2>k5||k3<k4)return 0;
		if(k4<=k2&&k3<=k5){
			return sum[k1];
		}
		psd(k1);
		int mid=(k2+k3)>>1;
		return query(k1*2,k2,mid,k4,k5)+query(k1*2+1,mid+1,k3,k4,k5);
	}
}tr;
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		tr.bud(1,1,n);
		vector<int>pos={0};
		int tt=0;
		array<int,26>cnt={0};
		for(int i=1;i<=n;++i){
			if(i<n&&s[i]==s[i+1]){
				pos.pb(i);
				++tt;
				++cnt[s[i]-'a'];
			}
		}
		pos.pb(n);
		auto real=[&](int x){
			return tr.query(1,1,n,1,x);
		};
		auto erase=[&](int l,int r){
			tr.set0(1,1,n,l,r);
		};
		vector<int>st;
		vector<pair<int,int> >ans;
		rep(i,1,SZ(pos)-2){
			int mx=max_element(cnt.begin(),cnt.end())-cnt.begin();
			if(st.empty()||s[pos[i]]==s[pos[st.back()]]){
				st.pb(i);
				continue;
			}
			int u=s[pos[i]]-'a',v=s[pos[st.back()]]-'a';
			if(cnt[mx]*2>=tt&&u!=mx&&v!=mx){
				st.pb(i);
				continue;
			}
			--cnt[u],--cnt[v];
			ans.eb(real(pos[st.back()]+1),real(pos[i]));
			erase(pos[st.back()]+1,pos[i]);
			st.pop_back();
			tt-=2;
		}
		st.pb(SZ(pos)-1);
		for(auto&i:st){
			ans.eb(1,real(pos[i]));
			erase(1,pos[i]);
		}
		printf("%d\n",SZ(ans));
		for(auto&x:ans)printf("%d %d\n",get<0>(x),get<1>(x));
	}
	return 0;
}