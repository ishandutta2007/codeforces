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
template<typename T>void rd(vector<T>&v){for(T&i:v)rd(i);}

const int N=1005;
int a[N],cnt[N];
int MEX(int n){
	for(int i=1;i<=n;i++)cnt[a[i]]++;
	int ans=0;
	while(cnt[ans])ans++;
	for(int i=1;i<=n;i++)cnt[a[i]]--;
	return ans;
}
void P(int n){
	for(int i=1;i<=n;i++)printf("%i ",a[i]);
	printf("\n");
}
bool srt(int n){
	for(int i=2;i<=n;i++)if(a[i]<a[i-1])return 0;
	return 1;
}
int main(){
	for(int t=ri();t--;){
		int n=ri();
		vector<int> op;
		for(int i=1;i<=n;i++)rd(a[i]);
		//if(a[n]==0)op.pb(n),a[n]=MEX(n);
		while(!srt(n)){
			int pos=MEX(n);
			if(pos==0){
				for(int i=1;i<=n;i++)
					if(a[i]!=i){
						op.pb(i);
						a[i]=pos;
						break;
					}
			}else{
				op.pb(pos);
				a[pos]=pos;
			}
			//P(n);
		}
		/*int mod=0;
		while(!srt(n)){
			int pos=MEX(n);
			if(pos==0)mod=1;
			if(pos==n)mod=0;
			op.pb(pos+mod);
			a[pos+mod]=pos;
			P(n);
		}*/
		/*for(int i=1;i<=n;i++){
			bool ok=true;
			for(int j=i+1;j<=n;j++)
				if(a[i]==a[j])
					ok=false;
			if(!ok){
				op.pb(i);
				a[i]=MEX(n);
				P(n);
			}
		}*/
		/*a[n]=MEX(n);
		op.pb(n);
		P(n);*/
		/*for(int i=1;i<=n;i++){
			int pos=MEX(n);
			op.pb(pos);
			a[pos]=pos;
			P(n);
		}*/
		printf("%i\n",op.size());
		for(int i:op)printf("%i ",i);
		printf("\n");
	}
	return 0;
}