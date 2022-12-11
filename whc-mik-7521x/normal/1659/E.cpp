#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct dsu{
    int fa[N],pd[N];
    int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
    void unnion(int x,int y){fa[find(y)]=find(x);}
    void init(int x){for(int i=0;i<=x;i++)fa[i]=i,pd[i]=0;}
}ds1[35],ds2[35];
int n,m;
struct node{
    int x,y,w;
};
vector<node>nd;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        nd.push_back(node{x,y,w});
    }
    for(int i=0;i<30;i++){
        ds1[i].init(n);
        ds2[i].init(n);
        for(auto it:nd)if(it.w&(1<<i))ds1[i].unnion(it.x,it.y);
        if(!i)continue;
        for(auto it:nd){
            if((it.w&1)&&(it.w&(1<<i)))ds2[i].unnion(it.x,it.y);
        }
    }
    set<int>st;
    for(auto it:nd){
        if(!(it.w&1))st.insert(it.x),st.insert(it.y);
    }
    for(int i=1;i<=30;i++){
        for(int o:st)ds2[i].pd[ds2[i].find(o)]=1;
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        int pdd=0;
        for(int i=0;i<30;i++)if(ds1[i].find(x)==ds1[i].find(y))pdd=1;
        if(pdd){puts("0");continue;}
        for(int i=1;i<30;i++)if(ds2[i].pd[ds2[i].find(x)])pdd=1;
        if(pdd){puts("1");continue;}
        puts("2");
    }
    return  0;
}