#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=200005;
int n,q,num[26],sum[N][26];char s[N];
signed main(){
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<=n;++i){
		memcpy(sum[i],sum[i-1],sizeof(sum[i]));
		++sum[i][s[i]-'a'];
	}
	rd(q);
	while(q--){
		int l,r;rd(l),rd(r);
		if(l==r)puts("Yes");
		else{
			int tot=0;
			for(int i=0;i<=25;++i)if(sum[r][i]-sum[l-1][i])++tot;
			if(tot>2)puts("Yes");
			else{
				if(s[l]==s[r])puts("No");
				else puts("Yes");
			}
		}
	}
	return 0;
}