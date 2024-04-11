// author: xay5421
// created: Sun Sep 12 22:53:50 2021
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long LL;
const int N=305;
int T,n,m,a[N*N],b[N*N],posx[N*N],posy[N*N];
vector<int>bin[N*N];
struct BIT{
	int t[N];
	void upd(int k1,int k2){
		for(int i=k1;i<=m;i+=i&-i)t[i]+=k2;
	}
	int qry(int k1){
		int k2=0;
		for(int i=k1;i;i&=i-1)k2+=t[i];
		return k2;
	}
}t[N];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		rep(i,1,n*m)scanf("%d",&a[i]),b[i]=a[i];
		sort(b+1,b+1+n*m);
		int len=unique(b+1,b+1+n*m)-b-1;
		rep(i,1,len)bin[i].clear();
		rep(i,1,n*m)a[i]=lower_bound(b+1,b+1+len,a[i])-b;
		rep(i,1,n*m)bin[a[i]].push_back(i);
		rep(i,1,n)rep(j,1,m)t[i].t[j]=0;
		int ind=0;
		rep(i,1,len){
			vector<pair<int,int> >vec;
			rep(_,0,SZ(bin[i])-1){
				++ind;
				int x=(ind-1)/m+1,y=(ind-1)%m+1;
				vec.emplace_back(x,y);
			}
			sort(vec.begin(),vec.end(),[&](pair<int,int>x,pair<int,int>y){
				return x.first^y.first?x.first<y.first:x.second>y.second;
			});
			int cur=0;
			for(auto x:bin[i]){
				tie(posx[x],posy[x])=vec[cur++];
			}
		}
		LL ans=0;
		rep(i,1,n*m){
			ans+=t[posx[i]].qry(posy[i]);
			t[posx[i]].upd(posy[i],1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}