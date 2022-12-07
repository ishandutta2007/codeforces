#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second 
#define PB push_back
#define ll long long
using namespace std;

const int N=300005;
char s[5][N];
int s0[N],s1[N],n;

void work(int x,int y){
	char c0='1',c1='0';
	if (s0[x]<s1[x]||s0[y]<s1[y]) swap(c0,c1);
	int p0=1,p1=1;
	for (;p0<=2*n&&p1<=2*n;)
		if (s[x][p0]==c0||s[y][p1]==c0){
			putchar(c0);
			p0+=(s[x][p0]==c0);
			p1+=(s[y][p1]==c0);
		}
		else{
			putchar(c1);
			++p0;
			++p1;
		}
	for (;p0<=2*n;putchar(s[x][p0++])); 
	for (;p1<=2*n;putchar(s[y][p1++]));
	puts(""); 
}
void solve(){
	scanf("%d",&n);
	For(i,0,2){
		scanf("%s",s[i]+1);
		s0[i]=s1[i]=0;
		For(j,1,2*n) s[i][j]=='1'?++s1[i]:++s0[i];
	}
	if ((s0[0]<s1[0])==(s0[1]<s1[1])) work(0,1);
	else if ((s0[0]<s1[0])==(s0[2]<s1[2])) work(0,2);
	else if ((s0[1]<s1[1])==(s0[2]<s1[2])) work(1,2);
	else assert(0);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*

*/