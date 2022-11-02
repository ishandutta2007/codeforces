#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define ld long double
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
const int N=1005;
int n,n1,n2,q[N],x[N],y[N],vis[N],match[N],Match[N],e[N][N];
PI s1[N],s2[N];
vector<PI> ans1,ans2;
map<int,set<PI> > M1,M2;
set<PI> S1,S2;
inline bool in(int a,int b,int c){
	//cout<<a<<" "<<b<<" "<<c<<endl;
	return a>b&&a<c;
}
bool dfs(int p){
	for(int i=1;i<=n2;i++)if(e[p][i]&&!vis[i]){
		vis[i]=1;
		if(!match[i]||dfs(match[i])){
			match[i]=p; return 1;
		}
	}
	return 0;
}
void print(vector<PI> ans){
	writeln(ans.size());
	for(auto i:ans){
		wri(x[i.first]); wri(y[i.first]); wri(x[i.second]); writeln(y[i.second]);
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		x[i]=read(); y[i]=read();
		M1[x[i]].insert(mp(y[i],i));
		M2[y[i]].insert(mp(x[i],i));
	}
	for(auto i:M1){
		int tot=0;
		for(auto j:i.second){
			q[++tot]=j.second;
		}
		for(int j=1;j<tot;j++)s1[++n1]=mp(q[j],q[j+1]);
	}
	for(auto i:M2){
		int tot=0;
		for(auto j:i.second){
			q[++tot]=j.second;
		}
		for(int j=1;j<tot;j++)s2[++n2]=mp(q[j],q[j+1]);
	}
	for(int i=1;i<=n1;i++){
		for(int j=1;j<=n2;j++)e[i][j]=in(y[s2[j].first],y[s1[i].first],y[s1[i].second])&&in(x[s1[i].first],x[s2[j].first],x[s2[j].second]);
	}
	int ans=0;
	for(int i=1;i<=n1;i++){
		if(dfs(i))ans++;
		memset(vis,0,sizeof(vis));
	}
	//cout<<ans<<endl;
	//for(int i=1;i<=n1;i++)for(int j=1;j<=n2;j++)cout<<e[i][j]<<endl;
	for(int i=1;i<=n2;i++)if(match[i])Match[match[i]]=i;
	while(1){
		int flag=1;
		for(int i=1;i<=n1;i++)if(!Match[i]){
			S1.insert(s1[i]); flag=0; Match[i]=-1;
			for(int j=1;j<=n2;j++)if(e[i][j]){Match[match[j]]=0; match[j]=-1;}
		}
		for(int i=1;i<=n2;i++)if(!match[i]){
			S2.insert(s2[i]); flag=0; match[i]=-1;
			for(int j=1;j<=n1;j++)if(e[j][i]){match[Match[j]]=0; Match[j]=-1;}
		}
		if(flag)break;
	}
	for(int i=1;i<=n1;i++)if(Match[i]>0)S1.insert(s1[i]);
//	for(auto i:S1)cout<<i.first<<" wzp "<<i.second<<endl; for(auto i:S2)cout<<i.first<<" "<<i.second<<endl;
	for(auto i:M1){
		int tot=0;
		for(auto j:i.second){
			q[++tot]=j.second;
		}
		int dq=1;
		for(int j=1;j<tot;j++)if(!S1.count(mp(q[j],q[j+1]))){
			ans1.push_back(mp(q[dq],q[j])); dq=j+1;
		}
		ans1.push_back(mp(q[dq],q[tot]));
	}
	for(auto i:M2){
		int tot=0;
		for(auto j:i.second){
			q[++tot]=j.second;
		}
		int dq=1;
		for(int j=1;j<tot;j++)if(!S2.count(mp(q[j],q[j+1]))){
			ans2.push_back(mp(q[dq],q[j])); dq=j+1;
		}
		ans2.push_back(mp(q[dq],q[tot]));
	}
	print(ans2);
	print(ans1);
}
/*
6
1 1
4 1
2 0
3 0
2 2
3 2

6
1 1
1 4
0 2
0 3
2 2
2 3

*/