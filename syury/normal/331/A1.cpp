#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long int lint;
int n;
vector<int>a;
lint opt;
int l,r;

int main(){
    scanf("%d",&n);
    a.resize(n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    opt=-3000000000ll;;
    for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
            if(a[i]!=a[j]){continue;}
            lint curr=a[i]+a[j];
            for(int k=i+1;k<j;k++){
                if(a[k]>=0){curr+=a[k];}
            }
            if(curr>opt){opt=curr;l=i;r=j;}
        }
    }
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(i==l || i==r){continue;}
        if(i<l || i>r || a[i]<0){ans.push_back(i+1);}
    }
    printf("%lld %d\n",opt,ans.size());
    for(size_t i=0;i<ans.size();i++){printf("%d ",ans[i]);}
    return 0;
}