#include <bits/stdc++.h>
using namespace std;
const int N=100050;
int BIT[N];
void Add(int i,int x){for(;i<N;i+=i&-i)BIT[i]=max(BIT[i],x);}
int Get(int i){int res=0;for(;i>0;i-=i&-i)res=max(res,BIT[i]);return res;}
int main(){
    int n;
    scanf("%i",&n);
    int a[n];
    for(int i=0;i<n;i++)scanf("%i",&a[i]),Add(a[i],Get(a[i])+1);
    printf("%i",Get(n));
    return 0;
}