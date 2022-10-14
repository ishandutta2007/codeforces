#include <bits/stdc++.h>
using namespace std;
const int N=100050;
int n,k,a[N];
int main(){
    scanf("%i%i",&n,&k);
    for(int i=1;i<=n;i++)scanf("%i",&a[i]);
    map<int,int> cnt;
    set<int> all;
    for(int i=1;i<=n;i++){
        if(i>k){
            if(cnt[a[i-k]]==1)all.erase(a[i-k]);
            if(cnt[a[i-k]]==2)all.insert(a[i-k]);
            cnt[a[i-k]]--;
        }
        if(cnt[a[i]]==0)all.insert(a[i]);
        if(cnt[a[i]]==1)all.erase(a[i]);
        cnt[a[i]]++;
        if(i>=k){
            if(all.empty())printf("Nothing\n");
            else printf("%i\n",*prev(all.end()));
        }
    }
    return 0;
}