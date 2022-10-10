#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

class MCMF {
public:   
	typedef long long VAL;
	static const int SIZE=1005;
	static const VAL INF=OVER9000;
	typedef struct ARC{
		int t,c;
		VAL w;
		ARC *o;
	} *PTR;
	ARC arc[200005];
	PTR now[SIZE],e[SIZE];
	int cnt[SIZE],l[SIZE],r[SIZE],edge;
	VAL sum;
	void clear(){
		memset(e,edge=sum=0,sizeof(e));
	}
	MCMF() {clear();}
	ARC &REV(PTR x){
		return arc[(x-arc)^1];
	}
	int flow(int S,int T){
		return spfa_johnson(S,T,INF);
	} 
	PTR add_edge(int x,int y,int c,VAL w=0){
		e[x]=&(arc[edge++]=(ARC){
			y,c,+w,e[x]
		});
		e[y]=&(arc[edge++]=(ARC){
			x,0,-w,e[y]
		});
		return e[x];
	}
	int aug(int S,int T,int &can){
		int x,z=T,use=can;
		for(x=S;x!=T;x=now[x]->t) if(use>now[x]->c) use=now[z=x]->c;
		for(x=S;x!=T;x=now[x]->t){
			now[x]->c-=use;
			REV(now[x]).c+=use;
			sum+=use*now[x]->w;
		}
		can-=use;
		return z;
	}
	int spfa_johnson(int S,int T,int can){
		if(S==T) return can;
		int in=can,x,m;
		VAL phi[SIZE],len[SIZE],MAXW=OVER9000;
		memset(l,0,sizeof(l));
		fill_n(phi,SIZE,MAXW);
		phi[r[0]=T]=0;
		for(int i=m=0;i<=m;i++)
		{
			l[x=r[i%SIZE]]=0;
			for(PTR u=e[x];u;u=u->o){
				if(phi[x]+REV(u).w>=phi[u->t]||!REV(u).c) continue;
				phi[u->t]=phi[x]+REV(u).w;
				if(!l[u->t]) l[r[++m%SIZE]=u->t]=1;
			}
		}
		do{
			typedef pair<VAL,int> TPL;
			priority_queue<TPL> q;
			fill_n(len,SIZE,MAXW);
			memset(l,0,sizeof(l));
			q.push(TPL(len[T]=0,T));
			while(q.size()){
				x=q.top().second;
				q.pop();
				if(!l[x]) l[x]=1;
				else continue;
				for(PTR u=e[x];u;u=u->o){
					if(!REV(u).c||l[u->t]) continue;
					VAL at=len[x]+phi[x]+REV(u).w-phi[u->t];
					if(at>=len[u->t]) continue;
					len[u->t]=at;
					now[u->t]=&REV(u);
					q.push(TPL(-at,u->t));
				} 
			}
			for(x=0;x<SIZE;x++) phi[x]+=len[x];
		}while(phi[S]<MAXW&&aug(S,T,can)!=T);
		return in-can;
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N,M;
	cin >> N >> M;
	vector<int> sum_in(N,0),sum_out(N,0);
	MCMF fsolver;
	int ans0 =0;
	for(int i =0; i < M; i++) {
		int a,b,c,f;
		cin >> a >> b >> c >> f;
		a--, b--;
		sum_in[b] +=f;
		sum_out[a] +=f;
		fsolver.add_edge(a,b,OVER9000,2);
		fsolver.add_edge(a,b,max(0,c-f),1);
		fsolver.add_edge(b,a,min(c,f),1);
		if(f > c) {
			ans0 +=f-c;
			fsolver.add_edge(b,a,f-c,0);}
		}
	fsolver.add_edge(0,N-1,OVER9000,0);
	fsolver.add_edge(N-1,0,OVER9000,0);
	for(int i =0; i < N; i++) {
		int fd =sum_in[i]-sum_out[i];
		fsolver.add_edge(N,i,max(0,fd),0);
		fsolver.add_edge(i,N+1,max(0,-fd),0);}
	fsolver.flow(N,N+1);
	cout << fsolver.sum+ans0 << "\n";
	return 0;}

// look at my code
// my code is amazing