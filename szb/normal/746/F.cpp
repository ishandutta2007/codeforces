#include<queue>
#include<ctime>
#include<vector>
#include<cstdio>
#include<cstring>
#include<string>
#include<memory.h>
#include<set>
#include<map>
#include<ctime>
#include<algorithm>
#define ll long long
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
#define F first
#define S i
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
const ll N=200100;
multiset<ll>s1,s2;
multiset<ll>::iterator j;
ll n,w,k,a[N],b[N],l,ans,tim,answ;
int main(){
	n=read();	w=read();	k=read();
	For(i,1,n)	a[i]=read();
	For(i,1,n)	b[i]=read();
	l=1;
	For(r,1,n){
		ans+=a[r];	tim+=(b[r]+1)/2;
		s1.insert(b[r]);
		while(s1.size()>w){
			s2.insert(*s1.begin());
			tim+=*(s1.begin())/2;
			s1.erase(s1.begin());
		}
		while(l<=r&&tim>k){
			if (b[l]>=*(s1.begin())){
				tim-=(b[l]+1)/2;
				s1.erase(s1.find(b[l]));
				if (s2.size()){
					j=s2.end();
					s1.insert(*(--j));
					tim-=*j/2;
					s2.erase(j);
				}
			}else	s2.erase(s2.find(b[l])),tim-=b[l];
			ans-=a[l++];
		}
		answ=max(answ,ans);
	}writeln(answ);
}
/*
 :Ni ti , pi, k
 , w().
*/