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
const int N=605;
int n,a[N],b[N],mxv,mxp;
int read(){
	char s[10];
	scanf("%s",s+1);
	int l=strlen(s+1),v=0;
	if (s[1]=='?') return -1;
	For(i,1,l) v=v*10+s[i]-'0';
	return v;
}

namespace Flow{
	struct edge{
		int to,next,f; 
	}e[N*N*4];
	int head[N*2],tot,S,T;
	int dis[N*2],q[N*2];
	void init(int _S,int _T){
		memset(head,0,sizeof(head));
		S=_S; T=_T; tot=1;
	}
	void add(int x,int y,int f){
		//cout<<"E "<<x<<' '<<y<<' '<<f<<endl;
		e[++tot]=(edge){y,head[x],f};
		head[x]=tot;
		e[++tot]=(edge){x,head[y],0};
		head[y]=tot;
	}
	bool bfs(){
		For(i,0,2*N-1) dis[i]=-1;
		int h=0,t=1; q[1]=S; dis[S]=0; 
		while (h!=t){
			int x=q[++h];
			for (int i=head[x];i;i=e[i].next)
				if (dis[e[i].to]==-1&&e[i].f){
					dis[e[i].to]=dis[x]+1;
					if (e[i].to==T) return 1;
					q[++t]=e[i].to;
				}
		}
		return 0;
	}
	int dfs(int x,int flow){
		if (x==T) return flow;
		int k,rest=flow;
		for (int i=head[x];i&&rest;i=e[i].next)
			if (dis[e[i].to]==dis[x]+1&&e[i].f){
				k=dfs(e[i].to,min(rest,e[i].f));
				e[i].f-=k; e[i^1].f+=k; rest-=k;
			}
		if (rest) dis[x]=-1;
		return flow-rest;
	}
	int flow(){
		int ans=0;
		for (;bfs();ans+=dfs(S,1<<30));
		return ans;
	}
	vector<int> Path(){
		vector<int> ans;
		ans.PB(T);
		for (int i=T;i!=S;)
			for (int j=head[i];j;j=e[j].next)
				if (j%2==1&&e[j].f){
					e[j].f--; e[j^1].f++;
					ans.PB(i=e[j].to);
					break;
				}
		reverse(ans.begin(),ans.end());
		return ans;
	}
}
void check(){
	int nd=n,sum=0;
	int S=++nd,T=++nd;
	Flow::init(S,T);
	static int mx[N],num[N],id[N][N],used[N];
	static pii at[N];
	For(i,1,n) mx[i]=-1,num[i]=0,used[i]=0;
	For(i,1,n) if (b[i]!=-1) used[b[i]]=1;
	For(i,1,n) if (!a[i]&&b[i]!=-1) ++num[b[i]];
	For(i,1,n) if (a[i]>0&&b[i]!=-1) mx[b[i]]=max(mx[b[i]],a[i]);
	For(i,1,n){
		num[i]+=(i-num[i]%i)%i;
		if (!num[i]&&used[i]) num[i]+=i;
		//cout<<i<<' '<<num[i]<<' '<<mx[i]<<endl;
		sum+=num[i]+max(mx[i],0);
	}
	//cout<<sum<<endl;
	if (sum>n) return;
	For(i,1,n)
		if (!a[i]&&b[i]!=-1)
			--num[b[i]],--sum;
		else Flow::add(S,i,1);
	For(i,1,n){
		For(j,0,max(mx[i],0)) id[i][j]=++nd,at[nd]=pii(i,j);
		For(j,1,mx[i]) Flow::add(id[i][j],T,1);
		Flow::add(id[i][0],T,num[i]);
	}
	For(i,1,n) For(j,1,n) For(k,0,max(mx[j],0))
		if ((a[i]==-1||a[i]==k)&&(b[i]==-1||b[i]==j))
			Flow::add(i,id[j][k],1);
	int val=Flow::flow();
	//cout<<val<<' '<<sum<<' '<<num[3]<<' '<<mxp<<endl;
	if (val!=sum) return;
	For(i,1,sum){
		vector<int> p=Flow::Path();
		//for (auto j:p) cout<<j<<' '; cout<<endl;
		//cout<<i<<endl;
		assert(p.size()==4);
		int x=p[1],y=p[2];
		//cout<<p[0]<<' '<<p[1]<<' '<<p[2]<<' '<<p[3]<<endl;
		if (a[x]==-1) a[x]=at[y].se;
		if (b[x]==-1) b[x]=at[y].fi;
		assert(pii(b[x],a[x])==at[y]);
	}
	//cout<<mxp<<' '<<b[mxp]<<endl;
	For(i,1,n){
		if (a[i]==-1&&b[i]==-1) a[i]=0,b[i]=1;
		if (a[i]==-1) a[i]=1;
		if (b[i]==-1) b[i]=(a[i]==0?1:b[mxp]);
		//cout<<a[i]<<' '<<b[i]<<endl;
	}
	static int par[N];
	For(i,1,n){
		static int lab[N];
		For(j,1,n) if (b[j]==i) lab[a[j]]=j;
		For(j,1,n) if (b[j]==i&&a[j]) par[j]=lab[a[j]-1];
		int len=0,las=0,fir=0;
		For(j,1,n) if (b[j]==i&&!a[j]){
			//cout<<i<<' '<<j<<endl;
			len?par[j]=las:fir=j; las=j;
			if ((++len)==i) len=0,par[fir]=j;
		}
	}
	For(i,1,n) printf("%d ",par[i]);
	exit(0);
}
int main(){
	#ifdef zyy
		freopen("1.in","r",stdin);
	#endif
	n=read();
	mxv=-1;
	For(i,1,n){
		a[i]=read(),b[i]=read();
		if (a[i]>mxv&&b[i]==-1)
			mxv=a[i],mxp=i;
	}
	if (!mxp){
		check();
		puts("-1");
	}
	else{
		//cout<<mxp<<endl;
		For(i,1,n){
			b[mxp]=i;
			check();
			b[mxp]=-1;
		} 
		puts("-1");
	}
}