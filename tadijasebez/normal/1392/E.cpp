#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define ldb double
template<typename T>void ckmn(T&a,T b){a=min(a,b);}
template<typename T>void ckmx(T&a,T b){a=max(a,b);}
void rd(int&x){scanf("%i",&x);}
void rd(ll&x){scanf("%lld",&x);}
void rd(char*x){scanf("%s",x);}
void rd(ldb&x){scanf("%lf",&x);}
void rd(string&x){scanf("%s",&x);}
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&i:x)rd(i);}
template<typename T,typename...A>void rd(T&x,A&...args){rd(x);rd(args...);}
template<typename T>void rd(){T x;rd(x);return x;}
int ri(){int x;rd(x);return x;}
template<typename T>vector<T> rv(int n){vector<T> x(n);rd(x);return x;}
const ll lim=1e16;
int main(){
	int n=ri(),st=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i&1)printf("0 ");
			else printf("%lld ",(ll)1<<(st+j-1));
			assert((ll)1<<(st+j-1)<=lim);
		}
		if(i%2==0)st+=2;
		printf("\n");
		fflush(stdout);
	}
	int q=ri();
	while(q--){
		ll k;rd(k);
		int now=0,x=1,y=1,cnt=0;
		for(int i=1;i<=n;i++){
			k/=2;
			printf("%i %i\n",x,y);
			fflush(stdout);
			cnt++;
			while(cnt<n*2-1&&k%2==now){
				y++;
				printf("%i %i\n",x,y);
				fflush(stdout);
				cnt++;
				k/=2;
			}
			x++;
			now^=1;
		}
	}
	return 0;
}