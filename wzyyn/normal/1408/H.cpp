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
const int N=500005;
int n,a[N],S[N];
int le[N],ri[N],tab[N];
priority_queue<int,vector<int>,greater<int>> Q; 
vector<int> op[N];
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n){
		S[i]=S[i-1]+(a[i]==0);
		op[i].resize(0);
		tab[i]=0;
	}
	S[n+1]=S[n];
	For(i,1,n) le[i]=0,ri[i]=n+1;
	For(i,1,n) if (a[i])
		if (S[i]<=S[n]/2) le[a[i]]=max(le[a[i]],i);
		else ri[a[i]]=min(ri[a[i]],i);
	int ans=S[n]/2;
	For(i,1,n) if (le[i]||ri[i]!=n+1){
		++tab[S[ri[i]]];
		op[S[le[i]]].PB(S[ri[i]]);
		//cout<<le[i]<<' '<<ri[i]<<endl;
	}
	while (!Q.empty()) Q.pop();
	int sz=0;
	For(i,1,n){
		sort(op[i].begin(),op[i].end());
		for (auto j:op[i]){
			Q.push(j);
			if (sz==i) Q.pop();
			else ++sz;
		}
	}
	for (;!Q.empty();Q.pop())
		--tab[Q.top()];
	int rem=0;
	For(i,S[n]/2+1,S[n]-1){
		rem+=tab[i];
		if (rem) ++sz,--rem;
	}
	cout<<min(ans,sz)<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}