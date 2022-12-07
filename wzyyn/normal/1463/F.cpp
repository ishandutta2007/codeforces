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
int n,x,y,ans,f[55],tab[55];
int main(){
	scanf("%d%d%d",&n,&x,&y);
	if (x<y) swap(x,y);
	int p=x+y;
	For(i,0,p-1) tab[i]=n/p+(i<n%p);
	For(i,0,(1<<x)-1){
		bool flg=0;
		int s=0;
		For(j,0,x-1) f[j]=(i>>j)&1;
		For(j,x,p-1) f[j]=0;
		For(j,0,x-1) if (f[j]&&f[j+y]) flg=1;
		For(j,0,x-1) if (f[j]) s+=tab[j];
		if (flg) continue;
		For(j,x,p-1)
		if (f[j-y]||f[j+y-p]);
		else s+=tab[j];
		ans=max(ans,s);
	}
	cout<<ans<<endl;
}
/*
11  1
2221111
*/