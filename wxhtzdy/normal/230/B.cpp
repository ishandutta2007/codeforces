#include<bits/stdc++.h>
using namespace std;
#define pb push_back
long long n,x;
int main(){
    int N=1000000;
    bool prime[N+1];
    for(int i=0;i<N;i++)prime[i]=1;
    prime[0]=prime[1]=0;
    vector<long long> v;
    for(long long i=2;i<=N;i++){
        if(prime[i]==0)continue;
        v.pb(i);
        for(int j=i+i;j<=N;j+=i)prime[j]=0;
    }
    scanf("%lld",&n);
    while(n--){
        scanf("%lld",&x);
        if((long long)sqrt(x)*(long long)sqrt(x)!=x || !prime[(int)sqrt(x)]){printf("NO\n");continue;}
        else printf("YES\n");
        /*int cnt=0;
        for(auto c:v){
            if(c>sqrt(x))break;
            if(x%c==0&&x!=c)cnt++;
            if(x%c==0&&x/c!=c)cnt=2;
            if(cnt>=2)break;
        }

        if(cnt==1)printf("YES\n");
        else printf("NO\n");*/
    }
}