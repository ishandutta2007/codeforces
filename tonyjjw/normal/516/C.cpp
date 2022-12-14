//*
#include<stdio.h>
#include<tuple>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define MN 200000
#define TN 262144
#define INF 1e18
using namespace std;

typedef __int64 ll;

int N,M;
int d[MN],h[MN];
tuple<ll,ll,ll,ll> T[2*TN],ans; // total, left, right, len

void set(int n,int L,int R){
	if(L==R){
		T[n]=mt(-INF,h[L],h[L],0);
		return;
	}
	int M=(L+R)>>1;
	set(2*n,L,M);
	set(2*n+1,M+1,R);
	ll lv[4],rv[4],v[4];
	tie(lv[0],lv[1],lv[2],lv[3])=T[2*n];
	tie(rv[0],rv[1],rv[2],rv[3])=T[2*n+1];
	v[0]=max(max(lv[0],rv[0]),lv[2]+d[M]+rv[1]);
	v[1]=max(lv[1],lv[3]+d[M]+rv[1]);
	v[2]=max(rv[2],rv[3]+d[M]+lv[2]);
	v[3]=lv[3]+d[M]+rv[3];
	T[n]=mt(v[0],v[1],v[2],v[3]);
}

int updated;
int last;

void get(int n,int L,int R,int l,int r){
	if(r<L || R<l)return;
	if(l<=L && R<=r){
		if(!updated){
			updated=1;
			ans=T[n];
			last=R;
			return;
		}
		ll lv[4],rv[4],v[4];
		tie(lv[0],lv[1],lv[2],lv[3])=ans;
		tie(rv[0],rv[1],rv[2],rv[3])=T[n];
		v[0]=max(max(lv[0],rv[0]),lv[2]+d[last]+rv[1]);
		v[1]=max(lv[1],lv[3]+d[last]+rv[1]);
		v[2]=max(rv[2],rv[3]+d[last]+lv[2]);
		v[3]=lv[3]+d[last]+rv[3];
		ans=mt(v[0],v[1],v[2],v[3]);
		last=R;
		return;
	}
	int M=(L+R)>>1;
	get(2*n,L,M,l,r);
	get(2*n+1,M+1,R,l,r);
}

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)scanf("%d",&d[i]);
	for(int i=0;i<N;i++){
		scanf("%d",&h[i]);
		h[i]*=2;
	}
	for(int i=N;i<2*N;i++){
		h[i]=h[i-N];
		d[i]=d[i-N];
	}
	set(1,0,2*N-1);
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d%d",&a,&b),--a,--b;
		tie(a,b)=mt(b+1,a-1);
		if(a>=N)a-=N;
		if(b<0)b+=N;
		if(a>b)b+=N;
		updated=0;
		get(1,0,2*N-1,a,b);
		ll val=get<0>(ans);
		printf("%I64d\n",val);
	}
	return 0;
}
//*/