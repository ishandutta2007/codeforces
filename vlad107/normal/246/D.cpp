#include <stdio.h>
#include <algorithm>
#include <set>

#define N 200000

using namespace std;

int n,m,a[500500],max,nom;
set<int>g[500500];
bool used[500500];

int main(){
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
        used[a[i]]=1;
    }
    for (int i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        --x;--y;
        x=a[x];y=a[y];
        if (x==y)continue;
        g[x].insert(y);
        g[y].insert(x);
    }
    int max=-1;
    for (int i=1;i<=N;i++){
        if (!used[i])continue;
        int cr=g[i].size();
        if (cr>max){
            max=cr;
            nom=i;
        }
    }
    printf("%d\n",nom);
}