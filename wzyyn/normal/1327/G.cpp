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
const int N=1005;
char s[N*N];
int ch[N][20],fa[N],co[N];
int n,nd=1,top,v[N],q[N];
ll f[2][1<<14][N];
int init(){
	int l=strlen(s+1),x=1;
	For(i,1,l){
		int c=s[i]-'a';
		if (!ch[x][c]) ch[x][c]=++nd;
		x=ch[x][c];
	}
	return x;
}
void build(){
	static int q[N];
	int h=0,t=0;
	For(i,0,13)
		if (!ch[1][i])
			ch[1][i]=1;
		else{
			fa[ch[1][i]]=1;
			q[++t]=ch[1][i];
		}
	while (h!=t){
		//cerr<<h<<
		int x=q[++h];
		For(i,0,13)
			if (!ch[x][i])
				ch[x][i]=ch[fa[x]][i];
			else{
				fa[ch[x][i]]=ch[fa[x]][i];
				q[++t]=ch[x][i]; 
			}
	}
	For(i,1,t)
		co[q[i]]+=co[fa[q[i]]];
	/*cout<<nd<<endl;
	For(i,1,nd) For(j,0,2)
		cout<<i<<' '<<j<<' '<<ch[i][j]<<endl;*/
}
int cnt[1<<14]; 
int main(){
	For(i,0,(1<<14)-1) cnt[i]=cnt[i/2]+(i&1);
	#ifdef zyy
		freopen("1.in","r",stdin);
	#endif
	scanf("%d",&n);
	For(i,1,n){
		scanf("%s",s+1);
		scanf("%d",&v[i]);
		co[init()]+=v[i];
	}
	build();
	scanf("%s",s+1);
	n=strlen(s+1);
	//cout<<co[1]<<' '<<co[2]<<endl;
	For(i,1,n)
		if (s[i]=='?')
			q[++top]=i;
	q[++top]=n+1;
	//For(I)
	static int tr[20][N];
	static ll trc[20][N];
	For(i,1,top) For(j,1,nd){
		int x=j; ll v=0;
		For(k,q[i-1]+1,q[i]-1)
			v+=co[x=ch[x][s[k]-'a']];
		tr[i][j]=x; trc[i][j]=v;
	}
	memset(f,233,sizeof(f));
	f[0][0][1]=0;
	For(i,1,top){
		memset(f[1],233,sizeof(f[1]));
		For(st,0,(1<<14)-1) if (cnt[st]==i-1) For(j,1,nd) f[1][st][tr[i][j]]=max(f[1][st][tr[i][j]],f[0][st][j]+trc[i][j]);
		if (i==top) break;
		memset(f[0],233,sizeof(f[0]));
		For(st,0,(1<<14)-1) if (cnt[st]==i-1) For(no,0,13) if (!(st&(1<<no)))
			For(j,1,nd) f[0][st|(1<<no)][ch[j][no]]=max(f[0][st|(1<<no)][ch[j][no]],f[1][st][j]+co[ch[j][no]]);
	}
	ll ans=-(1ll<<60);
	For(i,0,(1<<14)-1) For(j,1,nd)
		ans=max(ans,f[1][i][j]);
	printf("%lld\n",ans);
}