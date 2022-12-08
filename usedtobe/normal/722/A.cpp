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
char s[10];
int n,cnt;
int main() {
	read(n);
	scanf("%s",s+1);
	if(n==12){
		int aa=(s[1]-'0')*10+s[2]-'0';
		if (aa>12||aa==0){
			if(s[2]<='2'&&s[2]!='0'){
				if(s[1]>'1')s[1]='1',++cnt;
			}else if(s[2]=='0'){
				if(s[1]!='1')s[1]='1',++cnt;
			}else {
				if(s[1]!='0')s[1]='0',++cnt;
			}
		}
	}else if(n==24){
		int aa=(s[1]-'0')*10+s[2]-'0';
		if (aa>23){
			if(s[1]>'1')s[1]='1',++cnt;
		}
	}
	int aa=(s[4]-'0')*10+s[5]-'0';
	if(aa>59){
		if(s[4]>'1')s[4]='1',++cnt;
	}
	rep(i,1,5)printf("%c",s[i]);
	return 0;
}