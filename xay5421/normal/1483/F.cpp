// author: xay5421
// created: Wed Mar 24 15:20:36 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<cstdio>
#include<cstring>
#include<algorithm>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=1000005;
int n,ch[N][26],ind,pre[N],key[N],q[N],he,ta,fa[N],tin[N],tou[N],pos[N],length[N],tim;
bool pd[N],ok[N];
char s[N];
vector<int>e[N];
void dfs(int k1){
	tin[k1]=++tim;
	for(int x:e[k1]){
		if(key[x]==0)key[x]=key[k1];
		dfs(x);
	}
	tou[k1]=tim;
}
struct BIT{
	int t[N];
	void upd(int k1,int k2){
		for(int i=k1;i<=tim;i+=i&-i)t[i]+=k2;
	}
	int qry(int k1){
		int k2=0;
		for(int i=k1;i;i&=i-1)k2+=t[i];
		return k2;
	}
}t;
void init(){
	rep(i,0,25)if(ch[0][i])q[++ta]=ch[0][i];
	while(he!=ta){
		int k1=q[++he];
		rep(i,0,25){
			if(ch[k1][i]){
				fa[ch[k1][i]]=ch[fa[k1]][i];
				q[++ta]=ch[k1][i];
			}else{
				ch[k1][i]=ch[fa[k1]][i];
			}
		}
	}
	rep(i,1,ind)e[fa[i]].push_back(i);
	dfs(0);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%s",s);
		int k1=0;
		for(int j=0;s[j];++j){
			if(!ch[k1][s[j]-'a'])ch[k1][s[j]-'a']=++ind,pre[ind]=k1,length[ind]=length[k1]+1;
			k1=ch[k1][s[j]-'a'];
		}
		pd[k1]=1,key[k1]=k1,pos[i]=k1;
	}
	init();
	int ans=0;
	rep(now,1,n){
		static int a[N];
		int len=0;
		{
			int x=pos[now];
			while(x){
				int y=key[x==pos[now]?fa[x]:x];
				if(y)a[++len]=y;
				x=pre[x];
			}
		}
		sort(a+1,a+1+len,[&](int x,int y){return length[x]^length[y]?length[x]>length[y]:x<y;});
		len=unique(a+1,a+1+len)-a-1;
		rep(i,1,len)ok[a[i]]=1;
		{
			int x=pos[now],mn=1e9;
			while(x){
				int y=key[x==pos[now]?fa[x]:x];
				if(y){
					if(length[x]-length[y]+1>=mn)ok[y]=0;
					else mn=length[x]-length[y]+1;
				}
				x=pre[x];
			}
		}
		rep(i,1,len){
			ok[a[i]]&=t.qry(tin[a[i]]-1)==t.qry(tou[a[i]]);
			t.upd(tin[a[i]],1);
		}
		rep(i,1,len)ans+=ok[a[i]],t.upd(tin[a[i]],-1);
		//D("ans=%d\n",ans);
	}
	printf("%d\n",ans);
	return 0;
}