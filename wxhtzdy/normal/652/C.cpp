#include <bits/stdc++.h>
using namespace std;
const int N=300050;
int n,m,a[N],pos[N];
vector<int> all[N];
int main(){
    scanf("%i%i",&n,&m);
    for(int i=1;i<=n;i++)scanf("%i",&a[i]),pos[a[i]]=i;
    while(m--){
        int l,r;scanf("%i%i",&l,&r);
        l=pos[l],r=pos[r];
        if(l>r)swap(l,r);
        all[l].push_back(r);
    }
    int j=n+1;
    long long ans=0;
    for(int i=n;i>=1;i--){
        for(int c:all[i])j=min(j,c);
        ans+=j-i;
    }
    printf("%lld",ans);
    return 0;
}