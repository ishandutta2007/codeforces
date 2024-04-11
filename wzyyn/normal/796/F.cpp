#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=300005;
int n,Q,nn,ans,lim[N];
int t1[N*4],t2[N*4];
map<int,pair<int,vector<int> > > mp; 
void init(){
	for (nn=1;nn<=n+1;nn<<=1);
	For(i,0,2*nn-1) t2[i]=1e9,t1[i]=0;
}
void Chg1(int x,int v){
	x+=nn; t1[x]=v;
	for (x>>=1;x;x>>=1) t1[x]=max(t1[x<<1],t1[x<<1|1]);
}
int Qmx1(int x,int y){
	x+=nn-1; y+=nn+1;
	int ans=0;
	for (;x^y^1;x>>=1,y>>=1){
		if (!(x&1)) ans=max(ans,t1[x^1]);
		if (y&1)	ans=max(ans,t1[y^1]);
	}
	return ans;
}
void Chg2(int x,int y,int v){
	x+=nn-1; y+=nn+1;
	for (;x^y^1;x>>=1,y>>=1){
		if (!(x&1)) t2[x^1]=min(t2[x^1],v);
		if (y&1)	t2[y^1]=min(t2[y^1],v);
	}
}
int Qmx2(int x){
	int ans=1e9;
	for (x+=nn;x;x>>=1) ans=min(ans,t2[x]);
	return ans;
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n) lim[i]=-1;
 	init();
	while (Q--){
		int tp,x,y;
		scanf("%d%d%d",&tp,&x,&y);
		if (tp==1){
			int v,vv=Qmx1(x,y);
			scanf("%d",&v);
			//cout<<v<<' '<<vv<<endl;
			if (vv>v) return puts("NO"),0;
			//cout,,
			if (vv<v) ans|=v,--mp[v].fi;
			Chg2(x,y,v);
		}
		else{
			if (lim[x]==-1)
				lim[x]=Qmx2(x);
			Chg1(x,y);
		}
	}
	For(i,1,n)
		if (lim[i]==-1)
			lim[i]=Qmx2(i);
	//For(i,1,n) cout<<lim[i]<<endl;
	For(i,1,n){
		mp[lim[i]].fi++;
		mp[lim[i]].se.PB(i);
	}
	for (auto i:mp)
		if (i.se.fi<0)
			return puts("NO"),0;
	for (auto i:mp)
		if (i.se.fi>1){
			int v=i.fi,vv=1;
			for (;vv<=v;vv<<=1);
			int x=i.se.se[0];
			int y=i.se.se[1];
			lim[x]=v; lim[y]=vv-1-v;
			ans|=vv-1;
		}
	//cout<<ans<<endl;
	for (auto i:mp)
		if (i.se.fi==1){
			int v=i.fi,vv=1,tmp=0;
			for (;vv<=v;vv<<=1);
			for (;vv;vv>>=1)
				if (!(ans&vv)&&tmp+vv<=v)
					tmp+=vv,ans|=vv;
			lim[i.se.se[0]]=tmp;
		}
	puts("YES");
	For(i,1,n) printf("%d ",lim[i]);
}