#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;

#define pb push_back

const int MN = 2e5+5;
int n, s, i, arr[MN], f, cnt[MN], ss[MN], j, ans=1<<30, hm, ok;

int main(){
    for(scanf("%d%d",&n,&s),i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    if(arr[s]!=0) hm=1;
    if(n==1){printf("%d\n",hm); return 0;}
    for(i=1;i<=n;i++){
        if(arr[i]==0&&i!=s) hm++, f++;
        if(i!=s) cnt[arr[i]]++;
    }
    for(i=n;i>=1;i--) ss[i]=cnt[i]+ss[i+1];
    for(i=1;i<=n-1;i++){
        int wat = ss[i+1];
        if(!cnt[i]) ok++;
        ans=min(ans,wat+max(0,ok-wat-f));
    }
    printf("%d\n",ans+hm);
    return 0;
}