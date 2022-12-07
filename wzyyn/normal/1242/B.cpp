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
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
using namespace std;
const int N=100005;
int q[N],vis[N];
int h,t,n,m,ans;
vector<int> e[N];
set<int> S,S1;
void push(int x){
	S.erase(x);
	q[++t]=x;
	vis[x]=1;
}
void work(){
	while (h!=t){
		int x=q[++h];
		S1=S;
		for (auto i:e[x])
			S1.erase(i);
		for (auto i:S1)
			push(i);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	For(i,1,n) S.insert(i);
	For(i,1,n)
		if (!vis[i]){
			++ans;
			push(i);
			work();
		}
	printf("%d",ans-1);
}