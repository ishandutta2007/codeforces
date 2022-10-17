#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 10000005;
int prime[maxn],np[maxn],a[maxn],ans[maxn],tot=0;
void init() {
   a[1]=np[1]=1;
   for(int i=2;i<maxn;++i) {
       if(!np[i]) prime[++tot] = i, a[i] = i+1;
       for(int j=1;j<=tot;++j) {
           if(i*prime[j]>=maxn) break;
           a[i*prime[j]] = a[i] * (1+prime[j]);
           np[i*prime[j]] = 1;
           if(i%prime[j]==0) {
               int cnt = 0;
               int x = i;
               while(x % prime[j] == 0) x /= prime[j], ++cnt;
               ll s=0,c=1;
               for(int k=0;k<=cnt;++k) s+=c,c*=prime[j];
               a[i*prime[j]] = a[i] / s * (s+c);
               break;
           }
       }
   }
   ans[1]=1;
   for(int i=2;i<maxn;++i) {
       if(a[i]<=10000000 && ans[a[i]]==-1) {
           ans[a[i]]=i;
       }
   }
}

int main() {
    memset(ans,-1,sizeof(ans));
    init();
    int t;
    cin>>t;
    while(t--) {
        int x;
        cin>>x;
        cout<<ans[x]<<endl;
    }
}