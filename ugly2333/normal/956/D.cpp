//CF 956D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 1e5+15;
const DB eps = 1e-10;
int ab(int x){
	if(x<0)
		return -x;
	return x;
}
DB sq(int x){
	return (DB)x*x;
}
int T[N][2];
void ad(int x,int y){
	if(!x)
		return;
	while(x<N){
		T[x][y]++;
		x+=x&-x;
	}
}
int qu(int x,int y){
	int o=0;
	while(x){
		o+=T[x][y];
		x-=x&-x;
	}
	return o;
}
int n,w;
int s[2],x[N][2],y[N][2],r[N][2][2];
DB k[N][2][2],z[N][2];
pair<DB,int> p[N],q[N];
int main()
{
	int i,j,l,o,h,xx,yy;
	DB b,c;
	LL ans=0;
	scanf("%d%d",&n,&w);
	for(i=1;i<=n;i=i+1){
		scanf("%d%d",&xx,&yy);
		j=(xx>0);
		s[j]++;
		x[s[j]][j]=xx,y[s[j]][j]=yy;
		k[s[j]][j][0]=(DB)(yy-w)/xx;
		k[s[j]][j][1]=(DB)(yy+w)/xx;
		b=sq(yy+w)+sq(xx),c=sq(yy-w)+sq(xx);
		z[s[j]][j]=(DB)(b+c-sq(w+w))/sqrt(b*c);
		//cout<<b<<' '<<c<<' '<<z[s[j]][j]<<endl;
		//printf("%.11lf\n",z[s[j]][j]);
	}
	for(j=0;j<2;j=j+1)
		for(l=0;l<2;l=l+1){
			for(i=1;i<=s[j];i=i+1)
				p[i]=make_pair(k[i][j][l],i);
			sort(p+1,p+s[j]+1);
			h=0;
			for(i=1;i<=s[j];i=i+1){
				o=p[i].second;
				if(i>1&&p[i].first-p[i-1].first<eps)
					r[o][j][l]=h;
				else
					r[o][j][l]=++h;
				//cout<<o<<h<<endl;
				//printf("%.11f\n",k[o][j][l]);
			}
		}
	for(j=0;j<2;j=j+1){
		for(i=1;i<=s[j];i=i+1)
			p[i]=make_pair((DB)-x[i][j],i);
		sort(p+1,p+s[j]+1);
		memset(T,0,sizeof(T));
		for(i=1;i<=s[j];i=i+1){
			o=p[i].second;
			//cout<<o<<endl;
			ans-=qu(r[o][j][0]-1,0)-qu(r[o][j][1],1);
			ad(r[o][j][0],0),ad(r[o][j][1],1);
		}
	}
	for(i=1;i<=s[0];i=i+1){
		p[i]=make_pair(k[i][0][0],i);
		q[i]=make_pair(k[i][0][1],i);
	}
	sort(p+1,p+s[0]+1);
	sort(q+1,q+s[0]+1);
	for(i=1;i<=s[1];i=i+1){
		b=lower_bound(p+1,p+s[0]+1,make_pair(k[i][1][0]-eps,0))-p;
		c=lower_bound(q+1,q+s[0]+1,make_pair(k[i][1][1]+eps,0))-q;
		//cout<<k[i][0][1]<<endl;
		//cout<<b<<c<<endl;
		ans+=c-b;
	}
	cout<<ans;
	return 0;
}
/*'
2 1
1 -50000
2 -100000
*/