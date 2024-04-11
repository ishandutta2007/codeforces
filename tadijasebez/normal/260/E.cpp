//nikom nije nocas kao meni
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
int ri(){int x;scanf("%i",&x);return x;}
const int N=200050;
int x[N],y[N];
pii p[N];
int ls[N],rs[N],root,tsz;
vector<int> node[N];
void Build(int &c,int ss,int se){
    c=++tsz;
    for(int i=ss;i<=se;i++)node[c].pb(p[i].se);
    sort(node[c].begin(),node[c].end());
    if(ss==se)return;
    int mid=ss+se>>1;
    Build(ls[c],ss,mid);
    Build(rs[c],mid+1,se);
}
int Get(int c,int ss,int se,int qs,int qe,int y){
    if(qs>qe || qs>se || ss>qe)return 0;
    if(qs<=ss && qe>=se)return upper_bound(node[c].begin(),node[c].end(),y)-node[c].begin();
    int mid=ss+se>>1;
    return Get(ls[c],ss,mid,qs,qe,y)+Get(rs[c],mid+1,se,qs,qe,y);
}
int a[9],n;
void Work(){
    int A=a[0]+a[3]+a[6];
    int B=a[1]+a[4]+a[7]+A;
    int C=a[0]+a[1]+a[2];
    int D=a[3]+a[4]+a[5]+C;
    if(x[A]==x[A+1])return;
    if(x[B]==x[B+1])return;
    if(y[C]==y[C+1])return;
    if(y[D]==y[D+1])return;
    if(Get(root,1,n,1,A,y[C])!=a[0])return;
    if(Get(root,1,n,1,B,y[C])!=a[0]+a[1])return;
    if(Get(root,1,n,1,A,y[D])!=a[0]+a[3])return;
    if(Get(root,1,n,1,B,y[D])!=a[0]+a[1]+a[3]+a[4])return;
    printf("%.1f %.1f\n",x[A]+0.5,x[B]+0.5);
    printf("%.1f %.1f\n",y[C]+0.5,y[D]+0.5);
    exit(0);
}
int main(){
    n=ri();
    for(int i=1;i<=n;i++){
        x[i]=ri(),y[i]=ri();
        p[i]={x[i],y[i]};
    }
    sort(x+1,x+1+n);
    sort(y+1,y+1+n);
    sort(p+1,p+1+n);
    Build(root,1,n);
    for(int i=0;i<9;i++)a[i]=ri();
    sort(a,a+9);
    do{
        Work();
    }while(next_permutation(a,a+9));
    printf("-1\n");
    return 0;
}