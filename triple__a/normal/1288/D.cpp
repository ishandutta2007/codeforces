#include<bits/stdc++.h>
using namespace std;

const int maxn=300007;
int n,m;
int a[maxn][9];
int vec[260];

bool ck(int u){
    int ret=(1<<m)-1;
    for (int i=0;i<(1<<m);++i) vec[i]=-1;
    for (int i=0;i<n;++i){
        int val=0;
        for (int j=0;j<m;++j){
            if (a[i][j]>=u) val+=(1<<j);
        }
        vec[0]=i;
        for (int j=val;j;j=(j-1)&val){
            vec[j]=i;
        }
    }
    for (int i=0;i<=ret;++i){
        if (vec[i]!=-1&&vec[ret-i]!=-1) return 1;
    }
    return 0;
}
int ms(int l,int r){
    if (l==r) {ck(l); return l;}
    int md=(l+r)>>1;
    if (ck(md+1)) return ms(md+1,r);
    else return ms(l,md);
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;++i) for (int j=0;j<m;++j) scanf("%d",&a[i][j]);
    ms(0,1e9);
    int ret=(1<<m)-1;
    for (int i=0;i<=ret;++i){
        if (vec[i]!=-1&&vec[ret-i]!=-1){
            printf("%d %d\n",vec[i]+1,vec[ret-i]+1);
            return 0;
        }
    }
    return 0;
}