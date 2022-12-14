#include <cstdio>
namespace io{
	#define cs const
	#define il __inline__ __attribute__((always_inline))
	#define tpl template
	#define tpn typename
	typedef cs int&ci;
#ifdef LOCAL
	using std::getchar;
	using std::putchar;
#else	
	const size_t _I_Buffer_Size = 1 << 23, _O_Buffer_Size = 1 << 23;
	char _I_Buffer[_I_Buffer_Size],*_I_pos=_I_Buffer-1;
    const char *_I_end=_I_Buffer + _I_Buffer_Size;
    char _O_Buffer[_O_Buffer_Size],*_O_pos=_O_Buffer-1;
    const char *_O_end=_O_Buffer + _O_Buffer_Size,*_O_preend=_O_end-1;
    struct io{
		il ~io(){
			fwrite(_O_Buffer,1,_O_pos-_O_Buffer+1,stdout);
		}
	}ios;
    il char getchar(){
        return *((++_I_pos==_I_end)?fread(_I_Buffer,1,_I_Buffer_Size,stdin),_I_pos=_I_Buffer:_I_pos);
    }
    il void putchar(ci x){
        *((_O_pos==_O_preend)?fwrite(_O_Buffer,1,_O_end-_O_Buffer,stdout),_O_pos = _O_Buffer:++_O_pos)=x;
    }
#endif
	tpl<tpn T1>il void readuint(T1&x){
		int ch;
		while((ch=getchar()^'0')>9);
		for(x=ch; (ch=getchar()^'0')<=9; x=x*10+ch);
	}
	tpl<tpn T1,tpn T2>il void readuint(T1&x,T2&y){
		readuint(x);
		readuint(y);
	}
	tpl<tpn T>void writeuint(cs T&x){
		if(x>9)
			writeuint(x/10);
		putchar((x%10)|'0');
	}
	tpl<tpn T>il void writelnuint(cs T&x){
		writeuint(x);
		putchar('\n');
	}
	#undef cs
	#undef il
	#undef tpl
	#undef tpn
}
#include <vector>
#include <cstring>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
using io::readuint;
using io::writelnuint;
typedef long long ll;
typedef cs int& ci;
#define max_n 1000000
int hsn[max_n+1],dp[max_n+1],*top=dp;
struct node{
	int v,nxt;
	il node(){}
	il node(ci _v,ci _nxt):v(_v),nxt(_nxt){}
};
struct graph{
	int head[max_n+1],cnt;
	node edge[max_n<<1|1];
	il void build(){
		memset(head,0,sizeof(head)),cnt=0;
	}
	il void insert(ci u,ci v){
		push(u,v);
		push(v,u);
	}
	il void push(ci u,ci v){
		edge[++cnt]=node(v,head[u]);
		head[u]=cnt;
	}
};
graph g;
int dfs(ci u,ci p){
	int hsu,hln=0,sln;
	for(int i=g.head[u],v; i; i=g.edge[i].nxt)
		if((v=g.edge[i].v)!=p)
			if((sln=dfs(v,u))>hln)
				hln=sln,hsu=v;
	if(hln){
		hsn[u]=hsu;
		return hln+1;
	}
	hsn[u]=0;
	return 1;
}
void dfs(ci u){//n>1
	int hsu,hln=0,sln;
	for(int i=g.head[u],v; i; i=g.edge[i].nxt)
		if((sln=dfs(v=g.edge[i].v,u))>hln)
			hln=sln,hsu=v;
	hsn[u]=hsu;
}
ll ans;
int k;
void solve(ci u,ci p){
	int*dpu=++top;
	*dpu=1;
	int hsu=hsn[u];
	if(hsu){
		solve(hsu,u);
		int*dpe=top,hln=top-dpu;
		if(hln>=k)
			ans+=dpu[k];
		for(int i=g.head[u],v; i; i=g.edge[i].nxt)
			if((v=g.edge[i].v)!=p&&v!=hsu){
				solve(v,u);
				int sln=top-dpe;
				if(hln<k){
					if(sln+hln>=k)
						for(int*j=dpe+sln,*jx=dpu+(k-sln); jx<=dpe; --j,++jx)
							ans+=ll(*jx)**j;
				}
				else
					if(sln<k)
						for(int*j=dpe+sln,*jx=dpu+(k-sln); j>dpe; --j,++jx)
							ans+=ll(*j)**jx;
					else
						for(int*j=dpe+k,*jx=dpu; j>dpe; --j,++jx)
							ans+=ll(*j)**jx;
				for(int j=sln; j; --j)
					dpu[j]+=dpe[j];
				top=dpe;
			}
	}
}
int main(){
	int n;
	readuint(n,k);
	if(n==1){
		puts("0");
		return 0;
	}
	g.build();
	for(int i=n,u,v; --i; g.insert(u,v))
		readuint(u,v);
	dfs(1);
	ans=0;
	solve(1,0);
	writelnuint(ans);
	return 0;
}