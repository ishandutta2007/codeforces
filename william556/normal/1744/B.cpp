// LUOGU_RID: 90774432
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=1e5+5;
long long sum;
int n,q;
int cnt[2];
void solve(){
	n=in(),q=in();
	cnt[0]=cnt[1]=0,sum=0;
	for(int i=1;i<=n;i++){
		int x=in();
		cnt[x&1]++,sum+=x;
	}
	while(q--){
		int op=in(),x=in();
		sum+=1ll*cnt[op]*x;
		if(x&1)cnt[op^1]+=cnt[op],cnt[op]=0;
		printf("%lld\n",sum);
	}
}
int main(){
//	freopen("in.txt","r",stdin);
	int t=in();
	while(t--)solve();
	return 0;
}