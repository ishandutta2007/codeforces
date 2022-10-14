#include <bits/stdc++.h>
using namespace std;
int dist(int n,int m,int a,int b){
    return abs(n-a)+abs(m-b);
}
int main(){
    int tt=1;scanf("%i",&tt);
    while(tt--){
        int n,m,a,b;scanf("%i%i%i%i",&n,&m,&a,&b);
        printf("%i\n",max({dist(n,m,a,b),dist(1,m,a,b),dist(n,1,a,b),dist(1,1,a,b)}));
    }
    return 0;
}