#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
const long long mod = 1000000007;

long long gcd(long long a, long long b){
    if(a==0) return b;
    if(b==0) return a;
    if(a>b) return gcd(b, a%b);
    return gcd(a,b%a);

}
/*
long long go(int k, int deg){
    long long ans=1;
    long long denom=1;
    for(int i=1; i<=deg; i++) denom*=i;
    for(long long j=k;j<=(k+deg-1);j++){
        long long c=gcd(j,denom);
        denom/=c;
        ans=(ans*(j/c))%mod;
    }
    return ans;
}*/

int p[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
int l[]={5,3,2,2,1,1,1,1,1,1,1,1,1,1,1,1};
int w[]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1-1,-1,-1,-1,-1,-1,-1,-1,-1-1,-1,-1,-1,-1,-1,-1,-1,-1-1,-1,-1,-1,-1,-1,-1,-1,-1-1,-1,-1,-1,-1,-1,-1,-1,-1-1,-1,-1,-1,-1,-1,-1,-1,-1-1,-1,-1,-1,-1,-1,-1,-1,-1-1,-1,-1,-1,-1,-1,-1,-1,-1-1,-1,-1,-1,-1,-1,-1,-1,-1-1,-1,-1,-1,-1,-1,-1,-1,-1-1,-1,-1,-1,-1,-1,-1,-1,-1-1,-1,-1,-1,-1,-1,-1,-1,-1-1,-1,-1,-1,-1,-1,-1,-1,-1-1,-1,-1,-1,-1,-1,-1,-1,-1-1,-1,-1,-1,-1,-1,-1,-1,-1-1,-1,-1,-1,-1,-1,-1,-1,-1-1,-1,-1,-1,-1,-1,-1,-1,-1};
bool pused[]={false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false};
int a[100];
int b[100];
std::vector<int> ac(100);
std::vector<int> cerrr;
int err=0;
int n;
int ans[100];
int jans=-1;
int cnt;
int deg(int p, int n){
	int pc=p;
	int ans=1;
	int nc=n;
	while(nc>0){
		if((nc%2)==1) ans*=pc;
		nc/=2;
		pc*=pc;
	}
	return ans;
}
int maxj=-1;
void go(){
	if(cnt<4){
		int jwas=maxj;
		for(int j=0;j<=min(min(cnt,n-1),maxj+1);j++){
			for(int k=0; k<=l[cnt];k++){
				int pd=deg(p[cnt],k);
				if(k>0) maxj=max(maxj,j);
				if(ac[j]*pd<60){
					w[ac[j]]=-1;
					ac[j]*=pd;
					w[ac[j]]=j;
					cnt++;
					go();
					cnt--;
					w[ac[j]]=-1;
					ac[j]/=pd;
					w[ac[j]]=j;
					maxj=jwas;
				}
				
			}

		}
		return;
	}
	if(cnt<16){
		for(int j=2; j<=59/p[cnt]; j++){
			if(w[j]!=-1){
				ac[w[j]]*=p[cnt];
				int ww=w[j];
				w[j]=-1;
				cnt++;
				go();
				cnt--;
				w[j]=ww;
				ac[w[j]]/=p[cnt];

			}

		}
		if(maxj<(n-1)){
			maxj++;
			ac[maxj]=p[cnt];
			cnt++;
			go();
			cnt--;
			ac[maxj]=1;
			maxj--;			
		}
		cnt++;
		go();
		cnt--;

	}
	if(cnt==16);
	std::vector<int> x(maxj+1);
	for(int j=0; j<maxj+1; j++) x[j]=ac[j];
	if(maxj>=0) std::sort(x.begin(),x.end());
	int curerr=0;
	for(int j=0; j<=maxj; j++) curerr+=abs(a[n-1-j]-x[maxj-j]);
	curerr+=cerrr[n-maxj-1];
	if(curerr<err){
		for(int j=0; j<=maxj; j++) ans[j]=x[j];
		jans=maxj;
		err=curerr;
	}


}

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
/*   std::vector<std::vector<int>> praz(2001);
std::vector<bool> isp(2001,false);
std::vector<int> p;
for(int i=2; i<=2000; i++){
    bool f=false;
    for(int j=0; j<p.size();j++) if(i%p[j]==0){
        f=true;
       
        for(int k=0; k<praz[i/p[j]].size();k++) praz[i].push_back(praz[i/p[j]][k]);
        praz[i].push_back(p[j]);
        break;
    }
    if(f) continue;
    p.push_back(i);
    isp[i]=true;
    praz[i].push_back(i);
}*/
  int m,k;
//int ans=0;
  
  cin >> n;
  //std::vector<int> a(n+1);
  std::vector<int> w(n+1);
  cerrr.push_back(0);
  for(int i=0; i<n; i++){
	  int x;
	  cin>>x;
	  a[i]=x;
	  b[i]=x;
  }
  std::sort(a, a+n);
   for(int i=0; i<n; i++){
	  err+=(a[i]-1);
	  cerrr.push_back(err);
  }

  cnt=0;
  go();
  std::vector<bool> used(101,false);
  std::vector<int> output(101,1);
  for(int i=jans; i>=0; i--){
	  int curmax=-1;
	  int maxi;
	  for(int j=0;j<n;j++){
		  if((b[j]>curmax)&&(!used[j])){
			  curmax=b[j];
			  maxi=j;
		  }
	  }
	  used[maxi]=true;
	  output[maxi]=ans[i];

  }
  for(int i=0;i<n;i++) cout<<output[i]<<" ";
  return 0;
}