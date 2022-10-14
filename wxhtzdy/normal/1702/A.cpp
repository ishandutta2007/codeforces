#include <bits/stdc++.h>
using namespace std;
int main(){
        int t;scanf("%i",&t);
        while(t--){
                int n;scanf("%i",&n);
                int m=1;
                while(m<1e9&&m*10<=n)m*=10;
                printf("%i\n",n-m);
        }
}