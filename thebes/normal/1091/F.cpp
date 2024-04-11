#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MN = 1e5+5;
ll n, len[MN], t[MN], i, sum[MN], sm[3], lst[MN], L=1, st, ans, idk;
char ch;

int main(){
    for(scanf("%lld",&n),i=1;i<=n;i++)
        scanf("%lld",&len[i]);
    for(getchar(),i=1;i<=n;i++){
        ch = getchar();
        if(ch=='L') t[i]=0;
        else if(ch=='G') t[i]=1;
        else t[i]=2;
    }
    for(i=n;i>=1;i--){
        for(int j=2;j>=t[i];j--) sm[j]+=len[i];
        if(t[i]==0||t[i]==1) idk+=len[i];
        else idk=max(0LL,idk-len[i]);
        sum[i]=sm[t[i]];
        if(t[i]==1) sum[i]=idk;
    }
    for(i=1;i<=n;i++){
        if(t[i]>t[L]) L=i;
        lst[i]=L;
    }
    for(i=1;i<=n;i++){
        if(t[i]==0){
            if(st>=len[i]) st-=len[i];
            else{
                if(t[lst[i]]==1) ans+=5*(len[i]-st);
                else ans+=3*(len[i]-st);
                st=0;
            }
            ans += len[i];
        }
        else{
            double x = (sum[i]-st)/2.0;
            x = max(0.0, x);
            if(x<=len[i]){
                st = st+2*x-len[i];
                if(t[i]==1) x=4*x+len[i];
                else x=2*x+len[i];
                ans += x;
            }
            else{
                if(t[i]==1) ans += len[i]*5;
                else ans += len[i]*3;
                st += len[i];
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}

/*
4
10 10 10 10
WGWG
*/