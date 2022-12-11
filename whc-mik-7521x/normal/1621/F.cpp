#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long t,n,a,b,c;
int p[N];
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld%lld%lld",&n,&a,&b,&c);
        vector<int>v;
        vector<int>u;
        vector<int>w;
        for(int i=1;i<=n;i++){
            scanf("%1d",&p[i]);
        }
        for(int i=1;i<=n;){
            v.push_back(p[i++]);
            int cnt=0;
            while(i<=n&&p[i]==v.back()){
                cnt++;
                i++;
            }
            u.push_back(cnt);
        }
        int cnt1=0,cnt2=0,cntt1=0,cntt2=0;
        for(int i=0;i<(int)v.size();i++){
            if(v[i]){
                cnt1++;
                cntt1+=u[i];
            }
            else{
                cnt2++;
                cntt2+=u[i];
                if(i!=0&&i!=(int)v.size()-1)w.push_back(u[i]);
            }
        }
        stable_sort(w.begin(),w.end());
        if(cntt1+cnt1==0){
            printf("%lld\n",cntt2?a:0ll);
            continue;
        }
        if(cntt1>cntt2){ 
            if(c>=b){
                printf("%lld\n",max(0ll,1ll*b*(cntt2+1)+1ll*a*cntt2));
            }
            else{
                int tot=min(cntt1+cnt1-1,cntt2+cnt2+1);
                printf("%lld\n",max(0ll,1ll*(tot)*b+1ll*(cntt2)*a-1ll*(tot-cntt2-1)*c));
            }
        }
        else if(cntt1==cntt2){
            if(c>=b){
                printf("%lld\n",max(0ll,1ll*b*cntt1+1ll*a*cntt1));
            }
            else{
                printf("%lld\n",max(0ll,1ll*b*(cntt1+cnt1-1)+1ll*a*cntt2-1ll*c*(cnt1-1)));
            }
        }
        else{
            if(c>=b){
                printf("%lld\n",max(0ll,1ll*b*cntt1+1ll*a*(1+cntt1)));
            }
            else{
                int now=cntt1,tot=0;
                for(int i=0;i<(int)w.size();i++){
                    if(w[i]<=now)tot++,now-=w[i];
                    else break;
                }
                printf("%lld\n",max(0ll,1ll*b*(cntt1+tot)+1ll*a*(1+cntt1)-1ll*c*tot));
            }
        }
    }
    return  0;
}