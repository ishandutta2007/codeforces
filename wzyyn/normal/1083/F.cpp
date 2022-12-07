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
const int N=400005;
const int B=800;
struct node{
	int a[(1<<14)+2];
};
int n,k,Q,GG,ans;
int a[N],b[N],c[N],l[N];
vector<int> tg[N],v[N];
vector<node> su[N];
void build(int x){
	l[x]=v[x].size()-1;
	tg[x].resize(l[x]/B+3);
	su[x].resize(l[x]/B);
	For(i,1,l[x]) v[x][i]^=v[x][i-1];
	For(i,0,l[x]/B*B-1) ++su[x][i/B].a[v[x][i]];
	if (v[x][l[x]]) ++GG;
	For(i,0,l[x]) ans-=(!v[x][i]);
}
void work(int p,int val){
	int x=(p-1)%k,be=(p-1)/k/B; p=(p-1)/k;
	GG-=((v[x][l[x]]^tg[x][l[x]/B])!=0);
	//cout<<GG<<endl;
	if (p/B!=l[x]/B){
		for (;p/B==be;++p){
			ans+=(v[x][p]==tg[x][p/B]);
			--su[x][p/B].a[v[x][p]];
			v[x][p]^=val;
			ans-=(v[x][p]==tg[x][p/B]);
			++su[x][p/B].a[v[x][p]];
		}
		p=l[x]/B*B;
	}
	for (;p<=l[x];++p){
		ans+=(v[x][p]==tg[x][p/B]);
		v[x][p]^=val;
		ans-=(v[x][p]==tg[x][p/B]);
	}
	for (be++;be<l[x]/B;be++){
		ans+=su[x][be].a[tg[x][be]];
		tg[x][be]^=val;
		ans-=su[x][be].a[tg[x][be]];
	}
	GG+=((v[x][l[x]]^tg[x][l[x]/B])!=0);
	//cout<<GG<<' '<<ans<<endl;
}
int main(){
	scanf("%d%d%d",&n,&k,&Q);
	ans=n+k;
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) scanf("%d",&b[i]);
	For(i,1,n+k) c[i]=a[i]^b[i]^a[i-1]^b[i-1];
	For(i,1,n+k) v[(i-1)%k].PB(c[i]);
	For(i,0,k-1) build(i);
	printf("%d\n",GG?-1:ans);
	while (Q--){
		char s[5]; int x,y;
		scanf("%s%d%d",s+1,&x,&y);
		y^=(s[1]=='a'?a[x]:b[x]);
		work(x,y); work(x+1,y);
		s[1]=='a'?a[x]^=y:b[x]^=y;
		printf("%d\n",GG?-1:ans);
	}
}