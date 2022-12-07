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
const int N=100005;
const int B=505;
int ch[N][26],fa[N],qq[N],nd=1;
int n,Q,top,lp[N],rp[N],fl[N];
int id[N],pos[N],dfn[N],ed[N];
int vis[N][205];
char s[N];
vector<int> e[N];
struct node{
	int T,x,v,id;
	bool operator <(const node &a)const{
		return T<a.T;
	}
}q[N*2];
void dfs(int x){	
	dfn[x]=++*dfn;
	For(i,0,e[x].size()-1){
		dfs(e[x][i]);
		For(j,1,*id)
			vis[x][j]+=vis[e[x][i]][j];
	}
	ed[x]=*dfn;
}
void build(){
	int h=0,t=0;
	For(i,0,25)
		if (ch[1][i]){
			qq[++t]=ch[1][i];
			fa[ch[1][i]]=1;
		}
		else
			ch[1][i]=1;
	while (h!=t){
		int x=qq[++h];
		For(i,0,25)
			if (ch[x][i]){
				fa[ch[x][i]]=ch[fa[x]][i];
				qq[++t]=ch[x][i];
			}
			else
				ch[x][i]=ch[fa[x]][i];
	}
	For(i,2,nd)
		e[fa[i]].PB(i);
	dfs(1);
}
ll sum[N],ans[N];
ll S1[N],S2[N];
void update(int id){
	int x=1;
	For(i,lp[id],rp[id]-1)
		x=ch[x][s[i]];
	For(i,1,*::id)
		sum[i]+=vis[x][i];
	int l=dfn[x],r=ed[x];
	int bl=(l-1)/B+1,br=(r-1)/B+1;
	if (bl==br) For(i,l,r) S1[i]++;
	else{
		int pl=bl*B,pr=(br-1)*B+1;
		For(i,l,pl) ++S1[i];
		For(i,pr,r) ++S1[i];
		For(i,bl+1,br-1) ++S2[i];
	}
}
ll ask(int id){
	if (::id[id])
		return sum[::id[id]];
	int x=1,ans=0;
	For(i,lp[id],rp[id]-1){
		x=ch[x][s[i]];
		ans+=S1[dfn[x]]+S2[(dfn[x]-1)/B+1];
		//printf("Q %d %d %d %d\n",id,i,x,dfn[x]);
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n){
		lp[i]=rp[i-1];
		scanf("%s",s+lp[i]);
		rp[i]=strlen(s+lp[i])+lp[i];
		fl[i]=(rp[i]-lp[i]>=B);
		if (fl[i]) id[i]=++*id;
		int x=1;
		For(j,lp[i],rp[i]-1){
			int c=(s[j]-='a');
			if (!ch[x][c]) ch[x][c]=++nd;
			x=ch[x][c];
			if (fl[i])
				vis[x][id[i]]=1;
		}
	}
	build();
	For(i,1,Q){
		int l,r,x;
		scanf("%d%d%d",&l,&r,&x);
		if (l-1)
			q[++top]=(node){l-1,x,-1,i};
		q[++top]=(node){r,x,1,i};
	}
	sort(q+1,q+top+1);
	int pos=1;
	For(i,1,n){
		update(i);
		for (;pos<=top&&q[pos].T==i;++pos)
			ans[q[pos].id]+=q[pos].v*ask(q[pos].x);
		//printf("clk %d\n",i);
	}
	For(i,1,Q)
		printf("%lld\n",ans[i]);
}