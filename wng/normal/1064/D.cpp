#include <bits/stdc++.h>
typedef long long LL;
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,r,c,x,y;
	cin>>n>>m>>r>>c>>x>>y;
	r--;
	c--;
	vector<VI> t(n,VI(m));
	REP(i,n){
		string s;
		cin>>s;
		REP(j,m){
			if (s[j]=='*') t[i][j]=1;
		}
	}
	vector<VI> node(n,VI(m));
	int k=0;
	VI nbnode(2000100);
	REP(j,m){
		REP(i,n){
			if (!t[i][j]) {
				if (i==0 or t[i-1][j]) k++;
				node[i][j]=k;
				nbnode[k]++;
			}
		}
	}
	vector<VI> cs(k+1);
	VI visited(k+1);
	REP(j,m-1){
		REP(i,n){
			if (node[i][j] and node[i][j+1]){
				cs[node[i][j]].PB(node[i][j+1]);
				cs[node[i][j+1]].PB(node[i][j]);
				//cout<<" :"<<node[i][j]<<" "<<node[i][j+1]<<endl;
				int b1=node[i][j];
				int b2=node[i][j+1];
				while (i<n-1 and (node[i+1][j]<=b1 and node[i+1][j+1]<=b2)) i++;
			}
		}
	}
	//OK got a tree. Shortest path from root
	int root=node[r][c];
	priority_queue<pair<int,PII>> pq;
	pq.push({0,{root,0}});
	/*
	REP(i,n){
		REP(j,m){cout<<t[i][j];} cout<<endl;
	}
	cout<<endl;
	REP(i,n){
		REP(j,m){cout<<node[i][j]<<"\t";} cout<<endl;
	}*/
	int res=0;
	while (!pq.empty()){
		auto it=pq.top();
		pq.pop();
		if (!visited[it.S.F]){
			int nbr=it.S.S;
			int nbl=-it.F-nbr;
			int v=it.S.F;
			//cout<<"ved "<<v<<" "<<it.F<<" "<<nbr<<endl;
			visited[v]=1;
			res+=nbnode[v];
			for (auto c:cs[v]){
				if (!visited[c]){
					if (c<v and nbl<x){
						pq.push({-(nbr+nbl+1),{c,nbr}});
					}
					if (c>v and nbr<y){
						pq.push({-(nbr+nbl+1),{c,nbr+1}});
					}
				}
			}
		}
	}
	/*REPP(i,1,k+1){
		cout<<i<<" "<<visited[i]<<" "<<nbnode[i]<<endl;
	}*/
	cout<<res<<endl;
}