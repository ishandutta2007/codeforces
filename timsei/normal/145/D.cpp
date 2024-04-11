#include <cstdio>
#include <set>
using namespace std;
const int N = 1e5 + 5;
#define LL long long
LL ans , res;
set<LL>S;
set<LL>::iterator p,q;
int n,m,k,pos[N],val[N],nxt[N],tot;bool Yes(int x) {for(;x;x /= 10) if(x % 10 != 7 && x % 10 != 4) return 0;return 1;}
#define PER(i , a , b) for(int i = a;i <= b;++ i)
int main(void) {
	scanf("%d" , &n);ans=n*1ull*(n-1)*(n-2)/6ull*(n-3)/4 + n * 1ull * (n - 1) * 1ull * (n - 2) / 3 + n * 1ull * (n - 1) / 2;PER(i,1,n) scanf("%d",&val[i]),(Yes(val[i]))?pos[++ tot]=i:0;PER(i,1,tot) PER(j , i + 1 , tot) if(val[pos[i]]==val[pos[j]]) {nxt[i] = j; break;}PER(i,2,tot){
		res=0;S.clear();S.insert(n+1);S.insert(pos[i]-1);
		for(int j=i-1;j>=1;--j) {
			if(nxt[j]>=i)
				for(int k=nxt[j];k;k=nxt[k]) {
					p=S.lower_bound(pos[k]);q=p--;res+=(*q-pos[k])*(pos[k]-*p)*(pos[i]-pos[i-1]);
					if(*p==pos[i]-1) res+=(pos[i]-pos[i-1])*1ll*(pos[i]-pos[i-1]-1)/2*(*q-pos[k]);S.insert(pos[k]);
				}
			ans-=res*(pos[j]-pos[j-1]);
		}
	}printf("%lld\n",ans);
}