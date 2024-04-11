#include <bits/stdc++.h>
using namespace std;
const int N=150050;
int a[N],b[N];
vector<int> all;
void FindDivs(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0)all.push_back(i);
        while(n%i==0)n/=i;
    }
    if(n!=1)all.push_back(n);
}
int main(){
    int n;scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i%i",&a[i],&b[i]);
    FindDivs(a[1]);
    FindDivs(b[1]);
    for(int x:all){
        bool ok=true;
        for(int i=1;i<=n;i++)if(a[i]%x!=0&&b[i]%x!=0)ok=false;
        if(ok)return 0*printf("%i",x);
    }
    printf("-1");
    return 0;
}