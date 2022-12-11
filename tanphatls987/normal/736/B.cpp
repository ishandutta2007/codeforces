#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


bool isprime(int n){
    for(int i=2;i*i<=n;i++) if (n%i==0) return 0;
    return 1;
}
int solve(int n){
    if (isprime(n)) return 1;
    if (n%2==0) return 2;
    if (isprime(n-2)) return 2;
    return 3;
}

int main(){
    int n;
    scanf("%d",&n);
    cout<<solve(n);
}