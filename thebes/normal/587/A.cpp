#include <bits/stdc++.h>
using namespace std;

const int MN = 1e6+40;
int n, i, x, ans;
bitset<MN> a;

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++){
        scanf("%d",&x); int j=x;
        while(a[j]){
            a[j].flip();
            j++;
        }
        a[j].flip();
    }
    for(i=0;i<MN;i++)
        if(a[i]) ans++;
    printf("%d\n",ans);
    return 0;
}