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
#define all(v) v.begin(),v.end()
using namespace std;
const int N=1505;
int n,a[N],id[N];
bool cmp(int x,int y){
	return a[x]==a[y]?x<y:a[x]<a[y];
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) id[i]=i;
	sort(id+1,id+n+1,cmp);
	For(i,1,n) a[id[i]]=i;
	//For(i,1,n) cout<<a[i]<<' '; cout<<endl;
	int sum=0;
	For(i,1,n) For(j,i+1,n)
		sum+=(a[i]>a[j]);
	printf("%d\n",sum);
	For(i,1,n)
		for (;a[i]>i;){
			int p1=a[i]-1,p2=a[i];
			printf("%d %d\n",i,id[p1]);
			swap(a[id[p1]],a[id[p2]]);
			swap(id[p1],id[p2]);
		}
}