#include<bits/stdc++.h>
using namespace std;

const int maxn=500007;
int t,n;
int a[maxn];
int res[maxn];
set<pair<int,int>> s;
set<int> rem;
int main(){
    scanf("%d",&t);
    while (t--){
        s.clear(), rem.clear();
        scanf("%d",&n);
        rem.insert(n+1);
        for (int i=1;i<=n;++i) scanf("%d",&a[i]);
        for (int i=1;i<=n;++i) if (a[i]<0) a[i]=i+1;
        for (int i=1;i<=n;++i) s.insert({-a[i],i});
        for (int i=1;i<=n;++i){
            pair<int,int> w=*s.begin();
            s.erase(w);
            res[w.second]=n-i+1;
            rem.insert(w.second);
            if (*rem.upper_bound(w.second)<-w.first){
                puts("-1");
                goto cont;
            }
        }
        for (int i=1;i<=n;++i) printf("%d ",res[i]);
        puts(" ");
        cont:;
    }
    return 0;
}