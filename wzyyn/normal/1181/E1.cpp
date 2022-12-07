#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=100005;
struct node{
	int l,r,id;
	bool operator <(const node &a)const{
		if (l!=a.l) return l<a.l;
		if (r!=a.r) return r<a.r;
		return id<a.id;
	}
}p[N][4];
set<node> S[4];
int n;
void solve(set<node> *S){
	int n=S[0].size();
	if (S[0].size()==1) return;
	set<node> T[4];
	set<node>::iterator it[4];
	int mx[4];
	For(i,0,3) it[i]=S[i].begin(),mx[i]=-(1<<30);
	For(i,1,n-1){
		For(j,0,3) mx[j]=max(mx[j],(it[j]++)->r);
		For(j,0,3) if (mx[j]<=it[j]->l){
			set<node>::iterator it=S[j].begin();
			For(k,1,i){
				int id=(it++)->id;
				For(l,0,3){
					T[l].insert(p[id][l]);
					S[l].erase(p[id][l]);
				}
			}
			solve(S);
			solve(T);
			return;
		}
	}
	puts("NO");
	exit(0);
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		S[0].insert(p[i][0]=(node){a,c,i});
		S[1].insert(p[i][1]=(node){b,d,i});
		S[2].insert(p[i][2]=(node){-c,-a,i});
		S[3].insert(p[i][3]=(node){-d,-b,i});
	}
	solve(S);
	puts("YES");
}