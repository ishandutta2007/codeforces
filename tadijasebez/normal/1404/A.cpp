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
const int N=300050;
char s[N];
int main(){
	for(int t=ri();t--;){
		int n=ri(),k=ri();
		scanf("%s",s+1);
		bool ok=1;
		for(int i=1;i<=k;i++){
			map<char,bool> has;
			for(int j=i;j<=n;j+=k){
				if(s[j]!='?')has[s[j]]=1;
			}
			if(has['0']&&has['1']){ok=0;break;}
			if(has['0'])for(int j=i;j<=n;j+=k)s[j]='0';
			if(has['1'])for(int j=i;j<=n;j+=k)s[j]='1';
		}
		if(ok){
			map<char,int> cnt;
			for(int i=1;i<=k;i++){
				cnt[s[i]]++;
			}
			if(cnt['0']*2>k||cnt['1']*2>k)ok=0;
		}
		if(ok)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}