#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;
int n,k;
char s[100005];
int a[30],rem[30];
void solve(){
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	if (n%k) return puts("-1"),void(0);
	memset(a,0,sizeof(a));
	For(i,1,n) a[s[i]-'a']++;
	bool flag=0;
	For(i,0,25) if (a[i]%k) flag=1;
	if (!flag) return printf("%s\n",s+1),void(0);
	Rep(i,n,1){
		--a[s[i]-'a'];
		for (;s[i]!='z';){
			++s[i];
			++a[s[i]-'a'];
			int sum=0;
			For(j,0,25) sum+=(k-a[j]%k)%k;
			if (sum<=n-i){
				For(j,0,25) rem[j]=(k-a[j]%k)%k;
				rem[0]+=(n-i)-sum;
				int p=0;
				For(j,i+1,n){
					for (;!rem[p];++p);
					s[j]='a'+p; --rem[p];
				}
				printf("%s\n",s+1);
				return;
			}
			--a[s[i]-'a'];
		}
	}
	puts("-1");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}