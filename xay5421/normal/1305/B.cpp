#include<set>
#include<map>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=1005;
int n,a[N],b[N],m;bool ban[N];char s[N];vector<int>ans[N];
signed main(){
	scanf("%s",s+1),n=strlen(s+1);
	for(int i=1;i<=n;++i)a[i]=a[i-1]+(s[i]==')');
	for(int i=n;i>=1;--i)b[i]=b[i+1]+(s[i]=='(');
	int T=0;
	while(1){
		++T;
		int i=1,j=n;
		bool flag=0;
		memset(ban,0,sizeof(ban));
		while(i<j){
			while(i<j&&s[i]==')')++i;
			while(j>i&&s[j]=='(')--j;
			if(i==j)break;
			ans[T].push_back(i);
			ans[T].push_back(j);
			ban[i]=1,ban[j]=1;
			++i,--j;
			flag=1;
		}
		m=0;
		for(int k=1;k<=m;++k)if(!ban[k])s[++m]=s[k];
		n=m;
		sort(ans[T].begin(),ans[T].end());
		if(flag==0){--T;break;}
	}
	pt(T,'\n');
	for(int i=1;i<=T;++i){
		pt(ans[i].size(),'\n');
		for(auto x:ans[i])pt(x,' ');puts("");
	}
	return 0;
}