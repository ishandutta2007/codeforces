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
const int N=1000005;
int n,s1,s2;
char s[N];
int f[N],g[N],nx[N],q[5];
void solve(){
	int ans0=0,d0=0;
	int ans1=0,d1=0;
	int p=1;
	for (;s[p]!='P';++p);
	Rep(i,p,1)
		if (s[i]=='*')
			++ans0,d0=p-i;
	For(i,p,n)
		if (s[i]=='*')
			++ans1,d1=i-p;
	if (ans0<ans1)
		swap(ans0,ans1),swap(d0,d1);
	if (ans0==ans1&&d0>d1)
		swap(d0,d1);
	printf("%d %d\n",ans0,d0);
}

bool check(int v){
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	f[0]=1;
	For(i,1,n){
		g[i]+=g[i-1];
		f[i]|=(g[i]!=0);
		if (s[i]=='.'){
			f[i]|=f[i-1];
			continue;
		}
		if (s[i]=='P'){
			if (f[i-1]){
				g[i]++;
				g[min(n,i+v)+1]--;
				f[i]=1;
			}
			continue;
		}
		if (f[i]||!f[i-1]) continue;
		//cout<<v<<' '<<i<<endl;
		int ed=min(n,i+v),cnt=0;
		for (int j=nx[i];j<=ed&&cnt<2;j=nx[j])
			q[++cnt]=j;
		//cout<<cnt<<endl;
		if (!cnt) return 0;
		if (cnt>=1) f[q[1]]=1;
		if (cnt>=2){
			g[q[2]]++;
			g[min(q[1]+v,n)+1]--;
		}
	}
	return f[n];
}
int main(){
	scanf("%d%s",&n,s+1);
	For(i,1,n){
		s1+=(s[i]=='P');
		s2+=(s[i]=='*');
	}
	if (s1==1) return solve(),0;
	int l=1,r=n,ans=nx[n+1]=n+1;
	Rep(i,n,1) nx[i]=(s[i+1]=='P'?i+1:nx[i+1]);
	while (l<=r){
		int mid=(l+r)/2;
		if (check(mid))
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d %d\n",s2,ans);
}