#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=5000005,M=300005,P=1e9+7;

int fpow(int a,ll t){
	static int r;
	for(r=1;t;t>>=1,a=(ll)a*a%P)if(t&1)r=(ll)r*a%P;
	return r;
}

int sum[N],inv[N];
void shaker(){
	static const int K=666666;
	static bool fl[N];
	static int pri[K],pc;
	sum[1]=inv[1]=1;
	for(int i=2;i<N;i++){
		if(!fl[i])sum[i]=i-1,pri[++pc]=i;
		for(int j=1;i*pri[j]<N;j++){
			fl[i*pri[j]]=true;
			if(i%pri[j]==0){sum[i*pri[j]]=sum[i]*pri[j];break;}
			sum[i*pri[j]]=sum[i]*(pri[j]-1); 
		}
		inv[i]=P-(ll)(P/i)*inv[P%i]%P;
	}
	for(int i=1;i<N;i++)(sum[i]+=sum[i-1])%=P;
}

ll n;
int fphi(ll m){
	static int f[2005];static bool vi[2005];
	if(m<N)return sum[m];
	if(vi[m])return f[m];
	int s=(m%P)*(m%P+1)%P*(P/2+1)%P;
	for(ll i=1,j;i<=m;i=j+1)j=m/(m/i),s=(s-m/i%P*(fphi(j)-fphi(i-1)))%P;
	return vi[m]=true,f[m]=(s+P)%P;
}
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int calc(){
	int s=2-fpow(2,n+1);
	for(ll i=1,j;i<=n;i=j+1)j=n/(n/i),s=(s+(ll)(fpow(2,j+2)-fpow(2,i+1))*fphi(n/i))%P;
	return (s+P)%P;
}
int chk(int a,int b){
	if(a<0&&b<0)a=-a,b=-b;
	if(a<0||b<0||(!a^!b))return 0;
	assert(a>0&&b>0);
	return fpow(2,n/(max(a,b)/gcd(a,b))+1)-2;
}

char s0[M],s1[M];
int c0a,c0b,c0c,c1a,c1b,c1c,m0,m1,ans;

int main(){
	scanf("%s%s%lld",s0,s1,&n);
	m0=strlen(s0);m1=strlen(s1);
	for(int i=0;i<m0;i++)
		if(s0[i]=='A')c0a++;else if(s0[i]=='B')c0b++;else c0c++;
	for(int i=0;i<m1;i++)
		if(s1[i]=='A')c1a++;else if(s1[i]=='B')c1b++;else c1c++;
	shaker();
	for(int i=-c1c,s=1;i<=c0c;i++){
		int a=c0a-c1a+i;
		int b=c1b-c0b+(c1c-c0c+i);
		if(a==0&&b==0){
			int now=calc();
			ans=(ans+(ll)s*now)%P;
			if(m0==m1){
				int w=1;
				for(int j=0;j<m0;j++){
					if(s0[j]=='A'&&s1[j]=='B'){w=0;break;}
					if(s1[j]=='A'&&s0[j]=='B'){w=0;break;}
					if(s0[j]=='?'&&s1[j]=='?')w=(w<<1)%P;
				}
				if(w){
					int t=fpow(2,n+1)-2;
					ans=(ans+w*((ll)t*t%P-now))%P;
				}
			}
		}else ans=(ans+(ll)s*chk(a,b))%P;
		s=(ll)s*inv[c1c+i+1]%P*(c0c-i)%P;
	}
	printf("%d\n",(ans+P)%P);
	return 0;
}