#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,now;
int a[300005],pl[300005],b[300005],lazy[1100000],mina[1100000];

void pushdown(int id){
	if(lazy[id]){
		lazy[id<<1]+=lazy[id],lazy[id<<1|1]+=lazy[id];
		mina[id<<1]+=lazy[id],mina[id<<1|1]+=lazy[id];
		lazy[id]=0;
	}
}

void change(int id,int l,int r,int ql,int qr,int c){
	if(ql==l&&qr==r) return (void)(lazy[id]+=c,mina[id]+=c);
	pushdown(id);
	int mid=(l+r)/2;
	if(qr<=mid) change(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,c);
	else change(id<<1,l,mid,ql,mid,c),change(id<<1|1,mid+1,r,mid+1,qr,c);
	mina[id]=min(mina[id<<1],mina[id<<1|1]);
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint(),pl[a[i]]=i;
	for(int i=1;i<=n;i++) b[i]=readint();
	now=n;
	change(1,1,n,1,pl[n],-1);
	for(int i=1;i<=n;i++){
		printf("%d ",now);
		if(i==n) break;
		change(1,1,n,1,b[i],1);
		while(1){
			if(mina[1]>=0){
				now--;
				change(1,1,n,1,pl[now],-1);
			}
			else break;
		}
	}
	printf("\n");
	return 0;
}