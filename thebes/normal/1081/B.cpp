#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
int arr[MN], n, i, ans[MN], x, nxt;
vector<int> id[MN];

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++){
        scanf("%d",&x);
        id[n-x].push_back(i);
    }
    for(i=1;i<=n;i++){
        if(id[i].size()%i){
            printf("Impossible\n");
            return 0;
        }
        int wtf = 0;
        while(id[i].size()){
            ++nxt;
            for(int j=wtf*i;j<wtf*i+i;j++)
                ans[id[i][j]]=nxt;
            wtf++;
            if(wtf*i==id[i].size()) break;
        }
    }
    printf("Possible\n");
    for(i=1;i<=n;i++)
        printf("%d ",ans[i]);
    return 0;
}