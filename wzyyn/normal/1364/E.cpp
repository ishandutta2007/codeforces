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
int ans[1<<13];
int cnt[1<<13],q[1<<13];
int val1[1<<13],val2[1<<13];
int p[1<<13],tot,n,key[32][32];
map<pii,int> mp;
int query(int x,int y){
	++tot;
	/*assert(x!=y);
	assert(0<=x&&x<n);
	assert(0<=y&&y<n);*/
	int v;
	#ifdef zyy
		return p[x]|p[y];
	#else
		if (x>y) swap(x,y);
		if (mp.find(pii(x,y))!=mp.end())
			return mp[pii(x,y)];
		cout<<"? "<<x+1<<' '<<y+1<<endl;
		fflush(stdout);
		cin>>v;
		return mp[pii(x,y)]=v;
	#endif 
}
void init(){
	For(i,0,4095) cnt[i]=cnt[i/2]+(i&1);
	#ifdef zyy
		srand(time(NULL));
		For(i,0,n-1) p[i]=i;
		random_shuffle(p,p+n);
	#endif 
}
int main(){
	n=2048;
	#ifndef zyy
		scanf("%d",&n);
	#endif
	init();
	srand(time(NULL));
	for (;clock()<=200;rand());
	int co=4095,v1,v2; 
	For(T,1,60){
		int p1=rand()%n;
		int p2=rand()%n; 
		if (p1==p2) p2=(p2+1)%n;
		int v=query(p1,p2);
		if (cnt[v]<cnt[co])
			co=v,v1=p1,v2=p2;
	}
	int mn1=1<<30,mn2=1<<30,top=0;
	For(i,0,n-1) if (i!=v1)
		mn1=min(mn1,val1[i]=query(i,v1));
	val1[v1]=mn1;
	For(i,0,n-1) if (i!=v2&&val1[i]==mn1)
		mn2=min(mn2,val2[i]=query(i,v2));
	val2[v2]=mn2;
	For(i,0,n-1)
		if (val1[i]==mn1&&val2[i]==mn2)
			q[++top]=i;//cerr<<"FIND "<<i<<' '<<p[i]<<endl;
	int spe=-1;
	if (top!=2){
		random_shuffle(q+1,q+top+1);
		For(i,1,top){
			static int vis[1<<13];
			memset(vis,0,sizeof(vis));
			bool flag=0;
			For(j,1,top) if (j!=i){
				int v=query(q[i],q[j]);
				if (vis[v]){
					flag=1;
					break;
				}
				vis[v]=1;
			}
			if (!flag) spe=q[i];
		}
	}
	else{
		for (;;){
			int p=rand()%n;
			if (p==q[1]||p==q[2]) continue;
			int v=query(q[1],p);
			int vv=query(q[2],p);
			if (v^vv){
				spe=(v<vv?q[1]:q[2]);
				break;
			}
		}
	}
	//assert(spe!=-1);
	For(i,0,n-1) if (i!=spe) ans[i]=query(i,spe);
	//cerr<<tot<<' '<<top<<endl;
	//exit(0);
	cout<<"!";
	For(i,0,n-1) cout<<' '<<ans[i];
	cout<<endl;
}