#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define dep(i,a,b) for (int i=a;i>=b;--i)
#define re(i,a,b) for (int i=a;i<b;++i)
#define mp make_pair
#define pb push_back
using namespace std;
template<class T> inline void read(T&x){char c;bool fu=0;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x*=-1;}
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z) {read(x,y);read(z);}
typedef long long ll;
typedef pair<int,int> pii;
const int N=111111;
char s[N];
int p[N],n;
bool ok(int k){
	return s[k]=='a'||s[k]=='e'||s[k]=='i'||s[k]=='o'||s[k]=='u'||s[k]=='y';
}
int main() {
	read(n);
	rep(i,1,n)read(p[i]);
	bool flag=1;
	rep(i,1,n){
		gets(s+1);int len=strlen(s+1);s[++len]=' ';
		int pre=1,tot=0;
		rep(j,1,len)if(s[j]==' '){
			rep(k,pre,j-1)if(ok(k))++tot;
			pre=j+1;
		}
		if(tot!=p[i]){
			flag=0;
			break;
		}
	}
	if(flag)puts("YES");
	else puts("NO");
	return 0;
}