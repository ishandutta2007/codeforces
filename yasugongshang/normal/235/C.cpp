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
const int N=1000005,M=2000005;
char ch[N];
int n,last=1,tot=1,go[M][26],sz[M],pre[M],len[M],q[M];
void add(int c){
	int p=last,np=++tot; last=np; len[np]=len[p]+1;
	for(;p&&!go[p][c];p=pre[p])go[p][c]=np;
	if(!p)pre[np]=1; else{
		int q=go[p][c];
		if(len[q]==len[p]+1)pre[np]=q; else{
			int nq=++tot;
			memcpy(go[nq],go[q],sizeof(go[q]));
			pre[nq]=pre[q];
			pre[q]=pre[np]=nq;
			len[nq]=len[p]+1;
			while(go[p][c]==q){
				go[p][c]=nq; p=pre[p];
			}
		}
	}
}
inline bool cmp(int a,int b){
	return len[a]>len[b];
}
map<int,bool> vis;
int qt[N];
signed main(){
	scanf("%s",ch+1);
	n=strlen(ch+1);
	for(int i=1;i<=n;i++){add(ch[i]-'a'); sz[last]=1; }
	for(int i=1;i<=tot;i++)q[i]=i;
	sort(&q[1],&q[tot+1],cmp);
	for(int i=1;i<tot;i++)sz[pre[q[i]]]+=sz[q[i]];
	//for(int i=1;i<tot;i++){cout<<sz[q[i]]<<" "<<q[i]; puts("");}
	int q=read();
	while(q--){
		scanf("%s",ch+1);
		int Len=strlen(ch+1),dq=1,ans=0,tmp=0;
		for(int i=1;i<=Len;i++)ch[i]-='a';
		for(int i=Len+1;i<2*Len;i++)ch[i]=ch[i-Len];
		for(int i=1;i<Len;i++){
			while(dq&&!go[dq][ch[i]]){dq=pre[dq]; tmp=len[dq];}
			if(!dq)dq=1; else {dq=go[dq][ch[i]]; tmp++;}
		}
		int tt=0;
		for(int i=Len;i<2*Len;i++){
			while(dq&&!go[dq][ch[i]]){dq=pre[dq]; tmp=len[dq];}
			if(!dq)dq=1; else {
				dq=go[dq][ch[i]]; tmp++;
				while(Len<=len[pre[dq]])dq=pre[dq]; tmp=min(tmp,Len); 
				if(!vis[dq]&&tmp>=Len){ans+=sz[dq]; vis[dq]=1; qt[++tt]=dq;}
			}
			//cout<<i<<" "<<dq<<" "<<ans<<" "<<len[dq]<<" "<<(int)ch[i]<<endl;
		}
		while(tt)vis[qt[tt--]]=0;
		writeln(ans);
	}
}