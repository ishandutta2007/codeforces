#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#include<bits/stdc++.h>
#define ll long long
#define N 200005

char buf[1<<25],*p1=buf,*p2=buf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<25,stdin),p1==p2)?EOF:*p1++)
inline void rd(int &x){
	x=0;
	char c=getchar();
	while(c<'0'||c>'9')
		c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
char obuf[1<<25],*O=obuf;
#define putchar(c) (*O++=c)
inline void wr(ll x){
	if(x>9)
		wr(x/10);
	putchar(x%10+'0');
}

int n,q,a[N];

int l[N],r[N];
std::stack<int> st;
inline void init(){
	for(int i=1;i<=n;i++){
		while(st.size()&&a[st.top()]<a[i])
			r[st.top()]=i-1,st.pop();
		st.push(i);
	}
	while(st.size())
		r[st.top()]=n,st.pop();
	for(int i=n;i;i--){
		while(st.size()&&a[st.top()]<a[i])
			l[st.top()]=i+1,st.pop();
		st.push(i);
	}
	while(st.size())
		l[st.top()]=1,st.pop();
}

std::vector<std::pair<int,ll>> A[4][N];
std::vector<std::tuple<int,int,ll>> B[4][N];

ll t[N];
inline int lb(int x){
	return x&-x;
}
inline void add(int x,ll d){
	for(;x<=n;x+=lb(x))
		t[x]+=d;
}
inline ll sum(int x){
	ll res=0;
	for(;x;x-=lb(x))
		res+=t[x];
	return res;
}

ll ans[1000005];

inline void sol(int o){
	for(int i=1;i<=n;i++)
		t[i]=0;
	for(int i=1;i<=n;i++){
		for(auto [y,k]:A[o][i])
			add(y,k);
		for(auto [y,id,k]:B[o][i])
			ans[id]+=sum(y)*k;
	}
}

ll C[4]; 
inline void Add(int x,int y,ll K){
	C[0]=K;C[1]=K*y;C[2]=K*x;C[3]=1ll*K*x*y;
	for(int o=0;o<4;o++)
		A[o][x].emplace_back(y,C[o]);
}
inline void Sum(int x,int y,int id,ll K){
	B[0][x].emplace_back(y,id,1ll*K*(x+1)*(y+1));
	B[1][x].emplace_back(y,id,-K*(x+1));
	B[2][x].emplace_back(y,id,-K*(y+1));
	B[3][x].emplace_back(y,id,K);
}
inline void add(int x1,int y1,int x2,int y2,int K){
	Add(x1,y1,K);Add(x2+1,y2+1,K);
	Add(x1,y2+1,-K);Add(x2+1,y1,-K);
}
inline void sum(int x1,int y1,int x2,int y2,int id){
	Sum(x2,y2,id,1),Sum(x1-1,y2,id,-1),Sum(x2,y1-1,id,-1),Sum(x1-1,y1-1,id,1);
}

int pos[N];

std::vector<int> D[N];

int main(){
	rd(n),rd(q);
	for(int i=1;i<=n;i++)
		rd(a[i]),pos[a[i]]=i;
	init();
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j+=i)
			D[j].push_back(i);
	for(int i=1;i<=n;i++){
		std::vector<std::pair<int,int>> U,V;
		for(auto j:D[i]) if(pos[j]<pos[i/j]&&pos[j]>=l[pos[i]]&&pos[i/j]<=r[pos[i]])
			U.emplace_back(std::min(pos[i],pos[j]),std::max(pos[i],pos[i/j]));
		std::sort(U.begin(),U.end());
		for(auto [x,y]:U){
			while(V.size()&&y<=V.back().second)
				V.pop_back();
			V.emplace_back(x,y);
		}
		for(int o=0;o<(int)V.size();o++)
			add(o?V[o-1].first+1:l[pos[i]],V[o].second,V[o].first,r[pos[i]],1);
	}
	for(int i=1;i<=q;i++){
		int L,R;
		rd(L),rd(R);
		sum(L,L,R,R,i);
	}
	for(int o=0;o<4;o++)
		sol(o);
	for(int i=1;i<=q;i++)
		wr(ans[i]),putchar('\n');
	fwrite(obuf,O-obuf,1,stdout);
}