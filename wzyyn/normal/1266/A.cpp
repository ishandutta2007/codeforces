#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
int T=-1;
char s[100005];
int main(){
	if (T==-1) scanf("%d",&T);
	scanf("%s",s+1);
	bool fl1=0,fl2=0;
	int n=strlen(s+1),S=0;
	For(i,1,n){
		S=(S+s[i]-'0')%3;
		if (s[i]=='0'&&!fl1) fl1=1;
		else if (s[i]%2==0) fl2=1;
	}
	puts(fl1&&fl2&&S==0?"red":"cyan");
	if (--T) main();
}