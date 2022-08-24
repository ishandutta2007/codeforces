#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<unordered_map>
using namespace std;
struct tree{
	int l,r,father,w,where,u,v;
}t[1600000];
int n,rev[1600000],len;
struct bian{
	int u,v,w;
}A[510000],B[510000];
unordered_map<int,int>M[510000];
void change(int k){
    if (k==0) return;
    if (t[k].w) t[k].where=k;
    else if (t[t[k].l].where!=0) t[k].where=t[t[k].l].where;
	else t[k].where=t[t[k].r].where; 
}
void reverse(int k){
    if (k==0) return; rev[k]^=1; swap(t[k].l,t[k].r);
}
void pushdown(int k){
    if (rev[k]){
        reverse(t[k].l); reverse(t[k].r); rev[k]=0;
    }
}
void zig(int k){
    int f=t[k].father; pushdown(f); pushdown(k);
    if (t[t[f].father].l==f) t[t[f].father].l=k; else if (t[t[f].father].r==f) t[t[f].father].r=k;
    t[k].father=t[f].father; t[f].l=t[k].r; t[t[f].l].father=f; t[k].r=f; t[f].father=k; change(f);
}
void zag(int k){
    int f=t[k].father; pushdown(f); pushdown(k);
    if (t[t[f].father].l==f) t[t[f].father].l=k; else if (t[t[f].father].r==f) t[t[f].father].r=k;
    t[k].father=t[f].father; t[f].r=t[k].l; t[t[f].r].father=f; t[k].l=f; t[f].father=k; change(f);
}
int splay_root(int k){
    return t[k].father&&(t[t[k].father].l==k||t[t[k].father].r==k);
}
void splay(int k){
    pushdown(k); 
	while (splay_root(k)){
		int f1=t[k].father,f2=t[f1].father;
		if (splay_root(f1)==0){
			if (t[f1].l==k) zig(k); else zag(k); break;
		}
		pushdown(f2);
		if (t[f1].l==k){
			if (t[f2].l==f1){zig(f1); zig(k);} else {zig(k); zag(k);}
		} else if (t[f2].l==f1){zag(k); zig(k);} else {zag(f1); zag(k);}
	}
	change(k);
}
int access(int k){
    int now=0;
    while (k){
        splay(k); t[k].r=now; change(k); now=k; k=t[k].father;
    }
    return now;
}
void makeroot(int k){
    reverse(access(k)); splay(k);
}
int findfather(int k){
    while (t[k].father) k=t[k].father; return k;
}
void link(int k1,int k2){
//	cout<<"link "<<k1<<" "<<k2<<endl;
    makeroot(k1); t[k1].father=k2; int k3=access(k1);
  //  cout<<"fin"<<endl;
}
void cut(int k1,int k2){
	//cout<<"cut "<<k1<<" "<<k2<<endl;
    makeroot(k1); int k3=access(k2); splay(k2); t[k2].l=0; t[k1].father=0; change(k2);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		scanf("%d%d",&A[i].u,&A[i].v); if (A[i].u>A[i].v) swap(A[i].u,A[i].v);
	}
	for (int i=1;i<n;i++){
		scanf("%d%d",&B[i].u,&B[i].v); if (B[i].u>B[i].v) swap(B[i].u,B[i].v);
	}
	for (int i=1;i<n;i++) M[A[i].u][A[i].v]=1;
	for (int i=1;i<n;i++) if (M[B[i].u][B[i].v]==0) B[i].w=1; else B[i].w=0;
	for (int i=1;i<=n;i++) M[i].clear();
	for (int i=1;i<n;i++) M[B[i].u][B[i].v]=1;
	int ans=0;
	for (int i=1;i<n;i++) if (M[A[i].u][A[i].v]==0) A[i].w=1,ans++; else A[i].w=0;
	len=n;
	for (int i=1;i<n;i++){
		len++; t[len].w=A[i].w; t[len].u=A[i].u; t[len].v=A[i].v; change(len);
		link(len,A[i].u); link(len,A[i].v);
	}
	printf("%d\n",ans);
	for (int i=1;i<n;i++)
		if (B[i].w){
			int k1=B[i].u,k2=B[i].v; makeroot(k1); int k3=t[access(k2)].where;
			printf("%d %d %d %d\n",t[k3].u,t[k3].v,k1,k2);
			len++; t[len].w=0; t[len].u=B[i].u; t[len].v=B[i].v;
			cut(k3,t[k3].u); cut(k3,t[k3].v); link(k1,len); link(k2,len);
		}
	return 0;
}