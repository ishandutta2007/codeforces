#pragma GCC optimize(3)
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
using namespace std;
using io::readuint;
using io::writelnuint;
typedef cs int& ci;
#define max_n 1000000
int ans[max_n+1];
int hsn[max_n+1],dp[max_n+1],*top=dp;
vector<int>sn[max_n+1];
typedef vector<int>::iterator vit;
int dfs(ci u,ci p){
	int hsu,hln=0,sln;
	for(vit i=sn[u].begin(),ed=sn[u].end(); i!=ed; ++i){
		if(*i!=p)
			if((sln=dfs(*i,u))>hln)
				hln=sln,hsu=*i;
	}
	if(hln){
		hsn[u]=hsu;
		return hln+1;
	}
	hsn[u]=0;
	return 1;
}
void dfs(ci u){//n>1
	int hsu,hln=0,sln;
	for(vit i=sn[u].begin(),ed=sn[u].end(); i!=ed; ++i)
		if((sln=dfs(*i,u))>hln)
			hln=sln,hsu=*i;
	hsn[u]=hsu;
}
void solve(ci u,ci p);
int solve_ret(ci u,ci p){
	int*dpu=++top;
	*dpu=1;
	int hsu=hsn[u];
	if(hsu){
		int asu=solve_ret(hsu,u);
		int*dpe=top,num=asu?dpu[++asu]:1;
		for(vit i=sn[u].begin(),ed=sn[u].end(); i!=ed; ++i)
			if(*i!=p&&*i!=hsu){
				solve(*i,u);
				for(int j=top-dpe; j; --j)
					(dpu[j]+=dpe[j])>=num&&(num=dpu[j],asu=j);
				top=dpe;
			}
		return ans[u]=asu;
	}
	return 0;
}
void solve(ci u,ci p){
	int*dpu=++top;
	*dpu=1;
	int hsu=hsn[u];
	if(hsu){
		int asu=solve_ret(hsu,u);
		int*dpe=top,num=asu?dpu[++asu]:1;
		for(vit i=sn[u].begin(),ed=sn[u].end(); i!=ed; ++i)
			if(*i!=p&&*i!=hsu){
				solve(*i,u);
				for(int j=top-dpe; j; --j)
					(dpu[j]+=dpe[j])>=num&&(num=dpu[j],asu=j);
				top=dpe;
			}
		ans[u]=asu;
	}
}
int main(){
	int n;
	readuint(n);
	if(n==1){
		puts("0");
		return 0;
	}
	for(int i=n,u,v; --i; sn[u].push_back(v),sn[v].push_back(u))
		readuint(u,v);
	dfs(1);
	memset(ans,0,sizeof(ans));//solve(u): ans[u]=0;
	solve(1,0);
	for(int*i=ans,*ed=ans+n; ++i<=ed; writelnuint(*i));
	return 0;
}