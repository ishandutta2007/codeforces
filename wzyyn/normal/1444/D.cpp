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

bool f[505][255005];
int Split(vector<int> &L,vector<int> &R){
	L.resize(0);
	R.resize(0);
	int n,a[1005],S=0,SS=0;
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]),S+=a[i];
	if (S%2==1||n>500) return 1;
	For(i,0,n) For(j,0,S/2) f[i][j]=0;
	f[0][0]=1;
	For(i,1,n){
		For(j,0,SS){
			f[i][j]|=f[i-1][j];
			f[i][j+a[i]]|=f[i-1][j];
		}
		SS=min(S/2,SS+a[i]);
	}
	//cout<<(f[n][S/2]?1:0)<<endl;
	if (!f[n][S/2]) return 1;
	int p=S/2;
	Rep(i,n,1)
		if (f[i-1][p])
			L.PB(a[i]);
		else R.PB(a[i]),p-=a[i];
	return 0;
}
void solve(){
	vector<int> L,R,U,D;
	int fl0=Split(L,R);
	int fl1=Split(U,D);
	if (L.size()+R.size()!=U.size()+D.size())
		return puts("No"),void(0);
	if (fl0||fl1)
		return puts("No"),void(0);
	if (L.size()>R.size()) swap(L,R);
	if (U.size()>D.size()) swap(U,D);
	sort(L.begin(),L.end());
	sort(R.begin(),R.end());
	sort(U.begin(),U.end());
	sort(D.begin(),D.end());
	printf("Yes\n");
	int px=0,py=0;
	reverse(L.begin(),L.end());
	reverse(D.begin(),D.end());
	For(i,0,L.size()-1){
		px+=L[i];
		printf("%d %d\n",px,py);
		py+=D.back(); D.pop_back();
		printf("%d %d\n",px,py);
	}
	for (;D.size();){
		px-=R.back(); R.pop_back();
		printf("%d %d\n",px,py);
		py+=D.back(); D.pop_back();
		printf("%d %d\n",px,py);
	}
	reverse(R.begin(),R.end());
	For(i,0,R.size()-1){
		px-=R[i];
		printf("%d %d\n",px,py);
		py-=U.back(); U.pop_back();
		printf("%d %d\n",px,py);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}