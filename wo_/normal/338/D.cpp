#include<cstdio>
#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<long long,long long> P;

long long extgcd(long long a,long long b,long long &x,long long &y){
	if(a<b){
		return extgcd(b,a,y,x);
	}
	if(b!=0){
		long long d=extgcd(b,a%b,y,x);
		y-=(a/b)*x;
		return d;
	}else{
		x=1;
		y=0;
		return a;
	}
}

long long chinese_(long long p,long long q,long long k){
	//x = 0 mod p
	//x = k mod q
	long long a,b;
	long long d=extgcd(p,q,a,b);
	/*
	ap+bq=d
	a'p+b'q=k
	a'p=k-b'q
	x=a'p*/
	if(k%d!=0) return -1;
	long long coe=k/d;
	a*=coe;
	b*=coe;
	long long res=a*p;
	long long lcm=p/d*q;
	res%=lcm;
	if(res<0) res+=lcm;
	return res;
}
/*
long long chinese(long long p,long long a,long long q,long long b){
	//x = a mod p
	//x = b mod q
	a%=p;
	if(a<0) a+=p;
	b%=q;
	if(b<0) b+=q;
	if(a>=b){
		long long tmp=chinese_(q,p,a-b);
		if(tmp==-1) return -1;
		tmp+=b;
		long long x,y;
		long long d=extgcd(p,q,x,y);
		long long lcm=p/d*q;
		tmp%=lcm;
		return tmp;
	}else{
		return chinese(q,b,p,a);
	}
}*/

P chinese(long long p,long long a,long long q,long long b){
	//x = a mod p
	//x = b mod q
	a%=p;
	if(a<0) a+=p;
	b%=q;
	if(b<0) b+=q;
	if(a>=b){
		long long tmp=chinese_(q,p,a-b);
		if(tmp==-1) return P(-1,-1);
		tmp+=b;
		long long x,y;
		long long d=extgcd(p,q,x,y);
		long long lcm=p/d*q;
		tmp%=lcm;
		return P(lcm,tmp);
	}else{
		return chinese(q,b,p,a);
	}
}

long long lcm(long long a,long long b){
	long long x,y;
	long long d=extgcd(a,b,x,y);
	return a/d*b;
}

long long a[10100];
int N;
int e[10100];
long long tmp[10100];

P check(long long p){
	for(int i=0;i<N;i++) tmp[i]=a[i];
	int Ma=-1,id=-1;
	for(int i=0;i<N;i++){
		e[i]=0;
		while(tmp[i]%p==0){
			tmp[i]/=p;
			e[i]++;
		}
		if(e[i]>Ma){
			Ma=e[i];
			id=i;
		}
	}
	long long pm=1;
	for(int i=0;i<Ma;i++) pm*=p;
	for(int i=0;i<N;i++){
		if(i==id) continue;
		int cur=i-id;
		int cnt=0;
		while(cur%p==0){
			cur/=p;
			cnt++;
		}
		if(cnt!=e[i]&&(!(cnt>=Ma&&e[i]==Ma))){
			return P(-1,-1);
		}
	}
	return P(pm,N-1-id);
}

long long R,C;

vector<long long> ps;

void answer(bool flg){
	if(flg) cout<<"YES\n";
	else cout<<"NO\n";
	exit(0);
}

int main(){
	cin>>R>>C;
	cin>>N;
	long long l=1;
	for(int i=0;i<N;i++){
		cin>>a[i];
		long long x,y;
		long long d=extgcd(l,a[i],x,y);
		long long m=a[i]/d;
		if(l>R/m){
			cout<<"NO\n";
			return 0;
		}
		l*=m;
		if(l>R){
			cout<<"NO\n";
			return 0;
		}
	}
	long long tmp=l;
	for(long long i=2;i*i<=l;i++){
		if(tmp%i==0){
			ps.push_back(i);
			while(tmp%i==0){
				tmp/=i;
			}
		}
	}
	if(tmp!=1){
		ps.push_back(tmp);
	}
	if(ps.size()==0){
		//all 1
		if(N<=C){
			answer(true);
		}else{
			answer(false);
		}
	}
	P req=check(ps[0]);
	if(req.first==-1) answer(false);
	for(int i=1;i<ps.size();i++){
		P req2=check(ps[i]);
		if(req2.first==-1) answer(false);
		P nreq=chinese(req.first,req.second,req2.first,req2.second);
		req=nreq;
	}
	long long a=req.first,b=req.second;
	long long cur=b;
	while(true){
		if(b>=N&&b<=C) answer(true);
		if(b>C) break;
		b+=a;
	}
	answer(false);
	return 0;
}