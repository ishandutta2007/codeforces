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
const int N=100005;
int n,x=1;
int a[N],mat[N],vis[N];
int q1[N],q2[N],q3[N];
vector<pii> res;
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	Rep(i,n,1)
		if (a[i]==1)
			q1[++*q1]=i;
		else if (a[i]==2){
			if (!*q1) return puts("-1"),0;
			mat[i]=q1[(*q1)--];
			q2[++*q2]=i;
		}
		else if (a[i]==3){
			if (*q3) mat[i]=q3[*q3];
			else if (*q2) mat[i]=q2[*q2];
			else if (*q1) mat[i]=q1[(*q1)--];
			else return puts("-1"),0;
			q3[++*q3]=i; 
		}
	For(i,1,n)
		if (a[i]&&!vis[i]){
			int cur=i;
			for (;cur!=0;){
				vis[cur]=1;
				if (a[cur]==1)
					res.PB(pii(x++,cur));
				else if (a[cur]==2)
					res.PB(pii(x,cur));
				else{
					res.PB(pii(x,cur));
					res.PB(pii(x,mat[cur]));
					++x;
				}
				cur=mat[cur];
			} 
		}
	printf("%d\n",res.size());
	for (auto i:res)
		printf("%d %d\n",i.fi,i.se);
}