#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200050;
int a[N],b[N],pref[N];
vector<int> all[N];
int main(){
    int t;scanf("%i",&t);
    while(t--){
        int n;scanf("%i",&n);
        for(int i=0;i<n;i++)all[i].clear();
        for(int i=1;i<=n;i++)scanf("%i%i",&a[i],&b[i]),all[a[i]].push_back(b[i]);
        pref[0]=(int)all[0].size();
        for(int i=1;i<n;i++)pref[i]=pref[i-1]+(int)all[i].size();
        multiset<int> val;
        ll ans=0;
        int cnt=0;
        for(int i=n-1;i>0;i--){
            for(int j:all[i])val.insert(j);
            while(pref[i-1]+cnt<i){
                cnt++;
                ans+=*val.begin();
                val.erase(val.begin());
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}