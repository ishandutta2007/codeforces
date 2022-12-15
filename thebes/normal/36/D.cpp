#include <bits/stdc++.h>
using namespace std;

int t, k, i, x, y, r;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d",&t,&k);
    while(t--){
        scanf("%d%d",&x,&y); x--; y--;
        r = min(x/(k+1), y/(k+1));
        x -= r*(k+1); y -= r*(k+1);
        if(min(x,y)==k) printf("+\n");
        else printf("%c\n",((x+y+((r%2)&&k!=1)&1))?'+':'-');
    }
    return 0;
}