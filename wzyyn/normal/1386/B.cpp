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
const int N=100005;
int v[5],w[5],id[5];
ll p1[N],p2[N];
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
namespace N1{
	int sum;
	void insert(int x,int fl){
		if (!p1[x]&&!p2[x])
			fl?++sum:--sum;
	}
	bool check(){
		return sum!=0;
	}
}
namespace N2{
	map<pll,int> mp;
	int sum;
	void insert(int x,int fl){
		if (fl==1){
			if (!mp[pll(p1[x],p2[x])])
				if (mp[pll(-p1[x],-p2[x])]) ++sum;
			++mp[pll(p1[x],p2[x])];
		}
		else{
			--mp[pll(p1[x],p2[x])];
			if (!mp[pll(p1[x],p2[x])])
				if (mp[pll(-p1[x],-p2[x])]) --sum;
		}
	}
	bool check(){
		return sum!=0;
	}
}
namespace N3{
	int mn[N*4];
	int mx[N*4];
	int fl[N*4];
	int cmp(int x,int y){
		double v=1.0*p1[x]*p2[y]-1.0*p1[y]*p2[x];
		if (fabs(v)>1e12) return v>0?1:-1;
		ll vv=p1[x]*p2[y]-p1[y]*p2[x];
		return (vv?(vv>0?1:-1):0);
	}
	void pushup(int k){
		int ls=k*2,rs=k*2+1;
		fl[k]=fl[ls]|fl[rs];
		//cout<<k<<' '<<mn[ls]<<' '<<mn[rs]<<endl; 
		if (!mn[ls]||!mn[rs]){
			mn[k]=mn[ls]+mn[rs];
			mx[k]=mx[ls]+mx[rs];
		}
		else{
			if (cmp(mn[ls],mn[rs])==-1&&cmp(mn[ls],mx[rs])==1) fl[k]=1;
			if (cmp(mn[rs],mn[ls])==-1&&cmp(mn[rs],mx[ls])==1) fl[k]=1;
			if (cmp(mx[ls],mn[rs])==-1&&cmp(mx[ls],mx[rs])==1) fl[k]=1;
			if (cmp(mx[rs],mn[ls])==-1&&cmp(mx[rs],mx[ls])==1) fl[k]=1;
			mn[k]=(cmp(mn[ls],mn[rs])==-1?mn[ls]:mn[rs]);
			mx[k]=(cmp(mx[ls],mx[rs])==-1?mx[rs]:mx[ls]);
		}
	}
	void insert(int k,int l,int r,int x,int v){
		//cout<<k<<' '<<l<<' '<<r<<' '<<x<<endl;
		if (l==r){
			mn[k]=mx[k]=v*x;
			fl[k]=0;
			return;
		}
		int mid=(l+r)/2;
		if (x<=mid) insert(k*2,l,mid,x,v);
		else insert(k*2+1,mid+1,r,x,v);
		pushup(k);
	}
	void insert(int x,int v){
		insert(1,1,N-1,x,v);
	}
	bool check(){
		return fl[1];
	}
}
int main(){
	scanf("%d%d%d",&v[1],&v[2],&v[3]);
	id[1]=1; id[2]=2; id[3]=3;
	if (!v[id[1]]) swap(id[1],id[2]);
	if (!v[id[1]]) swap(id[1],id[3]);
	int Q,n=0;
	scanf("%d",&Q);
	while (Q--){
		char s[10];
		scanf("%s",s+1);
		if (s[1]=='A'){
			scanf("%d%d%d",&w[1],&w[2],&w[3]); ++n;
			p1[n]=1ll*w[id[2]]*v[id[1]]-1ll*v[id[2]]*w[id[1]];
			p2[n]=1ll*w[id[3]]*v[id[1]]-1ll*v[id[3]]*w[id[1]];
			//cout<<p1[n]<<' '<<p2[n]<<endl;
			ll G=gcd(abs(p1[n]),abs(p2[n]));
			if (G) p1[n]/=G,p2[n]/=G;
			//cout<<p1[n]<<' '<<p2[n]<<endl;
			N1::insert(n,1);
			//cout<<p1[n]<<' '<<p2[n]<<endl;
			N2::insert(n,1);
			//cout<<p1[n]<<' '<<p2[n]<<endl;
			N3::insert(n,1);
			//cout<<p1[n]<<' '<<p2[n]<<endl;
		}
		else{
			int x;
			scanf("%d",&x);
			N1::insert(x,0);
			N2::insert(x,0);
			N3::insert(x,0);
		}
		if (N1::check()) puts("1");
		else if (N2::check()) puts("2");
		else if (N3::check()) puts("3");
		else puts("0");
	}
}
/*
1 2 3
9
A 5 6 7
A 3 10 17
R 1
A 15 18 19
A 15 18 22
A 5 10 15
A 5 10 15
R 5
R 6

*/