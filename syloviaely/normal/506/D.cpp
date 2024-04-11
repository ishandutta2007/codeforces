#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<unordered_map>
using namespace std;
struct bian{
    int u,v,w;
}b[110000],A[110000];
int n,m,q,f[110000],w[110000],x[110000],pd[110000],now,len,bo[110000],lim=300;
unordered_map<int,int>S[110000];
int compare(bian k1,bian k2){
    return k1.w<k2.w;
}
int findfather(int k){
    if (f[k]==k) return k; f[k]=findfather(f[k]); return f[k];
}
int compare2(bian k1,bian k2){
    return k1.u<k2.u||(k1.u==k2.u&&k1.v<k2.v);
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++) scanf("%d%d%d",&b[i].u,&b[i].v,&b[i].w);
    scanf("%d",&q);
    for (int i=1;i<=q;i++) scanf("%d%d",&A[i].u,&A[i].v); 
    sort(b+1,b+m+1,compare); int l=1;
    for (now=1;now<=100000;now++){
        len=0;
        while (l<=m&&b[l].w==now){
            int k1=b[l].u,k2=b[l].v;
            if (bo[k1]!=now){bo[k1]=now; x[++len]=k1; f[k1]=k1;} else k1=findfather(k1);
            if (bo[k2]!=now){bo[k2]=now; x[++len]=k2; f[k2]=k2;} else k2=findfather(k2);
            if (k1!=k2) f[k1]=k2; l++;
        }
        if (len>=lim){
            for (int i=1;i<=q;i++){
                int k1=A[i].u,k2=A[i].v;
                if (bo[k1]==now&&bo[k2]==now) A[i].w+=(findfather(k1)==findfather(k2));
            }
        } else {
            for (int i=1;i<=len;i++)
                if (bo[x[i]]==now)
                    for (int j=i+1;j<=len;j++)
                        if (bo[x[j]]==now&&findfather(x[i])==findfather(x[j])) S[x[i]][x[j]]++;
        }
    }
    for (int i=1;i<=q;i++) printf("%d\n",A[i].w+S[A[i].u][A[i].v]+S[A[i].v][A[i].u]);
    return 0;
}