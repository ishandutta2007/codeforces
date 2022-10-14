#include <bits/stdc++.h>
using namespace std;
const int N=200050;
int a[N],b[N],ans[N];
multiset<int> s;
int main(){
    int n;
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&a[i]);
    for(int i=1;i<=n;i++)scanf("%i",&b[i]),s.insert(b[i]);
    for(int i=1;i<=n;i++){
        auto it=s.lower_bound(n-a[i]);
        if(it==s.end())it=s.begin();
        ans[i]=(a[i]+*it)%n;
        s.erase(it);
    }
    for(int i=1;i<=n;i++)printf("%i ",ans[i]);
    return 0;
}