#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory.h>

#define MAXN 100500

std::vector<std::pair<int,int> >w;
bool so[MAXN],used[MAXN];
int g[MAXN],n,m;

int main(){
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    scanf("%d",&n);
    memset(so,true,sizeof(so));
    for (int i=0;i<n;i++){
        scanf("%d",&g[i]);
        --g[i];
        so[g[i]]=false;
    }
    memset(used,false,sizeof(used));
    int kq=0;
    for (int i=0;i<n;i++)
        if (so[i]){
            kq++;
            int j=i;
            while (!used[j]){
                used[j]=true;
                j=g[j];
            }
            w.push_back(std::make_pair(i,j));
        }
    for (int i=0;i<n;i++)
        if (!used[i]){
            int j=i;
            while (!used[j]){
                used[j]=true;
                j=g[j];
            }
            w.push_back(std::make_pair(i,i));
        }
    m=w.size();
    if (m==1&&kq==0)m=0;
    printf("%d\n",m);
    for (int i=0;i<m;i++)
        printf("%d %d\n",w[i].second+1,w[(i+1)%m].first+1);
}