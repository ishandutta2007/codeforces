#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int mo=1000000007;
const int N=100005;
struct edge{
	int to,next;
}e[N*2];
int head[N],tot;
int n,ans;
ll v[N];
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
struct node{
	ll v[45];
	int st[45];
	int top;
	void insert(ll x,int d){
		v[++top]=x;
		st[top]=d;
		Rep(i,top-1,1)
			x=v[i]=gcd(v[i],x);
		int tmp=1;
		For(i,2,top)
			if (v[i]!=v[i-1]){
				v[++tmp]=v[i];
				st[tmp]=st[i];
			}
		top=tmp;
	}
	int getans(int d){
		int ans=0;
		st[top+1]=d+1;
		For(i,1,top)
			ans=(ans+v[i]*(st[i+1]-st[i]))%mo;
		return ans;
	}
}f[N];
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void getans(int x,int fa,int d){
	f[x]=f[fa];
	f[x].insert(v[x],d);
	ans=(ans+f[x].getans(d))%mo;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa)
			getans(e[i].to,x,d+1);
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%lld",&v[i]);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	getans(1,0,1);
	printf("%d",ans);
}