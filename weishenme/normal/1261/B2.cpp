#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200005;
int a[N],num[N],n,m,f[N],Ans[N];
struct Ask{
	int x,y,from;
}A[N];
int cmp(int x,int y){
	return a[x]>a[y]||(a[x]==a[y]&&x<y);
}
int cmp2(Ask x,Ask y){
	return x.x<y.x;
}
int find(int x){
	int ans=0;
	for (;x;x-=x&-x)ans+=num[x];
	return ans;
}
void insert(int x){
	for (;x<=n;x+=x&-x)num[x]++;
}
signed main(){
	scanf("%lld",&n);
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]),f[i]=i;
	sort(f+1,f+n+1,cmp);
	scanf("%lld",&m);
	for (int i=1;i<=m;i++)scanf("%lld%lld",&A[i].x,&A[i].y),A[i].from=i;
	sort(A+1,A+m+1,cmp2);
	for (int i=1,j=1;i<=n;i++){
		insert(f[i]);
		while (A[j].x==i){
			int l=1,r=n;
			while (l<r){
				int mid=(l+r)/2;
				if (find(mid)<A[j].y)l=mid+1;
				else r=mid;
			}
			Ans[A[j].from]=l;
			j++;
		}
	}
	for (int i=1;i<=m;i++)printf("%d\n",a[Ans[i]]);
}