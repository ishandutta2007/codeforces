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
char s[100005],t[100005];
int a[100005],b[100005];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		scanf("%s%s",s+1,t+1);
		for(int i=1;i<=n;i++) a[i]=s[i]-'0',b[i]=t[i]-'0';
		int l=1,r=n,d=0;
		vector<int> ans(0);
		for(int i=n;i>=1;i--){
			if((a[r]^d)==b[i]){
				if(l<r) r--;
				else r++;
				continue;
			}
			if((a[l]^d^1)==b[i]){
				ans.pb(i);
				if(l<r) l++;
				else l--;
				swap(l,r),d^=1;
			}
			else{
				ans.pb(1);
				ans.pb(i);
				if(l<r) l++;
				else l--;
				swap(l,r),d^=1;
			}
		}
		printf("%d ",ans.size());
		for(auto x:ans) printf("%d ",x);
		printf("\n");
	}
	return 0;
}