#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,mod=998244353;
int n,s,a[N],b[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&s);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)scanf("%d",&b[i]);
        long long ans=1;
        for(int i=1;i<=n;i++)if(b[i]!=-1&&a[i]-b[i]>s)ans=0;
        set<int>st;
        for(int i=1;i<=n;i++)st.insert(i);
        for(int i=1;i<=n;i++)if(b[i]!=-1)st.erase(b[i]);
        vector<int>vec,now(st.begin(),st.end());
        for(int i=1;i<=n;i++)if(b[i]==-1)vec.push_back(a[i]-s);
        stable_sort(vec.begin(),vec.end());
        int cnt=0;
        while(vec.size()){
            (ans*=now.end()-lower_bound(now.begin(),now.end(),vec.back())-cnt)%=mod;
            cnt++;
            vec.pop_back();
        }
        printf("%lld\n",ans);
    }
    return  0;
}