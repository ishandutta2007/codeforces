// luogu-judger-enable-o2
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long LL;
#define sqr(x) ((x)*(x))
#define mp make_pair
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
    int x=0; char ch=gc(); bool positive=1;
    for (;!isdigit(ch);ch=gc())if(ch=='-')positive=0;
    for (;isdigit(ch);ch=gc())x=x*10+ch-'0';
    return positive?x:-x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
        a=-a; putchar('-');
    }
    write(a); puts("");
}
const int M=100005,N=100005,oo=1000000005;
int nextt[M],ed[M],di[M],son[M],nedge,n,m,deep[N],cur[N],que[N];
inline void aedge(int a,int b,int c){
    nextt[++nedge]=son[a]; son[a]=nedge; ed[nedge]=b; di[nedge]=c;
}
inline void insert(int a,int b,int c){
	//cout<<a<<" "<<b<<" "<<c<<endl;
    aedge(a,b,c); aedge(b,a,0);
}
int tot;
bool bfs(int s,int t){
    for(int i=1;i<=tot;i++){deep[i]=oo; cur[i]=son[i];} que[0]=s; deep[s]=0;
    int l=0,r=0;
    while(l<=r){
        int k=que[l++]; //cout<<k<<" "<<deep[k]<<" "<<l<<" "<<r<<endl;
        for(int i=son[k];i;i=nextt[i])if(di[i]&&deep[ed[i]]==oo){
            deep[ed[i]]=deep[k]+1; que[++r]=ed[i];
        }
    }
    return deep[t]<oo;
}
inline int dfs(int now,int t,int limit){
    if(now==t||!limit)return limit;
    int flow=0,f;
    for(int i=cur[now];i;i=nextt[i]){
        cur[now]=i;
        if(deep[ed[i]]==deep[now]+1&&(f=dfs(ed[i],t,min(limit,di[i])))){
            di[i]-=f; di[((i-1)^1)+1]+=f; flow+=f; limit-=f; if(!limit)break;
        }
    }
    return flow;
}
int dinic(int s,int t){
    int ans=0;
    while(bfs(s,t))ans+=dfs(s,t,oo);
    return ans;
}
const int inf=100005;
int tong[6],cs[1<<6],dq,tt[1<<6],sum[1<<6];
bool check(){
	int s=1,t=2;
	tot=2+(1<<6); nedge=0;
	for(int i=1;i<=tot;i++)son[i]=0;
	for(int i=0;i<6;i++)insert(s,(1<<i)+2,tong[i]);
	for(int i=0;i<(1<<6);i++)sum[i]=cs[i];
	for(int i=0;i<6;i++){
		for(int j=0;j<(1<<6);j++)if(j>>i&1)sum[j]+=sum[j^(1<<i)];
	}
	for(int i=1;i<(1<<6);i++){
		tt[i]=0;
		for(int j=0;j<6;j++)if(i>>j&1)tt[i]+=tong[j];
	}
	//for(int i=0;i<(1<<6);i++)if(sum[i]<tt[i])cout<<sum[i]<<" "<<tt[i]<<" "<<i<<endl;
	for(int i=0;i<(1<<6);i++)if(sum[i]>tt[i])return 0;return 1;
}
char ch[N],ans[N];
int ycl[N];
int main(){
    scanf("%s",ch+1);
    n=strlen(ch+1);
    for(int i=1;i<=n;i++){
    	tong[ch[i]-'a']++; ycl[i]=(1<<6)-1;
	}
    m=read();
	while(m--){
		int pos=read(),s=0; scanf("%s",ch);
		int len=strlen(ch);
		for(int i=0;i<len;i++)s|=1<<(ch[i]-'a');
		ycl[pos]=s;
	}
	for(int i=1;i<=n;i++)cs[ycl[i]]++;
	dq=n;
	if(!check()){
		puts("Impossible");return 0; 
	}
	for(int i=1;i<=n;i++){
		cs[ycl[i]]--; dq--; 
		for(int j=0;j<6;j++)if((ycl[i]>>j&1)&&tong[j]){
			tong[j]--; 
			if(check()){ans[i]=j+'a'; break;}
			tong[j]++;
		}
	}
	cout<<(ans+1)<<endl;
}