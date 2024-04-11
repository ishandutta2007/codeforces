#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define double long double
using namespace std;

const int N=100005;
int n,a[N],pr[N],nx[N];
int fl[N],q[N];
set<int> S;
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int find(int p){
	auto it=S.lower_bound(p);
	if (it==S.end())
		return *S.begin();
	return *it;
}
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n){
		pr[i]=(i==1?n:i-1);
		nx[i]=(i==n?1:i+1);
	}
	S.clear(); 
	For(i,1,n)
		if (gcd(a[i],a[nx[i]])==1)
			S.insert(i),fl[i]=1;
		else fl[i]=0;
	int t=0,p=1;
	for (;t+1!=n;){
		if (S.empty()) break;
		p=find(p);
		fl[p]=0; S.erase(p);
		
		p=nx[p]; q[++t]=p;
		nx[pr[p]]=nx[p];
		pr[nx[p]]=pr[p];
		if (fl[p]) S.erase(p),fl[p]=0;
		if (gcd(a[pr[p]],a[nx[p]])==1)
			S.insert(pr[p]),fl[pr[p]]=1;
		
		p=nx[p];
	}
	if (t+1==n&&a[p]==1) q[++t]=p;
	printf("%d ",t);
	For(i,1,t) printf("%d ",q[i]);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}