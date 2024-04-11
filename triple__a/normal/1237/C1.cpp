#include<bits/stdc++.h>
using namespace std;

const int maxn=50007;
int n;
struct pt{
	int x,y,z,idx;
	bool ck;
	friend bool operator<(pt &u,pt &v){
		if (u.ck>v.ck) return 1;
		if (u.ck<v.ck) return 0;
		if (u.x<v.x) return 1;
		if (u.x>v.x) return 0;
		if (u.y<v.y) return 1;
		if (u.y>v.y) return 0;
		if (u.z<v.z) return 1;
		return 0;
	}
}p[maxn];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
		p[i].idx=i,p[i].ck=1;
	}
	sort(p+1,p+n+1);
	int i=1;
	while (i<=n){
		if (!p[i].ck) break;
		if (i+1<=n&&p[i].x==p[i+1].x&&p[i].y==p[i+1].y){
			printf("%d %d\n",p[i].idx,p[i+1].idx);
			p[i].ck=p[i+1].ck=0;
			i+=2;
		}
		else{
			i++;
		}
	}
	sort(p+1,p+n+1);
	i=1;
	while (i<=n){
		if (!p[i].ck) break;
		if (i+1<=n&&p[i].x==p[i+1].x){
			printf("%d %d\n",p[i].idx,p[i+1].idx);
			p[i].ck=p[i+1].ck=0;
			i+=2;
		}
		else{
			i++;
		}
	}
	sort(p+1,p+n+1);
	i=1;
	while (i<=n){
		if (!p[i].ck) break;
		printf("%d %d\n",p[i].idx,p[i+1].idx);
		i+=2;
	}
	return 0;
}