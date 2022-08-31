#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
pii a[100005];
int cnt1[2],cnt2[2];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=mp(readint(),i);
		sort(a+1,a+n+1);
		int lst=0;
		bool fl=0;
		cnt1[0]=cnt1[1]=cnt2[0]=cnt2[1]=0;
		for(int i=1;i<=n;i++){
			if(a[i].fi!=lst){
				if(cnt1[0]!=cnt2[0]) fl=1;
				cnt1[0]=cnt1[1]=cnt2[0]=cnt2[1]=0;
				cnt1[i&1]++,cnt2[a[i].se&1]++;
				lst=a[i].fi;
			}
			else{
				cnt1[i&1]++,cnt2[a[i].se&1]++;
			}
		}
		if(cnt1[0]!=cnt2[0]) fl=1;
		if(fl) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}