#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;

const int mo=1000000007;
const int N=1000005;
int n,S[N],vi[N],p[N],tms;
void C4(){
	tms+=S[4]; S[1]+=S[4];
}
void C2(){
	if (S[2]) --S[2];
	else S[1]-=2,++tms;
}
void C1(){
	for (;S[1]>S[2];S[1]-=2,S[2]++,tms++);
	tms+=max(S[1],S[2]);
} 
void solve(){
	scanf("%d",&n);
	For(i,1,max(5,n)) S[i]=0;
	int v=1;
	For(i,1,n/3) v=3ll*v%mo;
	if (n%3==1) v=1ll*v*(mo+1)/3%mo*4%mo;
	else if (n%3==2) v=2ll*v%mo;
	printf("%d ",v);
	For(i,1,n) vi[i]=0;
	For(i,1,n) scanf("%d",&p[i]);
	For(i,1,n) if (!vi[i]){
		int x=i,s=0;
		for (;!vi[x];x=p[x])
			vi[x]=1,++s;
		++S[s];
	}
	tms=0;
	Rep(i,n,5){
		tms+=S[i];
		S[i-3]+=S[i];
		S[i]=0;
	}
	if (n%3==0) C4(),C1();
	else if (n%3==2) C4(),C2(),C1();
	else{
		if (S[1]+S[4]>=S[2]&&S[4]) --S[4],C4(),C1();
		else if (S[1]==1&&S[2]==0) tms++;
		else C4(),C2(),C2(),C1();
	}
	printf("%d\n",tms);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}