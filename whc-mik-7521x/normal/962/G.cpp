#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,now,xx,yy,xxx,yyy,ans;
struct node{
	int x,y;
}a[N];
vector<pair<int,int>>seg[N];
bool d[N];
void solve(int x){
	now-=d[x];
	d[x]=1-d[x];
	now+=d[x];
}
int main(){
    scanf("%d%d%d%d%d",&xx,&yyy,&xxx,&yy,&n);
	for(int i=1;i<=n;++i){
        scanf("%d%d",&a[i].x,&a[i].y);
	}
	for(int i=1;i<=n;++i){
		int nxt;
        if(i==n)nxt=1;
        else nxt=i+1;
		if(a[i].x==a[nxt].x)seg[a[i].x].push_back({a[i].y,a[nxt].y});
	}
	for(int i=0;i<xxx;++i){
		for(auto [x1,x2]:seg[i]){
			int l=min(x1,x2),r=max(x1,x2);
			l=max(l,yy),r=min(r,yyy);
			if(l>r)continue;
			int last=now;
			solve(l);
            solve(r);
			if(i>xx&&x1>x2)ans+=(now-last)>>1;
		}
		if(i==xx)ans=now>>1;
	}
    printf("%d",ans);
	return 0;
}