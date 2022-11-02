#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <functional>
#include <list>
#include <queue>
#include <stack>
#include <iomanip>
#include <assert.h>

#define mp make_pair
#define pb push_back
#define N 500500

typedef long long ll;

using namespace std;

int a[N],n,x,y,used[N];
vector<int>g[N];
set<pair<int,int> >s;

int main(){
//    freopen("input","r",stdin);
//    freopen("output","w",stdout);
    scanf("%d",&n);
    for (int i=0;i<n+n;i++){
        scanf("%d%d",&x,&y);
        --x;--y;
        g[x].pb(y);
        g[y].pb(x);
        s.insert(mp(x,y));
        s.insert(mp(y,x));
    }
    for (int i=0;i<n;i++)
        if (g[i].size()!=4){
            puts("-1");
            return 0;
        }
    for (int i1=0;i1<4;i1++)for(int i2=0;i2<4;i2++)if (i1!=i2){
        memset(used,0,sizeof(used));
        a[0]=0;
        a[1]=g[0][i1];
        a[2]=g[0][i2];
        used[a[0]]=1;
        used[a[1]]=1;
        used[a[2]]=1;
        for (int j=3;j<n;j++){
            a[j]=-1;
            for (int t=0;t<4;t++)
                if ((s.find(mp(a[j-2],g[a[j-1]][t]))!=s.end())&&(!used[g[a[j-1]][t]])){
                    used[g[a[j-1]][t]]=1;
                    a[j]=g[a[j-1]][t];
                    break;
                }
            if (a[j]<0){
                a[0]=-1;
                break;
            }
        }
        if (a[0]<0)continue;
        for (int j=0;j<n;j++)printf("%d ",a[j]+1);
        puts("");
        return 0;
    }    
    puts("-1");
    return 0;
}