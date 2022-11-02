#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<utility>

using namespace std;

int n;
vector<long long int>s;
map<int,int>lmap,rmap;
vector<int>a;
long long int opt=-3000000000ll;
int l,r;

long long int sum(int l,int r){
    if(l>r){return 0ll;}
    return (l==0)? s[r] : s[r]-s[l-1];
}

int main(){
    scanf("%d",&n);
    a.resize(n);s.resize(n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        s[i]=(i==0)? 0 : s[i-1];
        s[i]+=(a[i]<0)? 0 : a[i];
        if(!lmap.count(a[i])){lmap.insert(make_pair(a[i],i));rmap.insert(make_pair(a[i],i));}
        rmap[a[i]]=i;
    }
    for(int i=0;i<n;i++){
        int cl=lmap[a[i]],cr=rmap[a[i]];
        if(cl==cr){continue;}
        long long int curr=a[i]+a[i]+sum(cl+1,cr-1);
        if(opt<curr){opt=curr;l=cl;r=cr;}
    }
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(i==l || i==r){continue;}
        if(i<l || i>r || a[i]<0){ans.push_back(i+1);}
    }
    printf("%I64d %d\n",opt,ans.size());
    for(size_t i=0;i<ans.size();i++){printf("%d ",ans[i]);}
    return 0;
}