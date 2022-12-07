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
const int S=405;
struct edge{
	int to,next,v;
}e[N*2];
int head[N],tot,n,m;
int dep[N],v[N];
int vis[N],flg[N];
int nd,tr[S][35];
int trr[S][S];
map<ll,int> mp;
ll sta[S];
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
}
int init_state(int v,ll val){
	if (mp[val]) return mp[val];
	mp[val]=++nd; sta[nd]=val;
	For(i,0,31){
		ll nval=val;
		if (val&(1ll<<i)) tr[mp[val]][i]=1;
		else{
			For(j,0,31)
				if (val&(1ll<<j))
					nval|=(1ll<<(j^i));
			tr[mp[val]][i]=init_state(i+1,nval);
		}
	}
	//cout<<val<<' '<<mp[val]<<endl;
	return mp[val];
}
void dfs(int x,int fa,int &S){
	//cout<<x<<endl;
	dep[x]=dep[fa]+1;
	//cout<<x<<' '<<dep[x]<<endl;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa&&!vis[e[i].to]){
			if (!dep[e[i].to]){
				v[e[i].to]=v[x]^e[i].v;
				dfs(e[i].to,x,S);
			}
			else if (dep[e[i].to]<dep[x]){
				//cout<<S<<' '<<(v[e[i].to]^v[x]^e[i].v)<<endl;
				S=tr[S][v[e[i].to]^v[x]^e[i].v];
			}
		}
}
struct oppp{
	int op1,op2,op3,op4;
}op[N];
int op_top;
int f[2][S];
const int mo=1000000007;
void UPD(int &x,int y){
	(x+=y)>=mo?x-=mo:233;
}
pii q[N];
int top,ST[N],val[N];
int main(){
	nd=1;
	init_state(0,1);
	For(i,0,31) tr[1][i]=1;
	For(i,1,nd) trr[i][1]=trr[1][i]=1;
	For(i,2,nd) For(j,2,nd){
		trr[i][j]=i;
		if (sta[i]&sta[j]&((1ll<<32)-2)) trr[i][j]=1;
		else
			For(k,1,31) if (sta[j]&(1ll<<k))
				if (!(sta[trr[i][j]]&(1ll<<k)))
					trr[i][j]=tr[trr[i][j]][k];
		//if (trr[i][j]==1)
	}
	//cout<<trr[2][2]<<' '<<sta[2]<<endl;
	//cout<<nd<<endl;
	scanf("%d%d",&n,&m);
	//cout<<tr[2][9]<<endl;
	For(i,1,m){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		add(x,y,v); add(y,x,v);
	}
	for (int i=head[1];i;i=e[i].next)
		vis[e[i].to]=1,q[++top]=pii(e[i].to,e[i].v);
	vis[1]=1;
	For(i,1,top){
		int now=mp[1];
		//cout<<now<<endl;
		vis[q[i].fi]=0;
		dfs(q[i].fi,0,now);
		vis[q[i].fi]=1;
		ST[q[i].fi]=now;
		val[q[i].fi]=q[i].se;
		//cout<<"INFO "<<now<<' '<<q[i].fi<<endl;
	}
	//cout<<nd<<endl; 
	For(i,1,top) if (!flg[q[i].fi]){
		bool ok=0;
		for (int j=head[q[i].fi];j;j=e[j].next)
			if (e[j].to!=1&&vis[e[j].to]){
				flg[e[j].to]=1;
				//cout<<q[i].fi<<' '<<e[j].to<<endl;
				++op_top;
				int tmp=trr[ST[q[i].fi]][ST[e[j].to]];
				op[op_top].op1=mp[1];
				op[op_top].op2=tmp;
				op[op_top].op3=tmp;
				op[op_top].op4=tr[tmp][val[q[i].fi]^val[e[j].to]^e[j].v];
				ok=1;
			}
		if (!ok){
			++op_top;
			op[op_top].op1=mp[1];
			op[op_top].op2=ST[q[i].fi];
			op[op_top].op3=-1;
			op[op_top].op4=-1;
		}
	}
	memset(f,0,sizeof(f));
	f[0][mp[1]]=1;
	int pre=0,now=1;
	For(i,1,op_top){
		//cout<<op[i].op1<<' '<<op[i].op2<<' '<<mp[1]<<endl;
		For(j,1,nd){
			if (op[i].op1!=-1)
				UPD(f[now][trr[j][op[i].op1]],f[pre][j]);
			if (op[i].op2!=-1)
				UPD(f[now][trr[j][op[i].op2]],f[pre][j]);
			if (op[i].op3!=-1)
				UPD(f[now][trr[j][op[i].op3]],f[pre][j]);
			if (op[i].op4!=-1)
				UPD(f[now][trr[j][op[i].op4]],f[pre][j]);
			f[pre][j]=0;
		}
		swap(pre,now);
	}
	int ans=0;
	For(i,2,nd)
		UPD(ans,f[pre][i]);
	cout<<ans;
}
//WAAAAAA