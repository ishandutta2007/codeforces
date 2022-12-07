#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=100005;
char s[N];
struct info{
	char a[12];
	info(){
		memset(a,0,sizeof(a));
	}
	info operator +(const info &b)const{
		info ans;
		For(i,0,11)
			ans.a[i]=b.a[a[i]];
		return ans;
	}
}tr[11],st[17][N];
ll ans;
int main(){
	For(i,0,9){
		For(j,0,11)
			if (j<=i||j==11) tr[i].a[j]=11;
			else tr[i].a[j]=(j*(j-1)/2+i+10)%11;
	}
	scanf("%s",s+1);
	int n=strlen(s+1);
	For(i,1,n){
		s[i]-='0';
		st[0][i]=tr[s[i]];
	}
	For(i,1,16) For(j,1,n-(1<<i)+1)
		st[i][j]=st[i-1][j]+st[i-1][j+(1<<(i-1))];
	For(i,1,n) if (s[i]){
		int ri=i+1,pos=s[i];
		Rep(j,16,0)
			if (ri+(1<<j)-1<=n)
				if (st[j][ri].a[pos]!=11){
					pos=st[j][ri].a[pos];
					ri+=1<<j;
				}
		ans+=ri-i;
	}
	printf("%lld\n",ans);
}