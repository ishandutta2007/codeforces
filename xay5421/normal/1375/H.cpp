#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef vector<pair<int,int> >VII;
typedef vector<int>VI;
typedef vector<VI>VVI;
const int N=5005;
int n,q,B,ind,a[N],aa[N];
VVI f[N];
int nid;
VI pos[260],res;
VII ans;
int mer(int k1,int k2){
//	printf("mer:%d %d\n",k1,k2);
	if(!k1||!k2)return k1+k2;
	ans.PB(MP(k1,k2));
	return ++ind;
}
VVI bud(int l,int r,VI npos){
//	printf(">>> %d %d\n",l,r);
	if(l==r){
		return {{npos[0]}};
	}
	int mid=(l+r)>>1;
	VI posl,posr;
	for(auto x:npos)(a[x]<=mid?posl:posr).PB(x);
	auto resl=bud(l,mid,posl),resr=bud(mid+1,r,posr),res=VVI(r-l+1,VI(r-l+1));
	rep(i,0,SZ(npos)-1)rep(j,i,SZ(npos)-1){
		int L=lower_bound(ALL(posl),npos[i])-posl.begin();
		int R=upper_bound(ALL(posl),npos[j])-posl.begin()-1;
		int&t=res[i][j];t=0;
		if(L<=R){
			t=resl[L][R];
		}
		L=lower_bound(ALL(posr),npos[i])-posr.begin();
		R=upper_bound(ALL(posr),npos[j])-posr.begin()-1;
		if(L<=R){
			t=mer(t,resr[L][R]);
		}
	}
	return res;
}
void sol(int L,int R){
	pos[nid].clear();
	rep(i,L,R)pos[nid].PB(aa[i]);
	sort(ALL(pos[nid]));
	f[nid]=bud(L,R,pos[nid]);
}
int main(){
	scanf("%d%d",&n,&q);
	B=1<<8;
	rep(i,1,n)scanf("%d",a+i),aa[a[i]]=i;
	nid=1,ind=n;
	for(int i=1;i<=n;i+=B){
		sol(i,min(n,i+B-1));
		++nid;
	}
	while(q--){
		int l,r;scanf("%d%d",&l,&r);
		nid=0;
		int now=0;
		for(int i=1;i<=n;i+=B){
			++nid;
//			printf("nid:%d\n",nid);
//			rep(i,0,SZ(pos[nid])-1)printf("%d ",pos[nid][i]);puts("");
			auto L=lower_bound(ALL(pos[nid]),l)-pos[nid].begin();
			auto R=upper_bound(ALL(pos[nid]),r)-pos[nid].begin()-1;
			if(L<=R){
//				printf(">>> %d %d\n",L-pos[nid].begin(),R-pos[nid].begin()-1);
				now=mer(now,f[nid][L][R]);
			}
		}
		res.PB(now);
	}
	printf("%d\n",SZ(ans)+n);
	for(auto x:ans)printf("%d %d\n",x.fi,x.se);
	for(auto x:res)printf("%d ",x);
	return 0;
}