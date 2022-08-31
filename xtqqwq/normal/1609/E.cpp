// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,q;
int a[300000],b[300000],c[300000],ab[300000],bc[300000],abc[300000];
char s[100005];

void update(int id){
	a[id]=a[id<<1]+a[id<<1|1];
	b[id]=b[id<<1]+b[id<<1|1];
	c[id]=c[id<<1]+c[id<<1|1];
	ab[id]=min(ab[id<<1]+b[id<<1|1],a[id<<1]+ab[id<<1|1]);
	bc[id]=min(bc[id<<1]+c[id<<1|1],b[id<<1]+bc[id<<1|1]);
	abc[id]=min(min(a[id<<1]+abc[id<<1|1],abc[id<<1]+c[id<<1|1]),ab[id<<1]+bc[id<<1|1]);
}

void build(int id,int l,int r){
	if(l==r){
		if(s[l]=='a') a[id]=1;
		if(s[l]=='b') b[id]=1;
		if(s[l]=='c') c[id]=1;
		return;
	}
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	update(id);
}

void change(int id,int l,int r,int x,char ch){
	if(l==r){
		a[id]=b[id]=c[id]=ab[id]=bc[id]=abc[id]=0;
		if(ch=='a') a[id]=1;
		if(ch=='b') b[id]=1;
		if(ch=='c') c[id]=1;
		return;
	}
	int mid=(l+r)/2;
	if(x<=mid) change(id<<1,l,mid,x,ch);
	else change(id<<1|1,mid+1,r,x,ch);
	update(id);
}

int main(){
	n=readint(); q=readint();
	scanf("%s",s+1);
	build(1,1,n);
	while(q--){
		int i; char ch;
		i=readint(); ch=getchar();
		while(ch!='a'&&ch!='b'&&ch!='c') ch=getchar();
		change(1,1,n,i,ch);
		printf("%d\n",abc[1]);
	}
	return 0;
}