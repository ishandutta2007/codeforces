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

ll n;
const int N=1000005;
int type[N],q[N],f[N];
int top,nd,id[N];
ll ans[N];
vector<int> e[N];
int getflow(int x){
	f[x]=0;
	if (type[x]==0) f[x]=1;
	if (type[x]==1){
		f[x]=1ll<<30;
		For(i,0,e[x].size()-1)
			f[x]=min(f[x],getflow(e[x][i]));
	}
	if (type[x]==2){
		f[x]=0;
		For(i,0,e[x].size()-1)
			f[x]+=getflow(e[x][i]);
	}
	return f[x];
}
void updans(int x,ll val){
	if (type[x]==0)
		ans[id[x]]=val;
	if (type[x]==1)
		For(i,0,e[x].size()-1)
			if (f[e[x][i]]==f[x])
				return updans(e[x][i],val);
	if (type[x]==2)
		For(i,0,e[x].size()-1)
			updans(e[x][i],val); 
}
void solve(){
	*id=0;
	ll n;
	cin>>n;
	string tmp;
	getline(cin,tmp);
	int top=0,len=tmp.length();
	for (;nd;type[nd]=0,e[nd].clear(),nd--);
	q[++top]=nd=1;
	For(i,0,len-1){
		if (tmp[i]=='(')
			q[++top]=++nd;
		if (tmp[i]==')'){
			e[q[top-1]].PB(q[top]);
			--top;
		}
		if (tmp[i]=='*')
			e[q[top]].PB(++nd),id[nd]=++*id;
		if (tmp[i]=='S') type[q[top]]=1;
		if (tmp[i]=='P') type[q[top]]=2;
	}
	type[1]=1;
	For(i,1,*id) ans[i]=0;
	n*=getflow(1);
	updans(1,n);
	printf("REVOLTING"); 
	For(i,1,*id) printf(" %lld",ans[i]);
	puts("");
	/*For(i,1,nd){
		printf("ND %d %d ",i,type[i]);
		For(j,0,e[i].size()-1) printf("%d ",e[i][j]);
		puts("");
	}*/
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}