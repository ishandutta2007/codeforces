#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
struct bian{
    int next,point,pd;
}b[110000];
int w[1000010][20],Log2[1100000],n,m,l[1100000],r[1100000],f[1000011][20],flag,p[1100000],len,go[1000011][20];
void add(int k1,int k2,int k3){
    b[++len]=(bian){p[k1],k2,k3}; p[k1]=len;
}
int getmax(int l,int r){
    if (l>r) return 0;
    int k1=Log2[r-l+1]; return max(w[l+(1<<k1)-1][k1],w[r][k1]);
}
int getmin(int l,int r){
    int k1=Log2[r-l+1]; return min(f[l+(1<<k1)-1][k1],f[r][k1]);
}
int findnext(int k1,int k2){
    for (int i=19;i>=0;i--)
        if (go[k1][i]-1<=k2) k1=go[k1][i];
    if (k1<k2+1) k1=go[k1][0]; return k1;
}
void buildtree(int k1,int k2){
    if (getmax(k1,k2)>k2||getmin(k1,k2)<k1){
        flag=1; return;
    }
    if (k1==k2) return;
    int num=k1,k3=k1;
    for (int i=p[k1];i;i=b[i].next)
        if (b[i].pd==0) num=max(num,b[i].point);
    k3=max(max(k3,num),getmax(k1+1,num)); num=findnext(k1+1,k3)-1;
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
    int pre=0,now=0;
    while ((1<<now)<=n){
        int l=(1<<now),r=min(n,(1<<(now+1))-1);
        for (int i=l;i<=r;i++) Log2[i]=now; now++;
    }
    for (int i=1;i<=n;i++) f[i][0]=n+1;
    for (;m;m--){
        int k1,k2; char ch[10]; scanf("%d%d%s",&k1,&k2,ch+1);  if (k1>=k2){cout<<"IMPOSSIBLE"<<endl; return 0;}
        if (ch[1]=='L') add(k1,k2,0); else add(k1,k2,1);
        w[k1][0]=max(w[k1][0],k2); f[k1][0]=min(f[k1][0],k2);
    }
    for (int i=0;i<20;i++) go[n+1][i]=n+1;
    for (int i=n;i;i--)
        if (w[i][0]==0){
            go[i][0]=i+1; 
            for (int j=1;j<20;j++) go[i][j]=go[go[i][j-1]][j-1];
        } else {
            go[i][0]=findnext(i+1,w[i][0]);
            for (int j=1;j<20;j++) go[i][j]=go[go[i][j-1]][j-1];
        }
    for (int i=1;i<20;i++)
        for (int j=(1<<i);j<=n;j++){
            w[j][i]=max(w[j][i-1],w[j-(1<<i-1)][i-1]);
            f[j][i]=min(f[j][i-1],f[j-(1<<i-1)][i-1]);
        }
    buildtree(1,n);
    if (flag){cout<<"IMPOSSIBLE"<<endl; return 0;}
    print(1);
    return 0;
}