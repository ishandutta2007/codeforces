// By wasa855
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mkp make_pair
#define vi vector<int>
#define pii pair<int,int> 
#define FI(n) FastIO::read(n)
#define FO(n) FastIO::write(n)
#define ull unsigned long long
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i,k,j) for(int i=(k);i>=(j);i--)
#define For(i,k,j) for(int i=(k);i<=(j);i++)
#define Foe(i,u) for(int i=lst[u],v=e[i].v;i;i=e[i].nxt,v=e[i].v)
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define Fin(s) freopen(s,"r",stdin)
#define Fout(s) freopen(s,"w",stdout)
#define file(s) Fin(s".in"),Fout(s".out")
#define INF ((1<<30)-1)
const int P=998244353; //
using namespace std;
template<typename T>inline void ckmax(T &a,T b) {(a<b)&&(a=b);}
template<typename T>inline void ckmin(T &a,T b) {(a>b)&&(a=b);}
inline int mul(int a,int b) {return 1ll*a*b%P;}
inline int add(int a,int b) {return a+b>=P?a+b-P:a+b;}
inline int sub(int a,int b) {return a-b>=0?a-b:a-b+P;}
inline void mulmod(int &a,int b) {a=mul(a, b);}
inline void addmod(int &a,int b) {((a+=b)>=P)&&(a-=P);}
inline void submod(int &a,int b) {((a-=b)<0)&&(a+=P);}
inline int ksm(int a,int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
inline int inv(int a) {return ksm(a,P-2);}
namespace FastIO {
  const int SIZE=1<<16; char buf[SIZE],obuf[SIZE],str[64]; int bi=SIZE,bn=SIZE,opt;
  int read(char *s) {
    while (bn) {for (;bi<bn&&buf[bi]<=' ';bi++);if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}
    int sn=0;while (bn) {for (;bi<bn&&buf[bi]>' ';bi++) s[sn++]=buf[bi];if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}s[sn]=0;return sn;
  }
  bool read(int& x) {if(x)x=0;int bf=0,n=read(str); if(!n) return 0; int i=0; if (str[i]=='-') bf=1,i=1; for(x=0;i<n;i++) x=x*10+str[i]-'0'; if(bf) x=-x; return 1;}
  void write(int x) {
    if(!x) obuf[opt++]='0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
    if (opt>=(SIZE>>1)){fwrite(obuf,1,opt,stdout); opt=0;}
  }
  void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf,1,opt,stdout); opt=0;}}
	void Fflush() {if (opt) fwrite(obuf,1,opt,stdout); opt=0;}
};
inline int read() {int x; FI(x); return x;}
const int MN=250005;
int n,m;
vector<int>a[MN],ans;
void print(vector<int>x) {
	for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);
}
int Dif(const vector<int>&a,const vector<int>&b) {
	int ans=0;
	for(int i=0;i<m;i++) ans+=a[i]!=b[i];
	return ans; 
}
bool check(const vector<int>&std) {
	for(int i=1;i<=n;i++) {
		if(Dif(std,a[i])>2) return 0;
	}
	return 1;
}
bool chk2(vector<int>std,int pos) {
	std[pos]=-1;
	int ned=-1;
	for(int i=1;i<=n;i++) {
		int sum=0;
		for(int j=0;j<m;j++) if(std[j]!=a[i][j]) sum++;
		if(sum>=4) return 0;
		if(sum<=2) continue;
		int tp1=-1,tp2=-1,tp3=-1;
		for(int j=0;j<m;j++) {
			if(std[j]!=a[i][j]) {
				if(tp1==-1) tp1=j;
				else if(tp2==-1) tp2=j;
				else tp3=j;
			}
		}
		if(tp1==pos) {
			if(ned==-1) ned=a[i][pos];
			else if(a[i][pos]!=ned) return 0;
		}
		else if(tp2==pos) {
			if(ned==-1) ned=a[i][pos];
			else if(a[i][pos]!=ned) return 0;
		}
		else if(tp3==pos) {
			if(ned==-1) ned=a[i][pos];
			else if(a[i][pos]!=ned) return 0;
		}
		else return 0;
	}
	if(ned==-1) ned=1;
	std[pos]=ned,ans=std;
	return 1;
}
signed main() {
	#ifndef ONLINE_JUDGE 
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		a[i].resize(m);
		for(int j=0;j<m;j++) a[i][j]=read();
	}
	int maxn=0;
	for(int i=2;i<=n;i++) maxn=max(maxn,Dif(a[1],a[i]));
	if(maxn<=2) {
		printf("Yes\n");
		print(a[1]);
		return 0;
	}
	if(maxn>4) {
		printf("No\n");
		return 0;
	}
	for(int i=2;i<=n;i++) {
		int dif=Dif(a[1],a[i]);
		if(dif==4) {
			vector<int>pos;
			for(int j=0;j<m;j++) if(a[1][j]!=a[i][j]) pos.pb(j);
			vector<int>std=a[1];
			for(int j=0;j<4;j++) for(int k=j+1;k<4;k++) {
				vector<int>tmp=std;
				tmp[pos[j]]=a[i][pos[j]],tmp[pos[k]]=a[i][pos[k]];
				if(check(tmp)) {
					printf("Yes\n");
					print(tmp);
					return 0;
				}
			}
			printf("No\n");
			return 0;
		}
		if(dif==3) {
			vector<int>pos;
			for(int j=0;j<m;j++) if(a[1][j]!=a[i][j]) pos.pb(j);
			vector<int>std=a[1];
			for(int j=0;j<3;j++) for(int k=j+1;k<3;k++) {
				int u=pos[j],v=pos[k],w=pos[j^k^3];
				vector<int>tmp=std;
				tmp[u]=a[i][u];
				if(chk2(tmp,w)) {
					printf("Yes\n");
					print(ans);
					return 0;
				}
				tmp=std,tmp[v]=a[i][v];
				if(chk2(tmp,w)) {
					printf("Yes\n");
					print(ans);
					return 0;
				}
			}
			printf("No\n");
			return 0;
		}
	}
	return 0;
}