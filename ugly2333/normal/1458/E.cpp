#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 111111;
const int inf = 2e9+N;
int n,m,a[N],b[N];
LL c[N];
pair<pair<int,int>,int> px[N],py[N];
vector<int> v[N*2];
void ade(int x,int y,int z){//cout<<x<<' '<<y<<' '<<z<<endl;
	int o=x-y+N;
	v[o].push_back(x);
	v[o].push_back(x+z);
}
int qu(int x,int y){
	LL z=(LL)x<<32|y;
	if(z==*lower_bound(c+1,c+n+1,z))
		return 1;
	int o=x-y+N;
	if(o<0||o>N*2)
		return 0;
	int i=upper_bound(v[o].begin(),v[o].end(),x)-v[o].begin();
	if(i&1)
		return 1;
	return 0;
}
int main(){
	int i,j,x,y,z,o,cx,cy;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i=i+1){
		scanf("%d%d",a+i,b+i);
		c[i]=(LL)a[i]<<32|b[i];
	}
	sort(c+1,c+n+1);
	a[n+1]=inf,b[n+1]=inf;
	for(i=1;i<=n+1;i=i+1){
		px[i]=make_pair(make_pair(a[i],a[i]+b[i]),i);
		py[i]=make_pair(make_pair(b[i],a[i]+b[i]),i);
	}
	sort(px+1,px+n+1);
	sort(py+1,py+n+1);
	cx=0,cy=0;
	i=1,j=1;
	while(1){
		x=px[i].second;
		y=py[j].second;
		o=min(a[x]-cx,b[y]-cy);
		if(o>0){
			ade(cx,cy,o);
			cx+=o,cy+=o;
			continue;
		}
		if(i>n&&j>n)
			break;
		if(a[x]<cx){
			i++;
			continue;
		}
		if(b[y]<cy){
			j++;
			continue;
		}
		if(cx==a[x]&&cy>=b[x]){
			cx++;
			i++;
			continue;
		}
		if(cx>=a[y]&&cy==b[y]){
			cy++;
			j++;
			continue;
		}
		if(cx==a[x])
			i++;
		if(cy==b[y])
			j++;
	}
	for(i=1;i<=m;i=i+1){
		scanf("%d%d",&x,&y);
		if(qu(x,y))
			printf("LOSE\n");
		else
			printf("WIN\n");
	}
	return 0;
}