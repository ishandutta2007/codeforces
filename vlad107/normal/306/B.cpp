#include <stdio.h>
#include <algorithm>
#include <set>
#include <vector>
#define N 500500
#define M 2000440
#define pb push_back
using namespace std;
multiset<int>s;
int n,m,nom[M],mt;
bool used[N];
vector<int>g[M];
struct Point{
    int x,y,u;
    inline bool operator<(const Point &t)const{return ((x<t.x)||((x==t.x)&&(y>t.y)));}
    inline bool operator>(const Point &t)const{return ((x>t.x)||((x==t.x)&&(y<t.y)));}
};
Point a[N];
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++){
        scanf("%d%d",&a[i].x,&a[i].y);
        a[i].y+=a[i].x-1;
        a[i].u=i;
        g[a[i].x].pb(+(i+1));
        g[a[i].y+1].pb(-(i+1));
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<g[i].size();j++)
            if (g[i][j]>0){
                s.insert(-a[g[i][j]-1].y);
                nom[a[g[i][j]-1].y]=a[g[i][j]-1].u;
            }
            else s.erase(s.find(-a[-(g[i][j]+1)].y));
        if ((!s.empty())&&(mt<i)){
            int t=-(*s.begin());
            mt=t;
            used[nom[t]]=1;
        }
    }
    int ct=0;
    for (int i=0;i<m;i++)ct+=1-used[i];
    printf("%d\n",ct);
    for (int i=0;i<m;i++)
        if (used[i]==0)printf("%d ",1+i);
    puts("");
}