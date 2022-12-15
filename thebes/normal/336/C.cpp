#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
vector<int> vec[32];
int n, i, j, x;

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++){
        scanf("%d",&x);
        for(j=30;j>=0;j--)
            if((1<<j)&x) vec[j].push_back(x);
    }
    for(j=30;j>=0;j--){
        if(vec[j].empty()) continue;
        x = vec[j][0];
        for(auto v : vec[j]) x &= v;
        if((x&(-x))==(1<<j)){
            printf("%d\n",vec[j].size());
            for(auto v : vec[j]) printf("%d ",v);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}