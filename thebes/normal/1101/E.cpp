#include <bits/stdc++.h>
using namespace std;

int n, i, x, y, X, Y;
char ch;

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++){
        scanf(" %c%d%d",&ch,&x,&y);
        if(ch=='+'){
            if(x>y) swap(x,y);
            X = max(X, x);
            Y = max(Y, y);
        }
        else{
            if(x>y) swap(x,y);
            printf("%s\n",(x>=X&&y>=Y)?"YES":"NO");
        }
    }
    return 0;
}