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
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
using namespace std;
int n,a[105],b[105],cnt[33333];
map<ull,int> mp;
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,0,32767) cnt[i]=cnt[i/2]+(i&1);
	For(i,0,32767){
		ull tmp=0;
		For(j,1,n) b[j]=cnt[(a[j]>>15)^i];
		For(j,2,n) tmp=233ll*tmp+b[j]-b[1];
		mp[tmp]=i;
	}
	For(i,0,32767){
		ull tmp=0;
		For(j,1,n) b[j]=cnt[(a[j]&32767)^i];
		For(j,2,n) tmp=233ll*tmp+b[1]-b[j];
		if (mp.find(tmp)!=mp.end())
			return printf("%d",mp[tmp]*32768+i),0;
	}
	puts("-1");
}