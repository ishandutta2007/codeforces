#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100050;
int a[N];
struct Fenwick{
    ll bit[N];
    void Add(int i,ll x){for(;i<N;i+=i&-i)bit[i]+=x;}
    ll Get(int i){ll res=0;for(;i;i-=i&-i)res+=bit[i];return res;}
}BIT[11];
int main(){
    int n,k;scanf("%i%i",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%i",&a[i]);
        for(int j=k;j>0;j--){
            BIT[j].Add(a[i],BIT[j-1].Get(a[i]-1));
        }
        BIT[0].Add(a[i],1);
    }
    printf("%lld",BIT[k].Get(N-1));
    return 0;
}