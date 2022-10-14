#include <bits/stdc++.h>
using namespace std;
const int N=1000050;
int main(){
    int k;scanf("%i",&k);
    char s[N];scanf("%s",&s);
    int n=strlen(s);
    if(k==0){
        long long ans=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0')cnt++;
            else{
                if(cnt!=0)ans+=(long long)cnt*(cnt+1)/2;
                cnt=0;
            }
        }
        if(cnt!=0)ans+=(long long)cnt*(cnt+1)/2;
        printf("%lld",ans);
        return 0;
    }
    int id=-1;
    map<int,int> lst,nxt;
    for(int i=0;i<n;i++){
        if(s[i]=='1')lst[i]=i-id,id=i;
    }
    id=n;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='1')nxt[i]=id-i,id=i;
    }
    //for(int i=0;i<n;i++)printf("%i %i\n",lst[i],nxt[i]);
    vector<int> one;
    for(int i=0;i<n;i++)if(s[i]=='1')one.push_back(i);
    long long ans=0;
    for(int i=0;i<(int)one.size()-k+1;i++){
        ans+=(long long)lst[one[i]]*nxt[one[i+k-1]];
    }
    printf("%lld",ans);
    return 0;
}