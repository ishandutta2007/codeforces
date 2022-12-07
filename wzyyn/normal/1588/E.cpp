#include<bits/stdc++.h>

using namespace std;

const double pi=acos(-1);
int n,R;
struct P{
	int x,y;
}p[3005];
long long sqr(int x){
	return 1ll*x*x;
}
int ok[3005][3005];
void upd(int x){
	int fir=0;
	double pl=0,pr=0;
	for (int i=1;i<=n;i++)
		if (i!=x){
			long long d=sqr(p[i].x-p[x].x)+sqr(p[i].y-p[x].y);
			if (d<=1ll*R*R) continue;
			double ang=atan2(p[i].y-p[x].y,p[i].x-p[x].x);
			double dif=asin(R/sqrt(d));
			double l=ang-dif,r=ang+dif;
			if (fir==0){
				fir=1; pl=l; pr=r;
			}
			else{
				for (;l>pl;l-=2*pi,r-=2*pi);
				for (;l+2*pi<=pl;l+=2*pi,r+=2*pi);
				if (r<=pl) l+=2*pi,r+=2*pi;
				pl=max(pl,l);
				pr=min(pr,r);
				if (pl>pr) break;
			}
		}
	//cout<<x<<' '<<fir<<' '<<pl<<' '<<pr<<endl;
	for (int i=1;i<=n;i++){
		if (i==x) continue;
		if (!fir) ok[x][i]=1;
		else if (pl>pr) ok[x][i]=0;
		else{
			double ang=atan2(p[i].y-p[x].y,p[i].x-p[x].x);
			for (;ang-2*pi>=pl;ang-=2*pi);
			for (;ang<pl;ang+=2*pi);
			if (ang<=pr) ok[x][i]=1;
		}
	}
}
int main(){
	scanf("%d%d",&n,&R);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&p[i].x,&p[i].y);
	for (int i=1;i<=n;i++)
		upd(i);
	int ans=0;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (ok[i][j]&&ok[j][i])
				++ans;
	cout<<ans<<endl;
}