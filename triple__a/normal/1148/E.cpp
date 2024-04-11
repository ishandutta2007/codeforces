#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=300007;
struct trip{
	int u,pos;
	friend bool operator<(trip x,trip y){
		if (x.u<y.u){
			return true;
		}
		else{
			return false; 
		}
	}
}dt[maxn];

int t[maxn],w[maxn],cnt=0;
int a[maxn*5],b[maxn*5],c[maxn*5];
int main(){
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;++i){
		scanf("%d",&dt[i].u);
		dt[i].pos=i+1;
	}
	for (int i=0;i<n;++i){
		scanf("%d",&t[i]);
	}
	sort(dt,dt+n);
	sort(t,t+n);
	int j=0;
	for (int i=0;i<n;++i){
		while (dt[i].u>t[i]&&j<i){
			if (dt[j].u<t[j]){
				a[cnt]=dt[j].pos;
				b[cnt]=dt[i].pos;
				c[cnt]=max(0,min(dt[i].u-t[i],t[j]-dt[j].u));
				dt[j].u+=c[cnt];
				dt[i].u-=c[cnt];
				if (c[cnt]>0){
					cnt++;
				}
			}
			if (dt[j].u==t[j]){
				j++;
			}
		}
		if (j==i&&dt[i].u>t[i]){
			printf("NO");
			return 0;
		}
	}
	for (int i=0;i<n;++i){
		if (dt[i].u!=t[i]){
			printf("NO");
			return 0;
		}
	}
	printf("YES\n%d\n",cnt);
	for (int i=0;i<cnt;++i){
		printf("%d %d %d\n",a[i],b[i],c[i]);
	}
}