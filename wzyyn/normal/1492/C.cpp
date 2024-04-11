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
const int N=200005;
int n,m,ans,p1[N],p2[N];
char s[N],t[N];
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s%s",s+1,t+1);
	For(i,1,m){
		p1[i]=p1[i-1]+1;
		for (;s[p1[i]]!=t[i];++p1[i]);
	}
	p2[m+1]=n+1;
	Rep(i,m,1){
		p2[i]=p2[i+1]-1;
		for (;s[p2[i]]!=t[i];--p2[i]);
	}
	For(i,1,m-1)
		ans=max(ans,p2[i+1]-p1[i]);
	cout<<ans<<endl;
}