#include<bits/stdc++.h>
using namespace std;
const long long N=1e3+10;
vector<long long>v;
vector<pair<long long,long long>>ope;
vector<long long>ans;
long long t,n,a[N],len;
void solve(int x){
    int kk=0;
    for(kk=0;kk<(int)v.size();kk++)if(v[kk]==x)break;
    for(int i=len+kk+1;i<len+kk+1+kk+1;i++){
        ope.push_back({i,v[i-(len+kk+1)]});
    }
    len+=(kk+1)*2;
    ans.push_back((kk+1)*2);
    reverse(v.begin(),v.begin()+kk+1);
    v.push_back(x);
    for(long long i=len+v.size();i<(long long)(len+v.size()+v.size()-2ll);i++){
        ope.push_back({i,v[i-len-v.size()+1ll]});
    }
    ans.push_back((v.size()-1ll)*2ll);
    len+=(v.size()-1ll)*2ll;
    v.erase(--v.end());
    v.erase(v.begin());
    reverse(v.begin(),v.end());
}
int main(){
    scanf("%lld",&t);
    while(t--){
        v.clear();
        ope.clear();
        ans.clear();
        len=0;
        scanf("%lld",&n);
        for(long long i=1ll;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        set<long long>st;
        for(long long i=1ll;i<=n;i++){
            if(st.find(a[i])!=st.end())solve(a[i]),st.erase(a[i]);
            else v.push_back(a[i]),st.insert(a[i]);
        }
        if(v.size()){
            puts("-1");
        }
        else{
            printf("%lld\n",(long long)ope.size());
            for(auto it:ope){
                printf("%lld %lld\n",it.first,it.second);
            }
            printf("%lld\n",(long long)ans.size());
            for(long long i:ans)printf("%lld ",i);
            puts("");
        }
    }
    return  0;
}