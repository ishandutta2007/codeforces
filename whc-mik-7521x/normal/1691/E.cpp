#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
    int l,r,c;
    bool operator<(const node b)const{
        return l==b.l?r<b.r:l<b.l;
    }
}a[N];
int fa[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void unnion(int x,int y){fa[find(y)]=find(x);}
void init(int x){for(int i=0;i<=x;i++)fa[i]=i;}
int n;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        init(n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i].c,&a[i].l,&a[i].r);
        }
        stable_sort(a+1,a+n+1);
        int ans=0;
        set<pair<int,int>>st1,st2;
        for(int i=1;i<=n;i++){
            while(st1.size()&&st1.begin()->first<a[i].l)st1.erase(st1.begin());
            while(st2.size()&&st2.begin()->first<a[i].l)st2.erase(st2.begin());
            if(a[i].c){
                if(st1.size()){
                    while(st1.size()>1){
                        unnion(i,st1.begin()->second);
                        st1.erase(st1.begin());
                    }
                    unnion(i,st1.begin()->second);
                }
                st2.insert({a[i].r,i});
            }
            else{
                if(st2.size()){
                    while(st2.size()>1){
                        unnion(i,st2.begin()->second);
                        st2.erase(st2.begin());
                    }
                    unnion(i,st2.begin()->second);
                }
                st1.insert({a[i].r,i});
            }
        }
        for(int i=1;i<=n;i++)ans+=i==find(i);
        printf("%d\n",ans);
    }
    return  0;
}