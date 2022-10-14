#include <bits/stdc++.h>
using namespace std;
const int N=1000050;
int n,m,a[N],b[N];
map<int,int> cnt;
int bit[31];
void Add(int val){
    for(int i=0;i<=30;i++)if(val&(1<<i))bit[i]++;
}
bool Get(int x){
    if(x>30)return false;
    if(bit[x]>0){
        bit[x]--;
        return true;
    }
    if(Get(x+1)){
        bit[x]++;
        return true;
    }
    return false;
}
int main(){
    scanf("%i %i",&n,&m);
    for(int i=0;i<n;i++)scanf("%i",&a[i]),Add(a[i]);
    for(int i=0;i<m;i++)scanf("%i",&b[i]),++cnt[b[i]];
    int ans=0;
    for(int i=0;i<=30;i++)while(cnt[i]--)ans+=Get(i)==true;
    printf("%i",ans);
    return 0;
}