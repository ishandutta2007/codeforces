#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

//0: =0
//1: =1
//8: 1 
//2: >=20
//3: >=21
//4: >=22
//5: 2
//6: =1 
//7: =2 

int n,tot,ans;
int v[200005],nxt[200005],h[100005],d[100005][9];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u,int fa){
	d[u][0]=1;
	int now1=0,now2=0,now3=0,cnt=0,tmp1=0,tmp2=0;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dfs(v[p],u);
		if(d[v[p]][6]) d[u][1]=2;
		int ttmp=max(max(d[v[p]][6],d[v[p]][7]),max(d[v[p]][2],d[v[p]][3]));
		if(ttmp>tmp1) tmp2=tmp1,tmp1=ttmp;
		else chkmax(tmp2,ttmp);
		chkmax(d[u][8],max(max(d[v[p]][6],d[v[p]][7]),max(d[v[p]][2],d[v[p]][3]))+1);
		d[u][2]+=max(d[v[p]][6],d[v[p]][0]);
		int tmp=max(max(d[v[p]][2],d[v[p]][3]),max(d[v[p]][7],d[v[p]][8]))-max(d[v[p]][6],d[v[p]][0]);
		if(tmp>now1) now3=now2,now2=now1,now1=tmp;
		else if(tmp>now2) now3=now2,now2=tmp;
		else chkmax(now3,tmp);
		chkmax(d[u][5],d[v[p]][4]);
		chkmax(ans,d[v[p]][4]+1);
		if(d[v[p]][6]||d[v[p]][0]) d[u][6]=1,cnt++;
		if(d[v[p]][7]||d[v[p]][1]) d[u][7]=2;
	}
	chkmax(ans,tmp1+tmp2+1);
	if(cnt>=2) d[u][7]=2;
	if(now1>0) d[u][3]=d[u][2]+now1;
	if(now2>0) d[u][4]=d[u][2]+now1+now2;
	chkmax(ans,d[u][3]),chkmax(ans,d[u][4]);
	chkmax(ans,d[u][0]),chkmax(ans,d[u][1]),chkmax(ans,d[u][2]),chkmax(ans,d[u][5]);
	chkmax(ans,d[u][6]),chkmax(ans,d[u][7]),chkmax(ans,d[u][8]);
//	cout<<"test "<<u<<endl;
//	for(int i=0;i<=8;i++) cout<<d[u][i]<<' ';
//	cout<<endl;
}

int main(){
	n=readint();
	for(int i=1;i<n;i++) addedge(readint(),readint());
	dfs(1,-1);
	printf("%d\n",ans);
	return 0;
}