#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
long long t,n,x,a[N];
signed main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&x);
        multiset<long long>st;
        for(long long i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            st.insert(a[i]);
        }
        long long ans=n;
        while(st.size()){
            long long now=*st.begin();
            if(st.find(now*x)!=st.end())st.erase(st.find(now*x)),ans-=2;
            st.erase(st.begin());
        }
        printf("%lld\n",ans);
    }
    return  0;
}