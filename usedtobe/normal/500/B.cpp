#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define dep(i,a,b) for (int i=a;i>=b;--i)
#define For(i,u) for (int i=H[u];i;i=nxt[i])
#define fec(i,x) for (i=x.begin();i!=x.end();++i)
#define re(i,a) for (int i=0;i<a;++i)
#define clr(x) memset(x,0,sizeof x)
#define mp make_pair
#define N 333
#define pb push_back
using namespace std;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x);read(y);read(z);}
typedef long long ll;
typedef pair<int,int> pii;
//head
bool ok[N][N];
int n,pos[N];
char s[N];bool use[N];
int main() {
	scanf("%d",&n);int x;
	rep(i,1,n) read(x),pos[x]=i;
	rep(i,1,n){
		scanf("%s",s+1);
		rep(j,1,n)ok[i][j]=s[j]-'0';
		ok[i][i]=1;
	}
	rep(k,1,n)rep(i,1,n)rep(j,1,n)ok[i][j]|=ok[i][k]&ok[k][j];
	int j;rep(i,1,n){
		for(j=1;!ok[i][pos[j]]||use[j];++j);
		use[j]=1;
		printf("%d ",j);
	}
	puts("");
	return 0;
}