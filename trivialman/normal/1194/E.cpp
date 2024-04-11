#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
#define PII pair<int,int>
typedef long long LL;
//const LL MOD = 998244353;
const int N = 10010;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct dat{
	int l,r,z;
}a[N],b[N];
int n,tr[N],x1[N],x2[N],y1[N],y2[N];

inline void add(int x,int val){
	for(;x<N;x+=x&-x)tr[x]+=val;
}
inline int sum(int x){
	int res = 0;
	for(;x;x-=x&-x)res+=tr[x];
	return res;
}
inline int sum(int l,int r){
	return sum(r)-sum(l-1);
}

int main(){
	//freopen("test.in","r",stdin);
	scanf("%d",&n);
	int nh=0,nv;
	rep(i,1,n)scanf("%d%d%d%d",x1+i,y1+i,x2+i,y2+i),nh+=(y1[i]==y2[i]);
	if(nh>n/2){
		rep(i,1,n)swap(x1[i],y1[i]),swap(x2[i],y2[i]);
	}
	int C=5005;
	rep(i,1,n){
		if(x1[i]>x2[i])swap(x1[i],x2[i]);
		if(y1[i]>y2[i])swap(y1[i],y2[i]);
		x1[i]+=C,x2[i]+=C,y1[i]+=C,y2[i]+=C;
	}
	nh=nv=0;
	rep(i,1,n)
		if(y1[i]==y2[i]) a[++nh]={x1[i],x2[i],y1[i]};
		else b[++nv]={y1[i],y2[i],x1[i]};
	sort(a+1,a+nh+1,[](dat x,dat y){return x.z>y.z;});
	sort(b+1,b+nv+1,[](dat x,dat y){return x.r>y.r;});
	LL ans = 0;
	rep(i,2,nh){
		memset(tr,0,sizeof tr);
		int k=1;
		rep(j,1,i-1){
			for(;k<=nv&&b[k].r>=a[j].z;++k)
				if(b[k].l<=a[i].z)add(b[k].z,1);
			int l=max(a[i].l,a[j].l), r=min(a[i].r,a[j].r);
			if(r>=l){
				LL x = sum(l,r);
				ans += x*(x-1)/2;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}