#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=50005,M=N*11*2,K=26;
int sz[M][10],rig[M],q[M],len[M],pre[M],last=1,tot=1;
int n,l[15],r[15],go[M][K];
bool vl[M],vr[M];
char ch[N],s[N];
void add(int c){
	int np=++tot,p=last; 
	len[np]=len[p]+1; last=np;
	for(;p&&!go[p][c];p=pre[p])go[p][c]=np;
	if(!p)pre[np]=1; else{
		int q=go[p][c];
		if(len[p]+1==len[q])pre[np]=q; else{
			int nq=++tot; memcpy(go[nq],go[q],sizeof(go[q]));//go[nq]=go[q];
			len[nq]=len[p]+1;
			pre[nq]=pre[q];
			pre[np]=pre[q]=nq;
			while(go[p][c]==q){
                go[p][c]=nq;
                p=pre[p];
            }
		}
	}
}
inline bool cmp(int a,int b){
	return len[a]>len[b]||(len[a]==len[b]&&a>b);
}
inline int zl(int l,int r,int x){
	if(r-l+1<len[pre[x]]+1)return pre[x]; else return x;
}
inline int zr(int l,int r,int x){
	return go[x][s[r]-'a'];
}
ll ans;
vector<int> v[M];
void dfs(int p){
	for(unsigned i=0;i<v[p].size();i++){dfs(v[p][i]); rig[p]=max(rig[p],rig[v[p][i]]); for(int j=0;j<n;j++)sz[p][j]+=sz[v[p][i]][j];}
}
signed main(){
	scanf("%s",s);
	n=read(); 
	int Len=strlen(s);
	memset(rig,-1,sizeof(rig));
	for(int i=0;i<Len;i++){add(s[i]-'a'); rig[last]=i;}
	for(int i=0;i<n;i++){
		scanf("%s",ch); l[i]=read(); r[i]=read();
		int len=strlen(ch);
		last=1; for(int j=0;j<len;j++){add(ch[j]-'a'); sz[last][i]++; }
	}
	for(int i=2;i<=tot;i++)v[pre[i]].push_back(i);
	dfs(1);
	//cout<<sz[4][1]<<" "<<q[tot]<<endl;
	for(int i=0;i<=tot;i++){
		for(int j=0;j<n;j++){
			if(sz[i][j]>r[j])vl[i]=1;
			if(sz[i][j]<l[j])vr[i]=1;
		}
	}
	int dql=go[1][s[0]-'a'],dqr=dql,dq=dql,dd=0,l=0,r=0;
	for(int i=0;i<Len;i++){
		while(l<i)dql=zr(i,++l,dql);
		dql=zl(i,l,dql);
		while(vl[dql]&&l<Len)dql=zr(i,++l,dql);
		while(r<i)dqr=zr(i,++r,dqr);
		dqr=zl(i,r,dqr);
		while(!vr[zr(i,r+1,dqr)]&&r+1<Len)dqr=zr(i,++r,dqr);
		while(dd<i)dq=zr(i,++dd,dq);
		dq=zl(i,dd,dq);
		while(rig[dq]>dd&&dd<Len)dq=zr(i,++dd,dq);
		if(l<Len&&!vr[dqr]&&dd<Len&&dd<=r)ans+=r-max(l,dd)+1;
		//cout<<l<<" "<<r<<" "<<dql<<" "<<dqr<<" "<<sz[dqr][1]<<" "<<dq<<" "<<rig[dq]<<endl;
	}
	cout<<ans<<endl;
}
/*
dddd
3
dddddd 2 5
ddddd 2 5
ddddddd 2 5

dddddd
ddddd

6 11
4 9
6 11
*/