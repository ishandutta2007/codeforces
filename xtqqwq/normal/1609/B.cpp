// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,q;
char s[100005];

int check(int i){
	if(i+2>n) return 0;
	return s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c';
}

int main(){
	n=readint(); q=readint();
	scanf("%s",s+1);
	int cnt=0;
	for(int i=1;i<=n-2;i++) cnt+=check(i);
	while(q--){
		int i; char ch;
		i=readint(); ch=getchar();
		while(ch!='a'&&ch!='b'&&ch!='c') ch=getchar();
		cnt-=check(i);
		if(i-1>=1) cnt-=check(i-1);
		if(i-2>=1) cnt-=check(i-2);
		s[i]=ch;
		cnt+=check(i);
		if(i-1>=1) cnt+=check(i-1);
		if(i-2>=1) cnt+=check(i-2);
		printf("%d\n",cnt);
	}
	return 0;
}