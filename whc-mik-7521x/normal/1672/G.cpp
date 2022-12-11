#include<bits/stdc++.h>
using namespace std;
const long long N=4e3+10,mod=998244353;
long long r,c,mp[N][N],w[N<<1];
vector<long long>al[N<<1];
long long fp(long long x,long long y){
	long long res=1;
	while(y)res=(y&1)?res*x%mod:res,x=x*x%mod,y>>=1;
	return res;
}
long long ct,val,deg;
long long vis[N<<1];
void dfs(long long i){
	if (vis[i])return;
	vis[i]=1;
	ct++;
	val^=w[i];
	deg+=al[i].size();
	for(auto it:al[i])dfs(it);
}
int main(){
    scanf("%lld%lld",&r,&c);
    for(long long i=1;i<=r;i++){
        char s[N];
        scanf("%s",s+1);
        for(long long o=1;o<=c;o++){
            mp[i][o]=(s[o]=='0'?0:s[o]=='1'?1:2);
        }
    }
	if(!(r%2)&&!(c%2)){
		long long cal=0;
		for(long long i=1;i<=r;i++){
			for(long long o=1;o<=c;o++){
				cal+=mp[i][o]==2;
			}
		}
		printf("%lld\n",fp(2,cal));
	}
	else if((r%2)&&!(c%2)){
		long long ans1=1,ans0=1;
		for(long long o=1;o<=c;o++){
			long long val=0,cal=0;
			for(long long i=1;i<=r;i++){
				mp[i][o]<2?val^=mp[i][o]:cal++;
			}
			if(cal==0)val?ans1=0:ans0=0;
			else ans0=ans0*fp(2,cal-1)%mod,ans1=ans1*fp(2,cal-1)%mod;
		}
		printf("%lld",(ans0+ans1)%mod);
	}
	else if(!(r%2)&&(c%2)){
		long long ans1=1,ans0=1;
		for(long long i=1;i<=r;i++){
			long long val=0,cal=0;
			for(long long o=1;o<=c;o++){
				mp[i][o]<2?val^=mp[i][o]:cal++;
			}
			if(cal==0)val?ans1=0:ans0=0;
			else ans0=ans0*fp(2,cal-1)%mod,ans1=ans1*fp(2,cal-1)%mod;
		}
		printf("%lld",(ans0+ans1)%mod);
	}
	else{
		for(long long i=1;i<=r;i++)
		for(long long o=1;o<=c;o++){
			if (mp[i][o]!=2){
				w[i]^=mp[i][o];
				w[o+r]^=mp[i][o];
			}
			else{
				al[i].push_back(o+r);
				al[o+r].push_back(i);
			}
		}
		long long ans0=1,ans1=1;
		for(long long i=1;i<=r+c;i++)if(!vis[i]){
			ct=0,val=0,deg=0;
			dfs(i);
			deg/=2;
			deg-=ct-1;
			long long mul=fp(2,deg);
			if(ct%2==0){
				if(val)mul=0;
				ans0=(ans0*mul)%mod;
				ans1=(ans1*mul)%mod;
			}
			else{
				if(val==0) ans0=(ans0*mul)%mod,ans1=0;
				else ans0=0,ans1=(ans1*mul)%mod;
			}
		}
		printf("%lld",(ans0+ans1)%mod);
	}
    return  0;
}