#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
template<typename T> void read(T &x){
	x=0;char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
}
const int MAXN=2e5;
int n;char s1[MAXN+5],s2[MAXN+5],s3[MAXN+5];
void print(char* s,char* t,char c){
	int cs=0,ct=0;
	for(int i=1;i<=n<<1;i++){
		if(s[i]==c) ++cs;
		if(t[i]==c) ++ct;
	}
	if(cs>ct){
		swap(cs,ct);
		for(int i=1;i<=n<<1;i++) swap(s[i],t[i]);
	} int j=1,cc=0;
	for(int i=1;i<=n<<1;i++){
		if(s[i]==c){
			while(j<=(n<<1)&&t[j]!=c) putchar(t[j]),j++,cc++;
			putchar(s[i]);cc++;if(j<=(n<<1)) j++;
		} else {
			putchar(s[i]);cc++;
		}
	} while(j<=(n<<1)) putchar(t[j]),j++,cc++;
	while(cc<3*n) cc++,putchar('0');printf("\n");
}
void solve(){
	scanf("%d%s%s%s",&n,s1+1,s2+1,s3+1);
	int c1=0,c2=0,c3=0;
	for(int i=1;i<=n<<1;i++) c1+=s1[i]-'0',c2+=s2[i]-'0',c3+=s3[i]-'0';
	if(c1<=n&&c2<=n) return print(s1,s2,'0'),void();
	if(c1<=n&&c3<=n) return print(s1,s3,'0'),void();
	if(c2<=n&&c3<=n) return print(s2,s3,'0'),void();
	if(c1>n&&c2>n) return print(s1,s2,'1'),void();
	if(c1>n&&c3>n) return print(s1,s3,'1'),void();
	if(c2>n&&c3>n) return print(s2,s3,'1'),void();
}
int main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve();
	return 0;
}