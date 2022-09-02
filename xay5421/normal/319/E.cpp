#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define PB push_back
#define EB emplace_back
#define SZ(x) ((int)(x).size())
using namespace std;
const int N=100005;
int n,fa[N],ind,L[N],R[N];
int fd(int k1){return fa[k1]==k1?k1:fa[k1]=fd(fa[k1]);}
vector<int>v[N*8];
vector<tuple<int,int,int> >mod;
void sol(int k1,int k2,int k3,int k4,int k5){
	if(SZ(v[k1])){
		for(auto x:v[k1]){
			L[k5]=min(L[k5],L[fd(x)]);
			R[k5]=max(R[k5],R[fd(x)]);
			fa[fd(x)]=k5;
		}
		v[k1].clear();
		v[k1].PB(k5);
	}
	if(k2==k3)return;
	int mid=(k2+k3)>>1;
	if(k4<=mid)sol(k1*2,k2,mid,k4,k5);
	else sol(k1*2+1,mid+1,k3,k4,k5);
}
void put(int k1,int k2,int k3,int k4,int k5,int k6){
	if(k2>k5||k3<k4)return;
	if(k4<=k2&&k3<=k5){
		v[k1].PB(k6);
		return;
	}
	int mid=(k2+k3)>>1;
	put(k1*2,k2,mid,k4,k5,k6),put(k1*2+1,mid+1,k3,k4,k5,k6);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rep(i,1,N-1)fa[i]=i;
	scanf("%d",&n);
	vector<int>num;
	rep(i,1,n){
		int k1,k2,k3;
		scanf("%d%d%d",&k1,&k2,&k3);
		mod.EB(k1,k2,k3);
		num.PB(k2),num.PB(k3);
	}
	sort(num.begin(),num.end());
	num.erase(unique(num.begin(),num.end()),num.end());
	rep(i,0,SZ(mod)-1){
		int k1,k2,k3;
		tie(k1,k2,k3)=mod[i];
		if(k1==1){
			k2=lower_bound(num.begin(),num.end(),k2)-num.begin()+1;
			k3=lower_bound(num.begin(),num.end(),k3)-num.begin()+1;
			++ind;
			L[ind]=k2;
			R[ind]=k3;
			sol(1,1,SZ(num),k2,ind);
			sol(1,1,SZ(num),k3,ind);
			if(k2+1<=k3-1){
				put(1,1,SZ(num),k2+1,k3-1,ind);
			}
		}
		if(k1==2){
			int u=fd(k2),v=fd(k3);
			puts(u==v||(L[v]<L[u]&&L[u]<R[v])||(L[v]<R[u]&&R[u]<R[v])?"YES":"NO");
		}
	}
	return 0;
}