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
int get(char *c){
	int n=strlen(c);
	if(c[0]=='m')return 1;
	else if(c[0]=='t'){
		if(c[1]=='u')return 2;
		else return 4;
	}
	else if(c[0]=='w')return 3;
	else if(c[0]=='f')return 5;
	else if(c[0]=='s'){
		if(c[1]=='a')return 6;
		else return 7;
	}
}
char a[10],b[10];
int main() {
	scanf("%s%s",a,b);
	int x=get(a),y=get(b);
	int ans=(y-x+7)%7;
	if(ans==2||ans==3||ans==0)puts("YES");
	else puts("NO");
	return 0;
}