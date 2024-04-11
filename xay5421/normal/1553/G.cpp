// author: xay5421
// created: Thu Jul 22 23:58:33 2021
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=1e6+5;
map<pair<int,int>,int>mp;
vector<int>g[N];
int ban[N],f[N],a[N],id[N],ans[N],ok[N];
int n,q,tot;
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
pair<int,int>minmax(int x,int y){return make_pair(min(x,y),max(x,y));}
int main(){
    rep(i,2,1000001)if(!ban[i]){
        for(int j=i;j<=1000001;j+=i){
            ban[j]=1;
            g[j].push_back(i);
        }
    }
    rep(i,2,1000001)f[i]=i;
    rd(n);rd(q);
    rep(i,1,n){
        rd(a[i]);
        rep(j,0,SZ(g[a[i]])-1){
            f[find(a[i])]=find(g[a[i]][j]);
        }
    }
    rep(i,1,q){
        int s,t;rd(s);rd(t);s=a[s];t=a[t];
        if(find(s)!=find(t)){
            ans[i]=2;
            pair<int,int>tmp=minmax(find(s),find(t));
            if(!mp.count(tmp))mp[tmp]=++tot;
            id[i]=mp[tmp];
        }
    }
    rep(i,1,n){
        vector<int>seq;
        seq.push_back(find(a[i]));
        rep(j,0,SZ(g[a[i]+1])-1){
            seq.push_back(find(g[a[i]+1][j]));
        }
        sort(seq.begin(),seq.end());
        rep(i,0,SZ(seq)-1)rep(j,i+1,SZ(seq)-1){
            if(mp.count(make_pair(seq[i],seq[j])))ok[mp[make_pair(seq[i],seq[j])]]=1;
        }
    }
    rep(i,1,q){
        if(id[i]&&ok[id[i]])ans[i]=1;
        pt(ans[i],'\n');
    }
    return 0;
}