#include <bits/stdc++.h>
using namespace std;
const int N=100050;
char s[N],t[N];
struct DSU{
    int p[26],sz[26];
    int root(int x){
        if(x==p[x])return x;
        else{
            p[x]=root(p[x]);
            return p[x];
        }
    }
    bool unite(int x,int y){
        x=root(x),y=root(y);
        if(x==y)return 1;
        if(sz[x]<sz[y])swap(x,y);
        p[y]=x,sz[x]+=sz[y];
        return 0;
    }
}D;
int main(){
    int tt;scanf("%i",&tt);
    while(tt--){
        int n;scanf("%i",&n);
        scanf("%s %s",s,t);
        for(int i=0;i<26;i++)D.p[i]=i,D.sz[i]=1;
        int cnt=0;
        bool ok=1;
        for(int i=0;i<n;i++){
            int x=(int)(s[i]-'a');
            int y=(int)(t[i]-'a');
            if(x>y)ok=0;
            if(!D.unite(x,y))cnt++;
        }
        printf("%i\n",(ok?cnt:-1));
    }
    return 0;
}