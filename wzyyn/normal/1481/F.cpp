#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;

const int N=100005;
int n,x,mx,flg[N],f[N],g[N];
int fa[N],d[N],nlf[N],s[N];
vector<int> v1[N];
vector<int> v2[N];
vector<int> v3[N];

void construct1(){
	printf("%d\n",mx+1);
	int p=x;
	for (;p!=0;p-=f[p]){
		int x=v3[f[p]].back();
		v3[f[p]].pop_back();
		for (auto i:v1[x]) flg[i]=1;
		for (auto i:v2[x]) flg[i]=1;
	}
	For(i,1,n) putchar(flg[i]?'a':'b');
}
void construct2(){
	printf("%d\n",mx+2);
	int r1=x,r2=n-x,p=-1;
	For(j,0,n)
		if (r1>=s[j]){
			for (auto y:v1[j]) flg[y]=1;
			for (auto y:v2[j]) flg[y]=1;
			r1-=s[j];
		}
		else if (r2>=s[j])
			r2-=s[j];
		else p=j;
	assert(p!=-1);
	if (r1>=v1[p].size()){
		for (auto j:v1[p]) flg[j]=1,--r1;
		For(j,0,r1-1) flg[v2[p][j]]=1;
	}
	else{
		assert(r1<=v2[p].size());
		For(j,0,r1-1) flg[v2[p][j]]=1;
	}
	For(i,1,n) putchar(flg[i]?'a':'b');
}

vector<int> e[N];
void dfs(int x){
	mx=max(mx,d[x]);
	for (auto i:e[x]){
		d[i]=d[x]+1;
		dfs(i);
	}
}
int main(){
	scanf("%d%d",&n,&x);
	For(i,2,n){
		scanf("%d",&fa[i]);
		e[fa[i]].PB(i);
		nlf[fa[i]]=1;
	}
	dfs(1);
	For(i,1,n){
		++s[d[i]];
		if (nlf[i]) v1[d[i]].PB(i);
		else v2[d[i]].PB(i);
	}
	For(i,0,n)
		if (s[i])
			v3[s[i]].PB(i);
	memset(f,30,sizeof(f));
	f[0]=0;
	For(i,1,n) if (v3[i].size()){
		int num=v3[i].size();
		memset(g,0,sizeof(g));
		For(j,0,n) if (f[j]<i) ++g[j],--g[j+num*i];
		For(j,i,n) g[j]+=g[j-i];
		For(j,i,n) if (g[j-i]&&f[j]>=i) f[j]=i;
	}
	if (f[x]<1e6) construct1();
	else construct2();
}