#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=3505,K=15;
int T,n,m,k,len,a[N];multiset<int>S;
signed main(){
	rd(T);
	while(T--){
		S.clear();
		rd(n),rd(m),rd(k),len=m-k-1;
		for(int i=1;i<=n;++i)rd(a[i]);
		int ans=0;
		if(len>0){
			for(int i=0;i<=k;++i){
				int l=i+1,r=n-(k-i);
				if(i==0){
					for(int j=0;j<len;++j){
						S.insert(max(a[l+j],a[r-len+j]));
					}
				}
				S.insert(max(a[l+len],a[r]));
				if(!S.empty())ans=max(ans,*S.begin());
				S.erase(S.find(max(a[l],a[r-len])));
			}
		}else{
			for(int i=1;i<=m;++i)ans=max(ans,a[i]);
			for(int i=n-m+1;i<=n;++i)ans=max(ans,a[i]);
		}
		pt(ans,'\n');
	}
	return 0;
}