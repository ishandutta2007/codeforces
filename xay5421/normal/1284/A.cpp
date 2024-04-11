#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=25;
int n,m,q;string s[N],t[N];
signed main(){
	rd(n),rd(m);
	for(int i=1;i<=n;++i)cin>>s[i];
	for(int i=1;i<=m;++i)cin>>t[i];
	rd(q);
	while(q--){
		int k1;rd(k1);
		int k2=(k1-1)%n+1,k3=(k1-1)%m+1;
		cout<<s[k2]<<t[k3]<<endl;
	}
	return 0;
}