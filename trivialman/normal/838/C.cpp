#include<iostream>
#include<cstdio>
#include<cmath>
#include<string.h>
using namespace std;

//fnk0 n/2k-7  
long n,k,p,bobwin;
long f[250010][30]; 
long long fac[250010], inversefac[250010];

long power(long x, long y, long p);
long F(long n,long k,long p);
void lists(long a[], long i, long num, long n, long k, long p);

void inverse(long a,long b,long long& x,long long& y){
	if(a==1){
		y = 0; x = 1;
		return;
	}
	else if(b==1){
		x = 1; y = a-1;
		return;
	}
	if(a>b){
		long r = a%b, k = a/b;
		inverse(r,b,x,y);
		long long x1 = x, y1 = k*x + y;
		x = x1; y = y1;
	}
	else{
		long r = b%a, k = b/a;
		//cout<<a<<" "<<r<<" "<<x<<" "<<y<<endl;
		inverse(a,r,x,y);
		long long x1 = k*y + x, y1 = y;
		x = x1; y = y1;
	}
	return;
}

long long C(long long n, long long m, long long p){
	//cout<<fac[n]<<" "<<inversefac[n]<<" "<<(fac[n]*inversefac[n])%p<<endl;
	//cout<<"C("<<n<<","<<m<<")="<<(((fac[n]*inversefac[m])%p)*inversefac[n-m])%p<<endl;
	return (((fac[n]*inversefac[m])%p)*inversefac[n-m])%p;
}

long power(long x, long y, long p){
	if(y==0){
		return 1;
	}
	else{
		long long t = power(x, y/2, p);
		if(y%2==0){
			return (t*t)%p;
		}
		else{
			return (((t*t)%p)*x)%p;
		}
	}
}

void lists(bool a[], long i, long num, long n, long k, long p){
	if(i==0){
		long long res = (F(num, k-1, p)*C(n,num,p))%p;
		res = (res*k)%p;
		f[n][k] = (f[n][k]+res)%p;
		//printf("Now, F(%ld,%ld,%ld,%d)=%ld\n",n,k,p,nonzeros,f[n/2][k]);
		return;
	}
	if(a[i]){
		lists(a, i-1, num, n, k, p);
		lists(a, i-1, num+(1<<i), n, k, p);	
	}
	else{
		lists(a, i-1, num, n, k, p);
	}
	return;
}

long F(long n,long k,long p){
	//cout<<n<<" "<<k<<endl;
	if ((n==0)||(k==1)){
		return 1;
	}
	if(f[n][k]!=0){
		return f[n][k];
	}
	bool a[19];
	long i, oneInN=0;
	for(i=1;i<18;i++){
		if ((n>>i)%2==1){
			a[i] = true;
			oneInN++;
		}else{
			a[i] = false;
		}
	}
	i--;//a[17]???TM 
	while(!a[i])i--;
	f[n][k] = 0;
	//i-1x1,...xn  
	lists(a, i-1, 0, n, k, p);
	//cout<<"F("<<n<<","<<k<<")="<<f[n][k]<<endl;
	return f[n][k];
}

int main(){
	cin>>n>>k>>p;
	long total = power(k,n,p);
	
	if(n%2==1){
		cout<<total<<endl;
	}
	else{
		fac[0] = 1; inversefac[0] = 1;
		for(int i=1;i<=n;i++){
			fac[i] = (fac[i-1]*i)%p;
			long long y;
			inverse(fac[i],p,inversefac[i],y);
			//cout<<i<<" "<<fac[i]<<" "<<inversefac[i]<<endl;
		}
		int log2n = (int)(log(n)/log(2));
		bobwin = 0;
		memset(f, 0, sizeof(f));
		bobwin = F(n,k,p)%p;
		//printf("F(%ld,%ld,%ld,%d)=%ld\n",n,k,p,nonzeros,temp);
		cout<<(total-bobwin+p)%p<<endl;
	}
	return 0;
}