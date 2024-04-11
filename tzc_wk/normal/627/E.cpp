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
	template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc(x%10^48);}
	template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=3e3; 
int R,C,n,k,x[MAXN+5],y[MAXN+5];
vector<int> vr[MAXN+5],vc[MAXN+5];
int l[MAXN+5],r[MAXN+5];ll ans=0;
int main(){
	scanf("%d%d%d%d",&R,&C,&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
		vr[x[i]].pb(i);vc[y[i]].pb(i);
	}
	for(int i=1;i<=MAXN;i++) sort(vr[i].begin(),vr[i].end(),[](int lhs,int rhs){return y[lhs]>y[rhs];});
	for(int i=1;i<=MAXN;i++) sort(vc[i].begin(),vc[i].end(),[](int lhs,int rhs){return x[lhs]<x[rhs];});
	for(int i=1;i<=R;i++){
		memset(l,0,sizeof(l));memset(r,0,sizeof(r));
		int pre=0;
		for(int j=1;j<=C;j++) for(int t=0;t<vc[j].size();t++)
			if(x[vc[j][t]]>=i){
				int id=vc[j][t];l[id]=pre;
				if(pre) r[pre]=id;pre=id;
			}
		ll ret=0;
		for(int j=1;j<=C;j++) for(int t=0;t<vc[j].size();t++)
			if(x[vc[j][t]]>=i){
				int id=vc[j][t],cur=id;
				for(int stp=1;stp<k;stp++) cur=r[cur];
//				printf("%d %d\n",id,cur);
				if(cur) ret+=1ll*(C-y[cur]+1)*(y[id]-y[l[id]]);
			}
//		printf("%d %d %lld\n",i,R,ret);
		ans+=ret;
		for(int j=R;j>=i;j--){
			for(int t=0;t<vr[j].size();t++){
				int id=vr[j][t];
				if(!r[id]){
					int cur=id;
					for(int stp=1;stp<k;stp++) cur=l[cur];
					if(cur) ret-=1ll*(y[cur]-y[l[cur]])*(C-y[id]+1);
					if(r[id]) l[r[id]]=l[id];
					if(l[id]) r[l[id]]=r[id];
					continue;
				}
				int cr=r[id],cl=r[id],stp=0;
				while(stp<k-1){if(!r[cr]) break;cr=r[cr];++stp;}
				for(int o=1;o<=k-1-stp;o++) cl=l[cl];
				if(cl) ret-=1ll*(C-y[cr]+1)*(y[cl]-y[l[cl]]);
				for(int o=1;o<=stp+1;o++){
					cr=l[cr];cl=l[cl];
					if(cl) ret-=1ll*(C-y[cr]+1)*(y[cl]-y[l[cl]]);
				}
				if(r[id]) l[r[id]]=l[id];
				if(l[id]) r[l[id]]=r[id];
				if(!r[id]) continue;
				cr=r[id],cl=r[id],stp=0;
				while(stp<k-1){if(!r[cr]) break;cr=r[cr];++stp;}
				for(int o=1;o<=k-1-stp;o++) cl=l[cl];
				if(cl) ret+=1ll*(C-y[cr]+1)*(y[cl]-y[l[cl]]);
				for(int o=1;o<=stp;o++){
					cr=l[cr];cl=l[cl];
					if(cl) ret+=1ll*(C-y[cr]+1)*(y[cl]-y[l[cl]]);
				}
			} ans+=ret;
//			printf("%d %d %lld\n",i,j-1,ret);
		}
	} printf("%lld\n",ans);
	return 0;
}
/*
10 10 10 4
7 9
8 1
5 7
6 8
6 4
5 8
4 3
1 3
5 1
6 9

4 4 3 1
1 3
2 2
3 4

5 5 5 2
1 2
1 5
3 4
4 3
5 2
*/