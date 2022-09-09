#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define mt make_tuple
#define ldb double
#define pii pair<int,int>
#define pll pair<ll,ll>
template<typename T>void ckmn(T &a,T b){a=min(a,b);}
template<typename T>void ckmx(T &a,T b){a=max(a,b);}
int ri(){int x;scanf("%i",&x);return x;}
void rd(){}
template<typename...T>void rd(int &x,T&...args){scanf("%i",&x);rd(args...);}
template<typename...T>void rd(ll &x,T&...args){scanf("%lld",&x);rd(args...);}
template<typename...T>void rd(ldb &x,T&...args){scanf("%lf",&x);rd(args...);}
template<typename...T>void rd(pii &x,T&...args){scanf("%i %i",&x.first,&x.second);rd(args...);}

ll Fir(int sum){
	ll ans=0;
	ans=sum%9;
	sum-=ans;
	while(sum>=9){
		ans=ans*10+9;
		sum-=9;
	}
	return ans;
}
ll IncMx(ll now){
	ll tmp=now,pw=1;
	while(tmp%10==9){
		tmp/=10;
		pw*=10;
	}
	return now+pw;
}
ll Dec(ll now,int cnt){
	int pw=1;
	while(cnt){
		cnt--;
		pw*=10;
	}
	return now-pw;
}
ll Build(int C,int D){
	ll now=Fir(C);
	D-=C+1;
	int cnt=0;
	while(D>=9){
		cnt++;
		D-=9;
	}
	now=IncMx(now);
	now=Dec(now,cnt);
	return now;
}
int main(){
	for(int t=ri();t--;){
		int n,k;rd(n,k);
		k++;
		ll ans=-1;
		auto chk=[&](ll x){
			if(ans==-1||ans>x)ans=x;
		};
		for(int las=0;las<=9;las++){
			if(las+k<=10){
				int sum_las=0;
				for(int i=las;i<las+k;i++)
					sum_las+=i;
				int ost=n-sum_las;
				if(ost>=0&&ost%k==0){
					chk(Fir(ost/k)*10+las);
				}
			}else{
				int A=10-las;
				int B=k-A;
				int sum_las=0;
				for(int i=las;i<las+k;i++)
					sum_las+=i%10;
				int ost=n-sum_las;
				for(int C=0;C<=ost;C++){
					for(int D=C+1;D>0;D-=9){
						if(A*C+B*D==ost){
							chk(Build(C,D)*10+las);
						}
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}