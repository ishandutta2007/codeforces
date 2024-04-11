#include <bits/stdc++.h>
using namespace std;
mt19937 rng(time(0));
long long BruteForce(string s,int p,int k,int x,int y){
    long long n=(int)s.length();
    long long ans=1e9;
    for(int i=0;i<n;i++){
        long long tmp=i*y;
        for(int j=i+p-1;j<n;j+=k)tmp+=(s[j]=='0')*x;
        ans=min(ans,tmp);
    }
    return ans;
}
int main(){
    int tt=1;scanf("%i",&tt);
    while(tt--){
        int n,p,k;cin>>n>>p>>k;//n=rng()%100000;p=rng()%100000,k=rng()%100000;//scanf("%i%i%i",&n,&p,&k);
        /*while(p==0)p=rng()%100000;
        while(k==0)k=rng()%100000;
        while(n==0)n=rng()%100000;*/
        string s;cin>>s;
        for(int i=0;i<n;i++){
            int rr=rng()%2;
            if(rr==0)s+='0';
            else s+='1';
        }
        long long x,y;cin>>x>>y;//x=rng()%10000;y=rng()%10000;//scanf("%lld%lld",&x,&y);
        //while(x==0)x=rng()%10000;
        //while(y==0)y=rng()%10000;
        long long pref[n];
        for(int i=0;i<n;i++)pref[i]=0;
        for(int i=n-1;i>=0;i--){
            if((i+k)<=(n-1))pref[i]=pref[i+k];//+(long long)(s[i]=='0')*x;
            //else pref[i]=(s[i]=='0')*x;
            if(s[i]=='0')pref[i]+=x;
        }
        long long ans=1e18;
        for(int i=0;i<n;i++){
            if((i+p)<=n)ans=min(ans,(long long)i*y+pref[i+p-1]);
            //else ans=min(ans,(long long)i*y);
        }
        //long long bans=BruteForce(s,p,k,x,y);
        /*if(bans!=ans){for(int j=0;j<100;j++)printf("WA\n");
            printf("%i %i %i\n",n,p,k);
            cout<<s<<'\n';
            printf("%i ",x);
            printf("%i\n",y);
            printf("aaaa: %lld %lld\n",ans,bans);
        }*/
        //printf("%lld\n",ans);
        cout<<ans<<'\n';
    }
    return 0;
}