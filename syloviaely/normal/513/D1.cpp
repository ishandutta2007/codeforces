#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
struct bian{
    int next,point,pd;
}b[100];
int n,m,len,p[110],w[110],f[110],l[110],r[110],flag;
void add(int k1,int k2,int k3){
    b[++len]=(bian){p[k1],k2,k3}; p[k1]=len;
}
int getmax(int k1,int k2){
    int num=0;
    for (int i=k1;i<=k2;i++) num=max(num,w[i]);
    return num;
}
int getmin(int k1,int k2){
    int num=n+1;
    for (int i=k1;i<=k2;i++) num=min(num,f[i]);
    return num;
}
void buildtree(int k1,int k2){
    if (getmax(k1,k2)>k2||getmin(k1,k2)<k1){
        flag=1; return;
    }
    if (k1==k2) return;
    int num=k1,k3=k1;
    for (int i=p[k1];i;i=b[i].next)
        if (b[i].pd==0) num=max(num,b[i].point);
    for (int i=k1+1;i<=num;i++) k3=max(k3,w[i]);
    while (num<k3){
        num++; k3=max(k3,w[num]);
    }
    for (int i=p[k1];i;i=b[i].next)
        if (b[i].pd==1&&b[i].point<=num){flag=1; return;}
    if (num!=k1){
        l[k1]=k1+1; buildtree(k1+1,num);
    }
    if (num!=k2){
        r[k1]=num+1; buildtree(num+1,k2);
    }
}
void print(int k){
    if (k==0) return;
    print(l[k]); printf("%d ",k); print(r[k]);
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) f[i]=n+1;
    for (;m;m--){
        int k1,k2; char ch[10]; scanf("%d%d%s",&k1,&k2,ch+1); if (k1>=k2){cout<<"IMPOSSIBLE"<<endl; return 0;}
        if (ch[1]=='L') add(k1,k2,0); else add(k1,k2,1);
        w[k1]=max(w[k1],k2); f[k1]=min(f[k1],k2);
    }
    buildtree(1,n);
    if (flag){cout<<"IMPOSSIBLE"<<endl; return 0;}
    print(1);
    return 0;
}