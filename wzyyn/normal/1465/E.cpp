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
int n;
ll d;
char s[100005];
int tab[55];
int main(){
	scanf("%d%lld%s",&n,&d,s+1);
	For(i,1,n) s[i]-='a';
	d-=(1<<s[n]);
	d+=(1<<s[n-1]);
	//cout<<d<<endl;
	For(i,1,n-2) ++tab[s[i]];
	For(i,0,25) d-=tab[i]*(1ll<<i);
	if (d>0)
		return puts("No"),0;
	Rep(i,25,0)	
		for (;tab[i]&&d+(2<<i)<=0;)
			--tab[i],d+=(2<<i);
	puts(d==0?"Yes":"No");
}