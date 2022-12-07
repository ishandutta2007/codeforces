#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;

const int N=100005;
const int L=1000005;
const int mo=1000000007;
int n,l[N];
vector<int> f[N];
string s[N];
char s1[L],s2[L];
int f1[L],f2[L],lcp[L];
void UPD(int &x,int y){
	(x+=y)>=mo?x-=mo:233;
}
void DIAO(int x){
	int mx=max(l[x],l[x-1])+2;
	For(i,0,mx+2){
		s1[i]=s2[i]='a'-1;
		f1[i]=f2[i]=lcp[i]=0;
	}
	For(i,0,l[x-1]  ) f1[i]=f[x-1][i];
	For(i,0,l[x-1]-1) s1[i]=s[x-1][i];
	For(i,0,l[x  ]-1) s2[i]=s[x  ][i];
	Rep(i,mx+1,0) lcp[i]=(s1[i]==s2[i]?lcp[i+1]+1:0);
	int v1=0,v2=0,fl=0;
	For(i,0,mx){
		if (i){
			if (s1[i]<s2[i-1]) UPD(v2,v1),v1=0;
			if (s1[i]>s2[i-1]) v1=0;
		}
		if (fl==0) UPD(v1,f1[i]);
		if (fl==1) UPD(v2,f1[i]);
		if (!fl&&s1[i]!=s2[i])
			fl=(s1[i]<s2[i]?1:-1);
		f2[i]=v2;
		int p=i+1+lcp[i+1];
		//cout<<x<<' '<<i<<' '<<p<<endl;
		if (p>mx||s1[p]<s2[p])
			UPD(f2[i],v1);
	}
	v1=v2=0;
	Rep(i,mx,0){
		int p=lcp[0];
		if (p>=i) UPD(f2[i],v1);
		else if (s1[p]<s2[p]){
			UPD(f2[i],v1);
			UPD(f2[i],v2);
		}
		p=i+1+lcp[i+1];
		if (p>mx||s1[p]<s2[p]) UPD(v1,f1[i]);
		else UPD(v2,f1[i]);
		if (s1[i-1]<s2[i]) UPD(v1,v2),v2=0;
		if (s1[i-1]>s2[i]) UPD(v2,v1),v1=0;
	}
	For(i,0,l[x]){
		//cout<<x<<' '<<i<<' '<<f2[i]<<endl;
		f[x][i]=f2[i];
	}
}
int main(){
	scanf("%d",&n);
	For(i,1,n) cin>>s[i];
	For(i,1,n) l[i]=s[i].length();
	For(i,1,n) f[i].resize(l[i]+1);
	For(i,0,l[1]) f[1][i]=1;
	For(i,2,n) DIAO(i);
	int ans=0;
	For(i,0,l[n])
		UPD(ans,f[n][i]);
	cout<<ans<<endl;
}