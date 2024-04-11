// author: xay5421
// created: Sun May  2 22:57:45 2021
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=200005;
int _T,n,nl,nr;
multiset<int>S,T;
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(_T);
	while(_T--){
		rd(n),rd(nl),rd(nr);
		S.clear();
		rep(i,1,nl){
			int x;
			rd(x);
			S.insert(x);
		}
		T.clear();
		rep(i,1,nr){
			int x;
			rd(x);
			if(S.find(x)!=S.end()){
				S.erase(S.find(x));
			}else T.insert(x);
		}
		if(SZ(S)<SZ(T))swap(S,T);
		int k=(SZ(S)-SZ(T))>>1;
		int lst=-1,ans=SZ(T),same=0;
		for(auto it=S.begin();it!=S.end();++it){
			if(*it==lst)++same,lst=-1;
			else lst=*it;
		}
		ans+=k+k-min(same,k);
		printf("%d\n",ans);
	}
	return 0;
}