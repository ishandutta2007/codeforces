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
const int N=1005;
int a[N][N],key[N],fa[N],nd,n;
int divide(vector<int> v){
	if (v.size()==1){
		key[v[0]]=a[v[0]][v[0]];
		return v[0];
	}
	int k=++nd,mx=0;
	for (auto i:v) for (auto j:v) mx=max(mx,a[i][j]);
	for (auto i:v) if (!key[i]){
		vector<int> v2;
		for (auto j:v) if (a[i][j]!=mx) v2.PB(j);
		fa[divide(v2)]=k;
	}
	key[k]=mx;
	return k;
}
int main(){
	scanf("%d",&n); nd=n;
	For(i,1,n) For(j,1,n) scanf("%d",&a[i][j]);
	vector<int> id;
	For(i,1,n) id.PB(i);
	int rt=divide(id);
	printf("%d\n",nd);
	For(i,1,nd) printf("%d%c",key[i],i==nd?'\n':' ');
	printf("%d\n",rt);
	For(i,1,nd) if (fa[i]) printf("%d %d\n",i,fa[i]);
}