#include <bits/stdc++.h>
using namespace std;
const int N=5050;
int a[N];
int Solve(int l,int r,int k){
	if(l>r)return 0;
    int mn=l;
    for(int i=l;i<=r;i++)if(a[i]<a[mn])mn=i;
    return min(r-l+1,a[mn]-k+Solve(l,mn-1,a[mn])+Solve(mn+1,r,a[mn]));
}
int main(){
    int n;scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&a[i]);
    printf("%i",Solve(1,n,0));
    return 0;
}