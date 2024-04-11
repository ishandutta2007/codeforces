//by xay5421 2449670833@qq.com
#include<set>
#include<map>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cassert>
#include<algorithm>
//#define int long long
#define debug(...) fprintf(stderr,__VA_ARGS__)
//#define debug(...) ((void)0)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;typedef unsigned long long ull;typedef std::pair<int,int> pii;
template<typename T>void rd(T&x){int f=0,c;while((c=getchar())<48||57<c)f^=!(c^45);x=(c&15);while(47<(c=getchar())&&c<58)x=x*10+(c&15);if(f)x=-x;}
template<typename T>inline void pt(T x){if(x<0)x=-x,putchar('-');if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int c){pt(x),putchar(c);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}
const int N=1005;
int n,m,a[N];char s[N][N];
signed main(){
	rd(n);
	std::vector<std::vector<int> >v[2];
	rep(i,1,n)rd(a[i]),m=max(m,a[i]+1);
	std::vector<int>t(m);
	rep(i,1,m)t[i-1]=i;
	v[0].push_back(t);
	pt(m,'\n');
	rep(i,1,n){
		v[i&1].clear();
		int tot=a[i];
		std::vector<int>qaq;
		for(int j=0;j<(int)v[(i-1)&1].size();++j){
			std::vector<int>L,R;
			int nowsz=v[(i-1)&1][j].size();
			if(nowsz&1)qaq.push_back(j);
			for(int k=0;k<nowsz/2;++k){
				if(tot>0){
					int id=v[(i-1)&1][j].back();
					s[id][i]='1';
					L.push_back(id);
					v[(i-1)&1][j].pop_back();
					--tot;
				}
			}
			v[i&1].push_back(L),v[i&1].push_back(R);
		}
		for(auto j:qaq){
			if(tot>0){
				int id=v[(i-1)&1][j].back();
				s[id][i]='1';
				v[i&1][j*2].push_back(id);
				v[(i-1)&1][j].pop_back();
				--tot;
			}
		}
		for(int j=0;j<(int)v[(i-1)&1].size();++j){
			int nowsz=v[(i-1)&1][j].size();
			for(int k=0;k<nowsz;++k){
				if(tot>0){
					int id=v[(i-1)&1][j].back();
					s[id][i]='1';
					v[i&1][j*2].push_back(id);
					v[(i-1)&1][j].pop_back();
					--tot;
				}
				else{
					int id=v[(i-1)&1][j].back();
					s[id][i]='0';
					v[i&1][j*2+1].push_back(id);
					v[(i-1)&1][j].pop_back();
				}
			}
		}
		std::vector<std::vector<int> >tmp(v[i&1]);
		v[i&1].clear();
		for(int j=0;j<(int)tmp.size();++j)if(tmp[j].size()){
//			puts("push");
			v[i&1].push_back(tmp[j]);
		}
	}
	rep(i,1,m)puts(s[i]+1);
	return 0;
}