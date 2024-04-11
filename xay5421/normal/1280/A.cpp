//by xay5421 2449670833@qq.com
#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;typedef unsigned long long ull;typedef pair<int,int>pii;typedef vector<int>VI;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)x=-x,putchar('-');if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}

const int N=1000005,P=1000000007;

int T,x,n,len;
char s[4000005];

void qaq(int now){
	int tmp=n;
	if(now>n)return;
	(len+=1ll*(s[now]-'0'-1)*(len-now+P)%P)%=P;
//	fprintf(stderr,">>> %d\n",len);
	for(int _=1;_<=s[now]-'0'-1;++_)
		for(int i=now+1;i<=tmp;++i)
			if(n<=x){
				s[++n]=s[i];
			}else return;
}

signed main(){
	rd(T);
	while(T--){
		rd(x);scanf("%s",s+1);n=strlen(s+1);
		len=n;
		for(int i=1;i<=x;++i){
			qaq(i);
		}
		for(int i=1;i<=n;++i)s[i]=0;
		pt(len,'\n');
	}
	return 0;
}