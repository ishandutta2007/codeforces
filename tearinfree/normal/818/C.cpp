#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>

typedef std::pair<int, int> ip;
int d,n,m;
ip xx[200000],yy[200000];
int ll[100000],rr[100000],tt[100000],bb[100000],chk[100000];

int main() {
	int x1,y1,x2,y2;
	scanf("%d %d %d",&d,&n,&m);
	for(int i=0;i<d;i++) {
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		xx[i]=ip(x1,i); xx[i+d]=ip(x2,i);
		yy[i]=ip(y1,i); yy[i+d]=ip(y2,i);
		if(x1==x2) {
			tt[i]--; bb[i]--;
		}
		else {
			ll[i]--; rr[i]--;
		}
	}
	std::sort(xx,xx+d+d);
	std::sort(yy,yy+d+d);
	
	int cnt=0,tmp=0;
	for(int i=0;i<d+d;i++) {
		if(i!=0&&xx[i].first!=xx[i-1].first) cnt+=tmp, tmp=0;
		if(!chk[xx[i].second]) chk[xx[i].second]=1,tmp++;
		else ll[xx[i].second]+=cnt;
	}
	
	memset(chk,0,sizeof(chk));
	cnt=tmp=0;
	for(int i=d+d-1;i>=0;i--) {
		if(i!=d+d-1&&xx[i].first!=xx[i+1].first) cnt+=tmp,tmp=0;
		if(!chk[xx[i].second]) chk[xx[i].second]=1,tmp++;
		else rr[xx[i].second]+=cnt;
	}

	memset(chk,0,sizeof(chk));
	cnt=tmp=0;
	for(int i=0;i<d+d;i++) {
		if(i!=0&&yy[i].first!=yy[i-1].first) cnt+=tmp,tmp=0;
		if(!chk[yy[i].second]) chk[yy[i].second]=1, tmp++;
		else tt[yy[i].second]+=cnt;
	}
	
	memset(chk,0,sizeof(chk));
	cnt=tmp=0;
	for(int i=d+d-1;i>=0;i--) {
		if(i!=d+d-1&&yy[i].first!=yy[i+1].first) cnt+=tmp,tmp=0;
		if(!chk[yy[i].second]) chk[yy[i].second]=1,tmp++;
		else bb[yy[i].second]+=cnt;
	}

	int l,r,t,b;
	scanf("%d %d %d %d",&l,&r,&t,&b);
	for(int i=0;i<d;i++) {
		if(ll[i]==l&&rr[i]==r&&tt[i]==t&&bb[i]==b) {
			printf("%d\n",i+1); return 0;
		}
	}
	puts("-1");

	return 0;
}