#include<bits/stdc++.h>
using namespace std;

const int N=6000005;
const int M=(1<<20)-1;
int n,Q,nd,rt;
int ch[N][2];
int S[N],fl[N];
int tg0[N],tg1[N];
void pushup(int k,int d){
	S[k]=S[ch[k][0]]+S[ch[k][1]];
	fl[k]=fl[ch[k][0]]|fl[ch[k][1]];
	if (ch[k][0]&&ch[k][1]) fl[k]|=1<<d;
}
int Newnode(){
	++nd;
	tg0[nd]=0;
	tg1[nd]=M;
	return nd;
}
void insert(int &k,int d,int v){
	if (!k) k=Newnode();
	if (d==-1) return S[k]=1,void(0);
	insert(ch[k][(v>>d)&1],d-1,v);
	pushup(k,d);
}

void AddTag(int k,int v0,int v1){
	int s0=tg0[k],s1=tg1[k];
	tg0[k]=((M^s0)&v0)|(s0&v1);
	tg1[k]=((M^s1)&v0)|(s1&v1);
}
void pushdown(int k,int d){
	if (ch[k][0]) AddTag(ch[k][0],tg0[k],tg1[k]);
	if (ch[k][1]) AddTag(ch[k][1],tg0[k],tg1[k]);
	int v0=ch[k][0],v1=ch[k][1];
	int p0=(tg0[k]>>d)&1,p1=(tg1[k]>>d)&1;
	ch[k][0]=ch[k][1]=0;
	ch[k][p0]+=v0; ch[k][p1]+=v1;
	tg0[k]=0; tg1[k]=M;	
} 
int Query(int k,int d,int l,int r,int x,int y){
	if (x<=l&&r<=y) return S[k];
	pushdown(k,d);
	int mid=(l+r)/2;
	if (y<=mid) return Query(ch[k][0],d-1,l,mid,x,y);
	if (x>mid) return Query(ch[k][1],d-1,mid+1,r,x,y);
	return Query(ch[k][0],d-1,l,mid,x,mid)+Query(ch[k][1],d-1,mid+1,r,mid+1,y);
}
int Merge(int x,int y,int d){
	if (!x||!y) return x+y;
	if (d==-1) return x;
	pushdown(x,d);
	pushdown(y,d);
	ch[x][0]=Merge(ch[x][0],ch[y][0],d-1);
	ch[x][1]=Merge(ch[x][1],ch[y][1],d-1);
	pushup(x,d);
	return x;
}
void And(int k,int d,int v){
	if (!(fl[k]&(M^v))){
		AddTag(k,0,v);
		return;
	}
	pushdown(k,d);
	if (ch[k][0])
		And(ch[k][0],d-1,v);
	if (ch[k][1])
		And(ch[k][1],d-1,v);
	
	if (!((v>>d)&1)){
		ch[k][0]=Merge(ch[k][0],ch[k][1],d-1);
		ch[k][1]=0;
	}
	pushup(k,d);
}
void Or(int k,int d,int v){
	if (!(fl[k]&v)){
		AddTag(k,v,M);
		return;
	}
	pushdown(k,d);
	if (ch[k][0])
		Or(ch[k][0],d-1,v);
	if (ch[k][1])
		Or(ch[k][1],d-1,v);
	if (((v>>d)&1)){
		ch[k][1]=Merge(ch[k][0],ch[k][1],d-1);
		ch[k][0]=0;
	}
	pushup(k,d);
}
pair<int,int> split(int k,int d,int l,int r,int x,int y){
	if (y<l||x>r||!k)
		return pair<int,int>(k,0);
	if (x<=l&&r<=y)
		return pair<int,int>(0,k);
	int nk=Newnode();
	int mid=(l+r)/2;
	pushdown(k,d);
	pair<int,int> re1=split(ch[k][0],d-1,l,mid,x,y);
	pair<int,int> re2=split(ch[k][1],d-1,mid+1,r,x,y);
	ch[k][0]=re1.first;
	ch[k][1]=re2.first;
	ch[nk][0]=re1.second;
	ch[nk][1]=re2.second;
	pushup(k,d);
	pushup(nk,d);
	return pair<int,int>(k,nk);
}
int main(){
	scanf("%d%d",&n,&Q);
	for (int i=1;i<=n;i++){
		int v;
		scanf("%d",&v);
		insert(rt,19,v);
	}
	while (Q--){
		int op,l,r,v;
		scanf("%d%d%d",&op,&l,&r);
		if (op==4)
			printf("%d\n",Query(rt,19,0,M,l,r));
		else{
			int v;
			scanf("%d",&v);
			pair<int,int> rtp=split(rt,19,0,M,l,r);
			if (op==1) And(rtp.second,19,v);
			if (op==2) Or(rtp.second,19,v);
			if (op==3) AddTag(rtp.second,v,M^v);
			rt=Merge(rtp.first,rtp.second,19);
		}
	}
}