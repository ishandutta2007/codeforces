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
const int N=1000005;
struct edge{
	int to,next,id;
}e[N*2];
int fl[N],tr[N],id[N],mn[N];
int head[N],tot,n,ans;
int q[N],d[N],fr[N];
void add(int x,int y,int i){
	x=id[x]; y=id[y];
	//cout<<"E "<<x<<' '<<y<<endl;
	e[++tot]=(edge){y,head[x],i};
	head[x]=tot;
	e[++tot]=(edge){x,head[y],i};
	head[y]=tot;
}
void UPD(int S){
	S=id[S];
	For(i,1,*id) d[i]=-1,fr[i]=0;
	int h=0,t=1;
	q[1]=S; d[S]=0;
	while (h!=t){
		int x=q[++h];
		for (int i=head[x];i;i=e[i].next)
			if (e[i].id!=fr[x])
				if (d[e[i].to]!=-1)
					ans=min(ans,d[e[i].to]+d[x]+1);
				else{
					d[e[i].to]=d[x]+1;
					fr[e[i].to]=e[i].id;
					q[++t]=e[i].to;
				}
	}
}
void sieve(){
	For(i,2,N-1) if (!fl[i])
		For(j,2,(N-1)/i) fl[i*j]=1;
	For(i,1,N-1) tr[i]=i;
	id[1]=++*id;
	For(i,2,N-1) if (!fl[i]){
		id[i]=++*id;
		For(j,1,(N-1)/i/i)
			for (;tr[i*i*j]%(i*i)==0;tr[i*i*j]/=i*i);
		For(j,1,(N-1)/i) mn[i*j]=i;
	}
}
int main(){
	sieve();
	scanf("%d",&n);
	For(i,1,n){
		int x;
		scanf("%d",&x);
		//cout<<tr[x]<<endl;
		if (tr[x]==1) return puts("1"),0;
		x=tr[x];
		if (mn[x]==x) add(x,1,i);
		else add(mn[x],x/mn[x],i);
	}
	ans=1<<30;
	For(i,1,1000) if (!fl[i]) UPD(i);
	printf("%d\n",ans==1<<30?-1:ans);
}