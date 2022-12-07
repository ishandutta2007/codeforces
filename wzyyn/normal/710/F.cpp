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
struct AK{
	int ch[N][26],fa[N];
	int num[26],rt[26];
	int flg[N],sum[N];
	int top,nd;
	int merge(int x,int y){
		if (!x||!y) return x+y;
		flg[x]|=flg[y];
		For(i,0,25)
			ch[x][i]=merge(ch[x][i],ch[y][i]);
		return x;
	}
	int q[N];
	void build_fail(int rt){
		int h=0,t=0,y;
		For(i,0,25)
			if (y=ch[rt][i]){
				fa[y]=rt;
				q[++t]=y;
				sum[y]=flg[y];
			}
		while (h!=t){
			int x=q[++h];
			//cout<<x<<' '<<h<<' '<<t<<endl;
			For(i,0,25)
				if (ch[x][i]){
					int y=ch[x][i],p=fa[x];
					for (;p!=rt&&!ch[p][i];p=fa[p]);
					fa[y]=(ch[p][i]?ch[p][i]:rt);
					q[++t]=y; sum[y]=sum[fa[y]]+flg[y];
				}
		}
	}
	void insert(char *c){
		int x=rt[++top]=++nd;
		num[top]=1; fa[x]=x;
		for (int i=1;c[i];++i)
			x=(ch[x][c[i]-'a']=++nd);
		flg[x]=1;
		//cout<<x<<endl;
		for (;top&&num[top]==num[top-1];--top)
			num[top-1]*=2,rt[top-1]=merge(rt[top-1],rt[top]);
		//cout<<top<<endl;
		build_fail(rt[top]);
	}
	int ask(char *c){
		int ans=0;
		for (int i=1;i<=top;i++){
			int x=rt[i];
			for (int j=1;c[j];++j){
				for (;x!=rt[i]&&!ch[x][c[j]-'a'];x=fa[x]);
				if (ch[x][c[j]-'a'])
					x=ch[x][c[j]-'a'];
				ans+=sum[x];
			}
		}
		//cout<<ans<<endl;
		return ans;
	}
}S1,S2;
char s[N];
int main(){
	int Q;
	scanf("%d",&Q);
	while (Q--){
		int tp;
		scanf("%d%s",&tp,s+1);
		if (tp==1) S1.insert(s);
		if (tp==2) S2.insert(s);
		if (tp==3){
			printf("%d\n",S1.ask(s)-S2.ask(s));
			fflush(stdout);
		}
	}
}