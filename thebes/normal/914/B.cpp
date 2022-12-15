#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
bitset<MN> cnt;
int n, i, x, fnd;

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++){
        scanf("%d",&x);
        cnt[x].flip();
    }
    for(i=1;i<MN;i++){
        if(cnt[i]) fnd=1;
    }
    printf("%s\n",(fnd)?"Conan":"Agasa");
    return 0;
}