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
const int N=605;
int query(vector<int> tmp){
	if (!tmp.size()) return 0;
	printf("? %d\n",tmp.size());
	for (auto i:tmp) printf("%d ",i);
	cout<<endl;
	scanf("%d",&tmp[0]);
	return tmp[0];
}
int query(int x,vector<int> tmp){
	int v1=query(tmp);
	tmp.PB(x);
	int v2=query(tmp);
	return v2-v1;
}
int n,h,t,q[N],fa[N],vis[N],dis[N];
void divide(int x,vector<int> tmp,int v){
	if (!tmp.size()) return;
	//cout<<"D "<<x<<' '<<tmp.size()<<' '<<v<<endl;
	if (!v) return;
	if (tmp.size()==1){
		//cout<<"FIND "<<x<<' '<<tmp[0]<<endl;
		q[++t]=tmp[0];
		fa[tmp[0]]=x;
		vis[tmp[0]]=1;
		dis[tmp[0]]=dis[x]+1;
		return;
	}
	int mid=tmp.size()/2;
	vector<int> ls,rs;
	For(i,0,mid-1) ls.PB(tmp[i]);
	For(i,mid,tmp.size()-1) rs.PB(tmp[i]);
	int val=query(x,ls);
	divide(x,ls,val);
	divide(x,rs,v-val);
}
void bfs(int S){
	h=0,t=1; q[1]=S; vis[S]=1;
	while (h!=t){
		int x=q[++h];
		vector<int> tmp;
		For(i,1,n) if (!vis[i]) tmp.PB(i);
		if (tmp.size()) divide(x,tmp,query(x,tmp));
	}
}
void NOTBIPAR(vector<int> tmp){
	int x=-1,y=-1;
	for (;tmp.size();){
		x=tmp.back();
		tmp.pop_back();
		if (!query(x,tmp)) continue;
		int l=0,r=tmp.size()-1;
		while (l<r){
			int mid=(l+r)/2;
			vector<int> ttmp;
			For(i,l,mid) ttmp.PB(tmp[i]);
			if (query(x,ttmp)) r=mid;
			else l=mid+1;
		}
		y=tmp[l];
		break;
	}
	static int q[N*2];
	int h=N,t=h+1; q[h]=x; q[t]=y;
	for (;x!=y;)
		if (dis[x]<dis[y])
			q[++t]=y=fa[y];
		else q[--h]=x=fa[x]; 
	printf("N\n%d\n",t-h);
	For(i,h+1,t) printf("%d ",q[i]); puts("");
}
int main(){
	scanf("%d",&n);
	For(i,1,n) if (!vis[i]) bfs(i);
	For(i,1,n) if (dis[i]) q[++*q]=i;
	vector<int> tmp;
	//cout<<"ENDL"<<endl;
	For(i,1,n) if (!(dis[i]&1)) tmp.PB(i);
	if (query(tmp)) NOTBIPAR(tmp);
	tmp.resize(0);
	For(i,1,n) if (dis[i]&1) tmp.PB(i);
	if (query(tmp)) NOTBIPAR(tmp);
	puts("Y");
	printf("%d\n",tmp.size());
	for (auto i:tmp) printf("%d ",i);
}
/*
4
2
4
0
1
0
0
0
1
//1-2 2-3 3-4 4-1
*/