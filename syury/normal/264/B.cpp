#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int>a,ans;
int opt=1;

int main(){
    int ma=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d",&tmp);
        ma=max(tmp,ma);
        if(tmp!=1){a.push_back(tmp);}
    }
    ans.resize(ma+1);
    n=a.size();
    if(n<=1){printf("1");return 0;}
    for(int i=0;i<n;i++){
        vector<int>divs(1,a[i]);
        for(int j=2;j*j<=a[i];j++){
            if(a[i]%j!=0){continue;}
            divs.push_back(j);
            if(j*j!=a[i]){divs.push_back(a[i]/j);}
        }
        int cans=1;
        for(size_t j=0;j<divs.size();j++){
            cans=max(cans,1+ans[divs[j]]);
        }
        for(size_t j=0;j<divs.size();j++){
            ans[divs[j]]=max(ans[divs[j]],cans);
        }
        opt=max(cans,opt);
    }
    printf("%d",opt);
    return 0;
}