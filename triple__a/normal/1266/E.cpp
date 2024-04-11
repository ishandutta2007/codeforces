#include<bits/stdc++.h>
using namespace std;
 
const int maxn=200007;
int n,q;
int a[maxn],bonus[maxn];
map<pair<int,int>,int> mp;
long long ans=0;
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i) scanf("%d",&a[i]), ans+=a[i];
    scanf("%d",&q);
    while (q--){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        if (mp.find({u,v})==mp.end()){
            if (bonus[w]<a[w]) ans--;
            bonus[w]++;
            mp.insert({{u,v},w});
        }
        else{
            bonus[mp[{u,v}]]--;
            if (bonus[mp[{u,v}]]<a[mp[{u,v}]]) ans++;
            mp.erase({u,v});
            if (w){
                mp.insert({{u,v},w});
                if (bonus[w]<a[w]) ans--;
                bonus[w]++;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}