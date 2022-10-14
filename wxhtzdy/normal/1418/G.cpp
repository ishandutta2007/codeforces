#include <bits/stdc++.h>
using namespace std;
const int N=500050;
const int K=65;
int n,a[N];
map<int,vector<int>> hsh;
mt19937 rng(189312);
vector<int> ggen(){
        vector<int> ret(K);
        for(int i=0;i<K;i++)ret[i]=rng()%3;
        return ret;
}
vector<int> xx(vector<int> a,vector<int> b) {
        vector<int> ret(K);
        for(int i=0;i<K;i++)ret[i]=(a[i]+b[i])%3;
        return ret;
}
vector<int> pref[N];
map<int,vector<int>> occ;
int main(){
        scanf("%i",&n);
        for(int i=1;i<=n;i++)scanf("%i",&a[i]),hsh[a[i]]=ggen();
        pref[0].resize(K);
        pref[0]=ggen();
        for(int i=1;i<=n;i++)pref[i]=xx(pref[i-1],hsh[a[i]]);
        map<vector<int>,int> cnt;
        cnt[pref[0]]++;
        long long ans=0;
        int ptr=0;
        for(int i=1;i<=n;i++){
                occ[a[i]].push_back(i);
                int pos=-1;
                if(occ[a[i]].size()>=4)pos=occ[a[i]][occ[a[i]].size()-4];
                while(ptr<pos)cnt[pref[ptr]]--,ptr++;
                ans+=cnt[pref[i]];
                cnt[pref[i]]++;
        }
        printf("%lld",ans);
        return 0;
}