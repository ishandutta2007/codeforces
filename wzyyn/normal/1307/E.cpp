#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int mo=1000000007;
const int N=5005;
int n,Q,res,tmp;
int a[N],tp[N],S[N];
int S1[N],S2[N];
vector<int> vQ[N];
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,Q) scanf("%d%d",&tp[i],&S[i]);
	For(i,1,Q) vQ[tp[i]].PB(S[i]);
	For(i,1,n) sort(vQ[i].begin(),vQ[i].end());
	For(i,1,n) ++S2[a[i]];
	For(i,0,n){
		if (i) ++S1[a[i]],--S2[a[i]];
		int sum=0,ans=1;
		For(j,1,n){
			int sz=vQ[j].size(),p1=0,p2=0;
			for (;p1<sz&&vQ[j][p1]<=S1[j];++p1);
			for (;p2<sz&&vQ[j][p2]<=S2[j];++p2);
			//cout<<i<<' '<<p1<<' '<<p2<<endl;
			if (j==a[i]){
				if (!p1||vQ[j][p1-1]!=S1[j]) sum-=233333;
				p1=0,p2-=(S2[j]>=S1[j]),sum++;
			}
			if (p1>p2) swap(p1,p2);
			if (!p1&&!p2) continue;
			else if (!p1) sum++,ans=1ll*ans*p2%mo;
			else if (p2!=1) sum+=2,ans=1ll*ans*p1*(p2-1)%mo;
			else sum++,ans=2ll*ans%mo;
		}
		//cout<<i<<' '<<sum<<' '<<ans<<endl;
		if (sum>res) res=sum,tmp=0;
		if (sum==res) tmp=(tmp+ans)%mo;
	}
	if (!res) tmp=1;
	printf("%d %d\n",res,tmp);
}