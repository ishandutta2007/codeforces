#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const long long mod=1000000007;

char ch[100100];
int N,K;

long long ex(long long a,long long e){
	if(e==0) return 1;
	long long tmp=ex(a,e/2);
	tmp*=tmp;
	tmp%=mod;
	if(e%2==1) tmp*=a;
	tmp%=mod;
	return tmp;
}

long long inv(long long a){
	return ex(a,mod-2);
}

int main(){
	scanf("%s",ch);
	N=strlen(ch);
	scanf("%d",&K);
	long long num=ex(2,(long long)K*N)-1;
	long long den=ex(2,N)-1;
	long long coe=num*inv(den);
	coe%=mod;
	long long sum=0;
	for(int i=0;i<N;i++){
		if(ch[i]=='0'||ch[i]=='5'){
			sum+=ex(2,i);
			sum%=mod;
		}
	}
	long long ans=sum*coe;
	ans%=mod;
	ans+=mod;
	ans%=mod;
	printf("%d\n",(int)ans);
	return 0;
}