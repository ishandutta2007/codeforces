#include<bits/stdc++.h>
#define rep(i,a,n) for(int _tmp=n,i=a;i<=_tmp;++i)
#define dep(i,a,n) for(int _tmp=n,i=a;i>=_tmp;--i)
#define fec(i,a) for(__typeof a.begin() i=a.begin();i!=a.end();++i)
#define For(i,u) for(int i=H[u];i;i=nxt[i])
#define re(i,a,b) for (int i=a;i<b;++i)
#define si(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
using namespace std;
template<class T> inline void read(T&x){char c;bool fu=0;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x*=-1;}
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z) {read(x,y);read(z);}
typedef long long ll;
typedef pair<int,int> pii;
const int N=211111;
char a[N];
int pos;int st;
void work(int x){
	st=x;
	if(x!=pos){
		a[x]+=1;
		if(a[x]=='9'+1)a[x]='0',work(x-1);
	}else work(x-1);
}
int n,t;
int main(){
	read(n,t);a[0]='0';
	scanf("%s",a+1);
	rep(i,1,n)if(a[i]=='.'){
		pos=i;
		break;
	}
	st=pos+1;
	rep(_,1,t){
		bool f=0;
		rep(i,max(st,pos+1),n){
			if(a[i]>='5'){
				n=i-1;
				work(i-1);f=1;
				break;
			}
		}
		if(!f)break;
	}
	int pre;
	if(a[0]!='0')pre=0;else pre=1;
	if(n==pos)n--;
	rep(i,pre,n)printf("%c",a[i]);
	return 0;
}