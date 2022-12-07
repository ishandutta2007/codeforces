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
int n,a[505],t;

struct node{
	int d,i,j;
}q[130000];
bool cmp(node a,node b){
	return a.d>b.d;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (a[i]<a[j])
				q[++t]=(node){a[j]-a[i],j,i};
			else
				q[++t]=(node){a[i]-a[j],i,j};
	sort(q+1,q+t+1,cmp);
	for (int i=1;i<=t;i++){
		printf("? %d %d\n",q[i].i,q[i].j);
		fflush(stdout);
		char s[5];
		scanf("%s",s+1);
		if (s[1]=='Y'){
			printf("! %d %d\n",q[i].i,q[i].j);
			return 0;
		}
	}
	puts("! 0 0");
}