#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<int>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
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
const int inf=1e9;
const int N=55,M=5005;
int nedge=1,son[N],nextt[M],ed[M];
int cost[M],dist[N],di[M];
bool vis[N];
int last[N],que[N],laedge[N];
bool spfa(int s,int t,int n){
    for (int i=1;i<=n;i++) {dist[i]=inf;last[i]=laedge[i]=vis[i]=que[i-1]=0;}
    int tot=1,l=0,r=0; que[0]=s; vis[s]=true; dist[s]=0;
    while (tot) {
        int k=que[l];
        vis[k]=false;
        if (++l==n) l=0;
        tot--; 
        for(int i=son[k];i;i=nextt[i]){
            if(di[i]>0&&dist[ed[i]]>dist[k]+cost[i]){
                dist[ed[i]]=dist[k]+cost[i]; laedge[ed[i]]=i; last[ed[i]]=k;
                if(vis[ed[i]]==0) {
                    if(++r==n)r=0;
                    que[r]=ed[i]; tot++; vis[ed[i]]=true;
                }
            }
        }
    }
    return last[t]>0;
}
int flo,len[M],s[M],S[M];
void costflow(int s,int t,int n){
	int sum=0;
    while(spfa(s,t,n)){
        int mmin=inf; 
        for(int i=t;last[i];i=last[i]){mmin=min(mmin,di[laedge[i]]);}
        len[flo]=dist[t]-sum; //cout<<dist[t]<<endl; exit(0);
        sum+=len[flo];
        flo++;
        for(int i=t;last[i];i=last[i]){
            di[laedge[i]]-=mmin;
            di[laedge[i]^1]+=mmin;
        }
    }
}
inline void aedge(int a,int b,int c,int d){
    nextt[++nedge]=son[a]; son[a]=nedge; ed[nedge]=b; di[nedge]=c; cost[nedge]=d;
}
inline void ins(int a,int b,int c,int d){
    aedge(a,b,c,d); aedge(b,a,0,-d);
}
int main(){
	int n=read(),m=read();
	For(i,1,m){
		int u=read(),v=read(),w=read();;
		ins(u,v,1,w);
	}
	costflow(1,n,n);
	S[0]=len[0]; 
	For(i,1,flo-1){
		s[i]=s[i-1]+i*len[i];
		S[i]=S[i-1]+len[i];
	}
	int q=read();
	while(q--){
		int x=read();
		int t=upper_bound(s,s+flo,x)-s;
		
		printf("%.10f\n",S[t-1]+(double)(x-s[t-1])/(t));
	}
}