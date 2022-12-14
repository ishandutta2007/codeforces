#include<cstdio>
#include<utility>
#include<algorithm>

using namespace std;

const long long mod=1000000007;

typedef pair<int,int> P;

int H,W,N;
P ps[2020];

long long dp[2020];

long long fact[200200];
long long ifact[200200];

long long ex(long long a,long long e){
	if(e==0) return 1;
	long long res=ex(a,e/2);
	res*=res;
	res%=mod;
	if(e%2==1) res*=a;
	res%=mod;
	return res;
}

long long inv(long long a){
	return ex(a,mod-2);
}

long long C(int h,int w){
	if(h<0||w<0) return 0;
	long long res=fact[h+w];
	res*=ifact[h];
	res%=mod;
	res*=ifact[w];
	res%=mod;
	return res;
}

long long solve(){
	ps[N]=P(H,W);
	N++;
	sort(ps,ps+N);
	for(int i=0;i<N;i++){
		dp[i]=C(ps[i].first,ps[i].second);
		for(int j=0;j<i;j++){
			int h=ps[i].first-ps[j].first;
			int w=ps[i].second-ps[j].second;
			long long tmp=C(h,w);
			tmp*=dp[j];
			tmp%=mod;
			dp[i]-=tmp;
			dp[i]%=mod;
		}
	}
	dp[N-1]+=mod;
	dp[N-1]%=mod;
	return dp[N-1];
}

int main(){
	scanf("%d%d%d",&H,&W,&N);
	H--;W--;
	for(int i=0;i<N;i++){
		int h,w;
		scanf("%d%d",&h,&w);
		h--;w--;
		ps[i]=P(h,w);
	}
	fact[0]=1;
	ifact[0]=1;
	for(int i=1;i<200200;i++){
		fact[i]=fact[i-1]*i;
		fact[i]%=mod;
		ifact[i]=inv(fact[i]);
	}
	long long ans=solve();
	printf("%d\n",(int)ans);
	return 0;
}