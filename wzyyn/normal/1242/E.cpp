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
const int N=300005;
int q[N],S[N],n,nd;
int pre[N],nxt[N],co[N];
vector<int> vec[N];
pii a[N];
set<int> SS;
void erase(int x){
	SS.erase(x);
	SS.erase(pre[x]);
	SS.erase(nxt[x]);
	pre[nxt[x]]=pre[x];
	nxt[pre[x]]=nxt[x];
	if (co[pre[pre[x]]]!=co[pre[x]]) SS.insert(pre[x]);
	if (co[pre[nxt[x]]]!=co[nxt[x]]) SS.insert(nxt[x]);
}
void insert(int x,int c){
	SS.erase(x);
	SS.erase(nxt[x]);
	pre[++nd]=x; nxt[nd]=nxt[x];
	pre[nxt[x]]=nd; nxt[x]=nd; co[nd]=c;
	if (co[pre[pre[nd]]]!=co[pre[nd]]) SS.insert(pre[nd]);
	if (co[pre[nxt[nd]]]!=co[nxt[nd]]) SS.insert(nxt[nd]);
	if (co[pre[nd]]!=co[nd]) SS.insert(nd);
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i].fi),a[i].se=i;
	sort(a+1,a+n+1,greater<pii >());
	Rep(i,n,1) S[i]=S[i+1]+a[i].fi-2;
	For(i,1,a[1].fi)
		vec[a[1].se].PB(++nd);
	For(i,1,nd){
		pre[i]=(i==1?nd:i-1);
		nxt[i]=(i==nd?1:i+1);
		co[i]=1;
	}
	*q=nd;
	For(i,2,n){
		int con=2;
		for (;con<a[i].fi&&con<(*q)&&(*q)+a[i].fi-2*(con+1)+2-2>S[i+1]&&(*q)+a[i].fi-2*(con+1)+2>=3;++con);
		int posi=(i==2?1:pre[*SS.begin()]);
		vec[a[i].se].PB(posi);
		For(j,1,con-2){
			vec[a[i].se].PB(nxt[posi]);
			erase(nxt[posi]);
		}
		vec[a[i].se].PB(nxt[posi]);
		SS.erase(posi);
		co[posi]=i;
		if (co[pre[posi]]!=co[posi])
		    SS.insert(posi);
		For(j,con+1,a[i].fi){
			insert(posi,i);
			vec[a[i].se].PB(nd);
		}
		*q=*q+a[i].fi-2*con+2;
		//printf("%d %d %d\n",con,posi,*q);
		//For(j,1,*q) printf("%d ",q[j]); puts("");
	}
	printf("%d\n",nd);
	For(i,1,n){
		for (auto j:vec[i])
			printf("%d ",j);
		puts("");
	}
}