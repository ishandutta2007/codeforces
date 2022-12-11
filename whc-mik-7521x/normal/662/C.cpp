#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+10;
long long cnt[N],val[N],n,m,mp[21][100005];
template<class T,class Alloc>
vector<T,Alloc>operator+(vector<T,Alloc>v1,vector<T,Alloc>v2){
    vector<T,Alloc>res=v1;
    for(long long i=0;i<(long long)v1.size();i++)res[i]=res[i]+v2[i];
    return res;
}
template<class T,class Alloc>
vector<T,Alloc>operator*(vector<T,Alloc>v1,vector<T,Alloc>v2){
    vector<T,Alloc>res=v1;
    for(long long i=0;i<(long long)v1.size();i++)res[i]=res[i]*v2[i];
    return res;
}
template<class T,class Alloc>
vector<T,Alloc>operator-(vector<T,Alloc>v1,vector<T,Alloc>v2){
    vector<T,Alloc>res=v1;
    for(long long i=0;i<(long long)v1.size();i++)res[i]=res[i]-v2[i];
    return res;
}
template<class T>
class FMT{
    vector<T>merge(vector<T>v1,vector<T>v2){
        return v1.insert(v1.end(),v2.begin(),v2.end()),v1;
    }
    vector<T>divide2(vector<T>v1){
        for(long long i=0;i<(long long)v1.size();i++)v1[i]=v1[i]/2;
        return v1;
    }
    public:
    vector<T>multipl(vector<T>v1,vector<T>v2){
        return v1*v2;
    }
    vector<T>Xor_FMT(vector<T>tr){
        if(tr.size()==1)return tr;
        vector<T>v1=Xor_FMT(vector<T>(tr.begin(),tr.begin()+(tr.size()>>1))),v2=Xor_FMT(vector<T>(tr.begin()+(tr.size()>>1),tr.end()));
        return merge(v1+v2,v1-v2);
    }
    vector<T>Xor_IFMT(vector<T>tr){
        if(tr.size()==1)return tr;
        vector<T>v1=Xor_IFMT(vector<T>(tr.begin(),tr.begin()+(tr.size()>>1))),v2=Xor_IFMT(vector<T>(tr.begin()+(tr.size()>>1),tr.end()));
        return merge(divide2(v1+v2),divide2(v1-v2));
    }
};
FMT<long long>ty;
void init(){
    for(long long i=0;i<1<<(n);i++){
        val[i]=min(1ll*__builtin_popcount(i),n-__builtin_popcount(i));
    }
}
int main(){
    scanf("%lld%lld",&n,&m);
    init();
    for(long long i=1;i<=n;i++){
        for(long long o=1;o<=m;o++){
            scanf("%1lld",&mp[i][o]);
        }
    }
    for(long long i=1;i<=m;i++){
        long long now=0;
        for(long long o=1;o<=n;o++){
            now=(now<<1)|mp[o][i];
        }
        cnt[now]++;
    }
    vector<long long>v1,v2;
    for(long long i=0;i<1<<(n);i++){
        v1.push_back(cnt[i]);
        v2.push_back(val[i]);
    }
    v1=ty.Xor_IFMT(ty.Xor_FMT(v1)*ty.Xor_FMT(v2));
    long long ans=1e18;
    for(auto it:v1)ans=min(ans,it);
    printf("%lld",ans);
    return  0;
}