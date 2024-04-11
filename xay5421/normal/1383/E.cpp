#include<bits/stdc++.h>
#define D(...) ((void)0)
//#define D(...) fprintf(stderr,__VA_ARGS__)
#define int long long
#define LL long long
#define MP make_pair
#define PB push_back
#define fi first
#define se second
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef pair<int,int>PII;typedef vector<int>VI;typedef vector<PII>VII;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=1000005,P=1e9+7;
int n,lst[2],go[N][2],f[N],le[N],nxt[N],len[N],st[N],top;char s[N];
void init(){
	lst[0]=lst[1]=n+1;
	go[n+1][0]=lst[0],go[n+1][1]=lst[1];
	for(int i=n;i>=1;--i){
		go[i][0]=lst[0],go[i][1]=lst[1];
		lst[s[i]&1]=i;
	}
	go[0][0]=lst[0],go[0][1]=lst[1];
}
signed main(){
	scanf("%s",s+1),n=strlen(s+1);
	rep(i,1,n+1)nxt[i]=n+1;
	init();
	for(int i=1,j;i<=n;i=j){
		j=i;
		while(j<=n&&s[j]==s[i])le[j]=i,++j;
		len[i]=j-i;
		if(s[i]=='0'){
			while(top&&len[i]>len[st[top]])nxt[st[top]]=i,--top;
			st[++top]=i;
		}
	}
	if(go[0][1]==n+1){printf("%lld\n",n);return 0;}
	if(s[1]=='1'){
		f[1]=1;
	}else{
		nxt[1]=n+1;
		f[1]=1;
		f[go[0][1]]=1;
	}
	rep(i,1,n)D("nxt[%lld]=%lld\n",i,nxt[i]);
	rep(i,1,n){
		if(s[i]=='1'||s[i+1]=='0'){
			D("/// %lld %lld\n",i,go[i][0]);
			(f[go[i][0]]+=f[i])%=P;
		}
		else{
			int t=nxt[le[i]];
			int to=t+i-le[i]+1;
			if(t!=n+1){
				D(">>> %lld %lld\n",i,to);
				(f[to]+=f[i])%=P;
			}
		}
//		if(s[i]=='0'||s[i+1]=='1'){
			(f[go[i][1]]+=f[i])%=P;
//		}
		D("??? %lld %lld %lld\n",i,go[i][1],f[go[i][1]]);
	}
	rep(i,1,n)D("f[%lld]=%lld\n",i,f[i]);
	int ans=0;
	int tot=0;
	for(int i=n;i>=1;--i){
		if(s[i]=='1')break;
//		D("ans+=f[%lld]\n",i);
		++tot;
//		(ans+=f[i])%=P;
	}
	rep(i,1,n)if(s[i]=='1')D("ans+=f[%lld]\n",i),(ans+=f[i])%=P;
	pt(1LL*ans*(tot+1)%P,'\n');
	return 0;
}