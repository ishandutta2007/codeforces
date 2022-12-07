#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int mo=998244353;
const int N=100005;
const int BLK=405;
const int K=255;
int L[K],R[K],tg[K];
int top[K],pos[K];
int id[N],f[N],s[N];
int v[N],V[N],LIM;
int a[N],la[N],pre[N],n;
void pushdown(int k){
	For(i,L[k],R[k]) s[i]+=tg[k];
	tg[k]=0;
}
void pushup(int k){
	top[k]=L[k];
	v[top[k]]=f[id[L[k]]];
	V[top[k]]=s[id[L[k]]];
	For(i,L[k]+1,R[k]){
		if (s[id[i]]!=s[id[i-1]]){
			V[++top[k]]=s[id[i]];
			v[top[k]]=v[top[k]-1];
		}
		v[top[k]]=(v[top[k]]+f[id[i]])%mo;
	}
	pos[k]=L[k]-1;
	for (;pos[k]!=top[k];++pos[k])
		if (V[pos[k]+1]>LIM) break;
	//cerr<<v[top[k]]<<' '<<(top[k]==L[k]-1?0:v[pos[k]])<<endl;
}
bool cmp(int x,int y){
	return s[x]<s[y];
}
void build(int k){
	For(i,L[k],R[k]) id[i]=i;
	sort(id+L[k],id+R[k]+1,cmp);
	pushup(k);
}
int q1[BLK+5],q2[BLK+5];
void add(int k,int l,int r,int v){
	pushdown(k);
	int p1=0,p2=0,p3=L[k]-1;
	For(i,L[k],R[k])
		if (l<=id[i]&&id[i]<=r)
			q1[++p1]=id[i],s[id[i]]+=v;
		else q2[++p2]=id[i];
	int pp1=1,pp2=1;
	for (;pp1<=p1||pp2<=p2;)
		if (pp2>p2||(pp1<=p1&&s[q1[pp1]]<s[q2[pp2]]))
			id[++p3]=q1[pp1++];
		else id[++p3]=q2[pp2++]; 
	pushup(k);
}
void add(int k,int val){
	tg[k]+=val;
	for (;pos[k]!=top[k]&&V[pos[k]+1]+tg[k]<=LIM;++pos[k]);
	for (;pos[k]!=L[k]-1&&V[pos[k]]+tg[k]>LIM;--pos[k]); 
}
int query(int k){
	return pos[k]==L[k]-1?0:v[pos[k]];
}
int ed;
void change(int l,int r,int v){
	for (;r>=l&&r>=ed;r--) s[r]+=v;
	if (r<l) return;
	int bl=l/BLK,br=r/BLK;
	if (bl==br) add(bl,l,r,v);
	else{
		For(i,bl+1,br-1) add(i,v);
		add(bl,l,R[bl],v);
		add(br,L[br],r,v);
	}
}
void update(int x){
	change(pre[x],x-1,1);
	if (pre[x]) change(pre[pre[x]],pre[x]-1,-1);
}
int main(){
	scanf("%d%d",&n,&LIM);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) la[a[i]]=0;
	For(i,1,n) pre[i]=la[a[i]],la[a[i]]=i;
	For(i,0,n/BLK) L[i]=i*BLK,R[i]=min(i*BLK+BLK-1,n);
	f[0]=1;
	For(i,1,n){
		update(i);
		int be=i/BLK;
		For(j,0,be-1) f[i]=(f[i]+query(j))%mo;
		For(j,be*BLK,i-1) if (s[j]<=LIM) 
			f[i]=(f[i]+f[j])%mo;
		if (i%BLK==BLK-1||i==n)
			build(i/BLK),ed=i+1;
	}
	printf("%d\n",f[n]);
} 
/*
8 2
1 2 3 4 4 3 2 1
1 2 3 5 11 23 41 68
*/