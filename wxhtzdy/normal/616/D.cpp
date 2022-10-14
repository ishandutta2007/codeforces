#include <bits/stdc++.h>
using namespace std;
const int N=500050;
int n,k,a[N];
int main(){
    scanf("%i %i",&n,&k);
    for(int i=1;i<=n;i++)scanf("%i",&a[i]);
    int j=0,tmp=0,l=0,r=0;
    map<int,int> cnt;
    for(int i=1;i<=n;i++){
        while(tmp<=k&&j<=n){
            j++;
            cnt[a[j]]++;
            if(cnt[a[j]]==1)tmp++;
        }
        if(j>n)j--;
        else if(tmp>k)tmp--,cnt[a[j]]--,j--;
        if(j-i>=r-l)l=i,r=j;
        if(cnt[a[i]]==1)tmp--;
        cnt[a[i]]--;
    }
    printf("%i %i",l,r);
    return 0;
}