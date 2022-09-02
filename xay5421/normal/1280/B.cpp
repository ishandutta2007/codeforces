//by xay5421 2449670833@qq.com
#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;typedef unsigned long long ull;typedef pair<int,int>pii;typedef vector<int>VI;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)x=-x,putchar('-');if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}

const int N=70;

int T,n,m,a[N][N];char s[N][N];

int get(int k1,int k2,int k3,int k4){
	return a[k3][k4]-a[k1-1][k4]-a[k3][k2-1]+a[k1-1][k2-1];
}

bool bad(){
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)if(s[i][j]=='A')return 0;
	return 1;
}

bool ok0(){
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)if(s[i][j]=='P')return 0;
	return 1;
}

bool ok1(){
	bool flag=1;
	for(int i=1;i<=n;++i)if(s[i][1]=='P'){flag=0;break;}
	if(flag)return 1;
	flag=1;
	for(int i=1;i<=n;++i)if(s[i][m]=='P'){flag=0;break;}
	if(flag)return 1;
	flag=1;
	for(int i=1;i<=m;++i)if(s[1][i]=='P'){flag=0;break;}
	if(flag)return 1;
	flag=1;
	for(int i=1;i<=m;++i)if(s[n][i]=='P'){flag=0;break;}
	if(flag)return 1;
	return 0;
}

bool ok2(){
	if(s[1][1]=='A')return 1;
	if(s[1][m]=='A')return 1;
	if(s[n][1]=='A')return 1;
	if(s[n][m]=='A')return 1;
	for(int i=1;i<=n;++i)if(get(i,1,i,m)==m)return 1;
	for(int i=1;i<=m;++i)if(get(1,i,n,i)==n)return 1;
	return 0;
}

bool ok3(){
	for(int i=1;i<=n;++i)if(s[i][1]=='A')return 1;
	for(int i=1;i<=n;++i)if(s[i][m]=='A')return 1;
	for(int i=1;i<=m;++i)if(s[1][i]=='A')return 1;
	for(int i=1;i<=m;++i)if(s[n][i]=='A')return 1;
	return 0;
}

signed main(){
	rd(T);
	while(T--){
		rd(n),rd(m);
		for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
		for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)a[i][j]=(s[i][j]=='A'),a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1]; 
		if(bad()){puts("MORTAL");continue;}
		else if(ok0()){puts("0");continue;}
		else if(ok1()){puts("1");continue;}
		else if(ok2()){puts("2");continue;}
		else if(ok3()){puts("3");continue;}
		else puts("4");continue;
	}
	return 0;
}