#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
namespace fastio{
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getchar();T neg=0;
		while(!isdigit(c)) neg|=!(c^'-'),c=getchar();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		if(neg) x=(~x)+1;
	}
	template<typename T> void recursive_print(T x){return (!x)?void():(recursive_print(x/10),putc(x%10^48),void());}
	template<typename T> void print(T x){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);}
	template<typename T> void print(T x,char c){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=5e5;
const int LOG_N=20;
const int MOD=1e9+7;
int qpow(int x,int e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
int n,qu,ncnt,sum[MAXN+5],dep[MAXN+5];char s[MAXN+5];
int nt[MAXN+5],pr[MAXN+5];
vector<int> son[MAXN+5];
vector<pii> itvl[MAXN+5];
int mch[MAXN+5],rt,bel[MAXN+5],op[MAXN+5],val[MAXN+5];
int pre[MAXN+5],pw10[MAXN+5];
int getnum(int l,int r){return (pre[r]-1ll*pre[l-1]*pw10[r-l+1]%MOD+MOD)%MOD;}
int build(int l,int r){
	if(s[l]=='('&&mch[l]==r) return bel[l]=bel[r]=build(l+1,r-1);
	int opt=-1,id=++ncnt;
	for(int i=l;i<=r;){
		if(s[i]=='+') opt=0;
		else if(s[i]=='*'&&!~opt) opt=1;
		if(s[i]=='(') i=mch[i]+1;
		else i++;
	} op[id]=opt;
	if(!~opt){
		for(int i=l;i<=r;i++){
			bel[i]=id;
			val[id]=(10ll*val[id]+s[i]-'0')%MOD;
		} return id;
	} int pre=l-1;
	for(int i=l;i<=r;){
		if((s[i]=='+'&&!opt)||(s[i]=='*'&&opt)){
			son[id].pb(build(pre+1,i-1));
			itvl[id].pb(mp(pre+1,i-1));
			pre=i;bel[i]=id;
		} if(s[i]=='(') i=mch[i]+1;
		else i++;
	} son[id].pb(build(pre+1,r));itvl[id].pb(mp(pre+1,r));
//	printf("build [%d,%d]:\n",l,r);
//	printf("op[%d]=%d\n",id,op[id]);
//	for(int x:son[id]) printf("%d ",x);printf("\n");
//	for(pii p:itvl[id]) printf("[%d,%d]\n",p.fi,p.se);
//	printf("\n");
	return id;
}
struct num0{
	int x,y;
	num0(int _x=0){(_x)?(x=_x,y=0):(x=y=1);}
	int val(){return (y)?0:x;}
	num0 operator +(const int &rhs){
		int sum=(val()+rhs)%MOD;
		return (sum)?num0(sum):num0(0);
	}
	num0 operator *(const int &rhs){
		num0 res=*this;
		(rhs)?(res.x=1ll*res.x*rhs%MOD):(res.y++);
		return res;
	}
	num0 operator /(const num0 &rhs){
		num0 res;res.x=1ll*x*qpow(rhs.x,MOD-2)%MOD;
		res.y=y-rhs.y;return res;
	}
};
vector<num0> ss[MAXN+5];
void calc(int x){
	if(~op[x]) val[x]=op[x];
	ss[x].resize(son[x].size());
	for(int i=0;i<son[x].size();i++){
		int y=son[x][i];dep[y]=dep[x]+1;calc(y);
		if(!i) ss[x][i]=val[y];
		if(op[x]==0){
			val[x]=(val[x]+val[y])%MOD;
			if(i) ss[x][i]=ss[x][i-1]+val[y];
		} else {
			val[x]=1ll*val[x]*val[y]%MOD;
			if(i) ss[x][i]=ss[x][i-1]*val[y];
		}
//		printf("%d %d %d\n",x,i,ss[x][i].val());
	}
}
int st_sum[MAXN+5][LOG_N+2];
pii st_dep[MAXN+5][LOG_N+2];
void buildst(){
	for(int i=1;i<=LOG_N;i++) for(int j=1;j+(1<<i)-1<=n;j++){
		st_sum[j][i]=min(st_sum[j][i-1],st_sum[j+(1<<i-1)][i-1]);
		st_dep[j][i]=min(st_dep[j][i-1],st_dep[j+(1<<i-1)][i-1]);
	}
}
int query_sum(int l,int r){
	int k=31-__builtin_clz(r-l+1);
	return min(st_sum[l][k],st_sum[r-(1<<k)+1][k]);
}
pii query_dep(int l,int r){
	int k=31-__builtin_clz(r-l+1);
	return min(st_dep[l][k],st_dep[r-(1<<k)+1][k]);
}
int main(){
//	freopen("calc.in","r",stdin);
//	freopen("calc.out","w",stdout);
	scanf("%s%d",s+1,&qu);n=strlen(s+1);
	for(int i=1;i<=n;i++){
		if(isdigit(s[i])) pre[i]=(10ll*pre[i-1]+s[i]-'0')%MOD;
		else pre[i]=pre[i-1];
	}
	for(int i=(pw10[0]=1);i<=n;i++) pw10[i]=10ll*pw10[i-1]%MOD;
	stack<int> stk;
	for(int i=1;i<=n;i++){
		if(s[i]=='(') stk.push(i),sum[i]=sum[i-1]+1;
		else if(s[i]==')'){
			mch[i]=stk.top();mch[stk.top()]=i;
			stk.pop();sum[i]=sum[i-1]-1;
		} else sum[i]=sum[i-1];
	}
	int pp=n+1;
	for(int i=n;i;i--){
		if(!isdigit(s[i])) pp=i;
		else nt[i]=pp-1;
	} pp=0;
	for(int i=1;i<=n;i++){
		if(!isdigit(s[i])) pp=i;
		else pr[i]=pp+1;
	}
//	for(int i=1;i<=n;i++) printf("%d%c",mch[i]," \n"[i==n]);
	rt=build(1,n);calc(rt);
//	for(int i=1;i<=n;i++) printf("%d%c",bel[i]," \n"[i==n]);
	for(int i=1;i<=n;i++) st_sum[i][0]=sum[i],st_dep[i][0]=mp(dep[bel[i]],i);
	buildst();
	while(qu--){
		int l,r;scanf("%d%d",&l,&r);
		if(sum[l-1]!=sum[r]){puts("-1");continue;}
		if(query_sum(l,r)<sum[l-1]){puts("-1");continue;}
		if(s[l]=='+'||s[l]=='*'){puts("-1");continue;}
		if(s[r]=='+'||s[r]=='*'){puts("-1");continue;}
		pii p=query_dep(l,r);int x=bel[p.se];
//		printf("%d\n",x);
		if(!~op[x]){
			if(isdigit(s[l])&&isdigit(s[r])) printf("%d\n",getnum(l,r));
			else printf("%d\n",val[x]);
			continue;
		}
		int L=upper_bound(itvl[x].begin(),itvl[x].end(),mp(l,n+1))-itvl[x].begin()-1;
		int R=upper_bound(itvl[x].begin(),itvl[x].end(),mp(r,n+1))-itvl[x].begin()-1;
		if(L<0) L=0;
		int u=son[x][L],v=son[x][R];
//		printf("%d %d\n",L,R);
		if(op[x]==1){
			int res=1;
			if(L!=R){
				num0 qwq=ss[x][R-1]/ss[x][L];
				res=qwq.val();
			}
			if(~op[u]) res=1ll*res*val[u]%MOD;
			else{
				if(isdigit(s[l])) res=1ll*res*getnum(l,nt[l])%MOD;
				else res=1ll*res*val[u]%MOD;
			} if(~op[v]) res=1ll*res*val[v]%MOD;
			else{
				if(isdigit(s[r])) res=1ll*res*getnum(pr[r],r)%MOD;
				else res=1ll*res*val[v]%MOD;
			}
			printf("%d\n",res);
		} else {
			int res=0;
			if(L!=R) res=(ss[x][R-1].val()-ss[x][L].val()+MOD)%MOD;
			if(~op[u]){
				if(op[u]==0) res=(res+val[u])%MOD;
				else{
					int LL=upper_bound(itvl[u].begin(),itvl[u].end(),mp(l,n+1))-itvl[u].begin()-1;
					if(LL<0) LL=0;
					int su=son[u][LL],mul=1;
					if(LL+1!=ss[u].size())
						mul=(ss[u].back()/ss[u][LL]).val();
					if(~op[su]) mul=1ll*mul*val[su]%MOD;
					else{
						if(isdigit(s[l])) mul=1ll*mul*getnum(l,nt[l])%MOD;
						else mul=1ll*mul*val[su]%MOD;
					}
					res=(res+mul)%MOD;
				}
			} else{
				if(isdigit(s[l])) res=(res+getnum(l,nt[l]))%MOD;
				else res=(res+val[u])%MOD;
			}
			if(~op[v]){
				if(op[v]==0) res=(res+val[v])%MOD;
				else{
					int RR=upper_bound(itvl[v].begin(),itvl[v].end(),mp(r,n+1))-itvl[v].begin()-1;
					int sv=son[v][RR],mul=1;
					if(RR) mul=(ss[v][RR-1]).val();
					if(~op[sv]) mul=1ll*mul*val[sv]%MOD;
					else{
						if(isdigit(s[r])) mul=1ll*mul*getnum(pr[r],r)%MOD;
						else mul=1ll*mul*val[sv]%MOD;
					}
					res=(res+mul)%MOD;
				}
			} else{
				if(isdigit(s[r])) res=(res+getnum(pr[r],r))%MOD;
				else res=(res+val[v])%MOD;
			}
			printf("%d\n",res);
		}
	}
	return 0;
}
/*
20 8
(1+(2+3)*4+5*6)+78*9
2 8
10 12
2 12
4 14
17 18
18 20
15 20
1 2

10 7
1+((1234))
3 10
4 9
6 8
5 9
3 9
1 9
1 10

30 7
(12*34)*(56)+(78)*((910*1112))
22 27
21 27
9 12
9 17
1 17
9 30
9 29
*/