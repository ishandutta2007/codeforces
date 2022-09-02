//by xay5421 2449670833@qq.com
#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;typedef unsigned long long ull;typedef pair<int,int>pii;typedef vector<int>VI;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)x=-x,putchar('-');if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=300005;
int T,ans[N];char s[N];
signed main(){
	rd(T);
	while(T--){
		scanf("%s",s+1);int n=strlen(s+1);
		ans[0]=0;
		for(int i=1;i<=n;++i){
			if(s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o'&&s[i+3]=='n'&&s[i+4]=='e'){
				s[i+2]=0;
				ans[++ans[0]]=i+2;
			}
			else if(s[i]=='o'&&s[i+1]=='n'&&s[i+2]=='e'){
				s[i+1]=0;
				ans[++ans[0]]=i+1;
			}
			else if(s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o'){
				s[i+1]=0;
				ans[++ans[0]]=i+1;
			}
		}
		pt(ans[0],'\n');
		for(int i=1;i<=ans[0];++i)pt(ans[i],' ');
		puts("");
	}
	return 0;
}