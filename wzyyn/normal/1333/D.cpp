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
const int N=3005;
int n,k;
char s[N],t[N];
int q[N];
int sim(){
	memcpy(t,s,sizeof(t));
	For(i,1,n){
		bool flg=0;
		For(j,1,n) if (t[j]=='R'&&t[j+1]=='L')
			swap(t[j],t[j+1]),flg=1,j++;
		if (!flg) return i-1;
	}
}
int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	int S1=0,sum=0;
	For(i,1,n){
		if (s[i]=='R') S1++;
		else sum+=S1;
	}
	if (k<sim()||k>sum)
		return puts("-1"),0;
	int p=1;
	For(i,1,k){
		*q=0;
		for (;sum>k-i&&p<n;p++)
			if (s[p]=='R'&&s[p+1]=='L')
				q[++*q]=p,--sum;
		if (!*q){
			p=1;		
			for (;sum>k-i&&p<n;p++)
				if (s[p]=='R'&&s[p+1]=='L')
					q[++*q]=p,--sum;
		}
		For(i,0,*q) printf("%d ",q[i]); puts("");
		For(i,1,*q) swap(s[q[i]],s[q[i]+1]);
	}
}