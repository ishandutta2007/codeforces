#include <bits/stdc++.h>
using namespace std;
set<int> primes;
map<int,int> primeNum;
bool isPrime[2000001];
int main(){
    int t; cin >> t;
    int a = 0;
    memset(isPrime,true,sizeof(isPrime));
    primes.insert(1);
    for(int i=2;i*i<=2000000;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=2000000;j+=i) isPrime[j] = false; 
        }
    }
    for(int p=1;p<=2000000;p++){
        if(isPrime[p]){
            primes.insert(p);
            primeNum[p] = ++a;
        }
    }
    while(t--){
        int x; scanf("%d",&x);
        int y = (int) ceil(sqrt(x)*1.0);
        auto begin = primes.lower_bound(y);
        auto end = primes.upper_bound(x);
        --end;
        int ans= primeNum[*end]+2-primeNum[*begin];
        if(primes.count(y) && y*y==x) --ans;
        printf("%d\n",ans);
    }
}