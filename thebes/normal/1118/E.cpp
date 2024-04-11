#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
int n, k, i, j, x, y, cnt;
pair<int,int> p;

int main(){
    scanf("%d%d",&k,&n);
    if(1LL*n*(n-1)<k) printf("NO\n");
    else{
        printf("YES\n");
        for(i=1;i<=n;i++){
            for(j=i+1;j<=n;j++){
                p = {i, j}; cnt ++;
                if(p.first==x||p.second==y) swap(p.first,p.second);
                printf("%d %d\n",p.first,p.second);
                if(cnt==k) return 0;
                swap(p.first,p.second); cnt ++;
                printf("%d %d\n",p.first,p.second);
                x = p.first, y = p.second;
                if(cnt==k) return 0;
            }
        }
    }
    return 0;
}