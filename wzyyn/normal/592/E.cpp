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
using namespace std;
const int N=350000;
struct P{
	int x,y;
	P(){}
	P(int _x,int _y){
		x=_x; y=_y;
	}
	bool be()const{
		return x?x>0:y>0;
	}
	P operator +(const P &a)const{
		return P(x+a.x,y+a.y);
	}
	P operator -(const P &a)const{
		return P(x-a.x,y-a.y);
	}
	ll operator *(const P &a)const{
		return 1ll*x*a.y-1ll*y*a.x;
	}
	bool operator ==(const P &a)const{
		return 1ll*x*a.y==1ll*y*a.x&&be()==a.be();
	}
}p[N*2];
ll ans,SSS[N*2];
int n,PX,PY;
int S[N*2],SS[N*2];
bool cmp(P x,P y){
	return x.be()^y.be()?x.be():x*y>0;
}
int main(){
	scanf("%d%d%d",&n,&PX,&PY);
	For(i,1,n){
		scanf("%d%d",&p[i].x,&p[i].y);
		p[i].x-=PX; p[i].y-=PY;
		//cout<<p[i].x<<
	}
	sort(p+1,p+n+1,cmp);
	int top=1; S[1]=1;
	For(i,2,n){
		if (!(p[i]==p[i-1]))
			p[++top]=p[i];
		++S[top];
	}
	n=top;
	For(i,1,n){
		//printf("%d %d %d\n",p[i].x,p[i].y,S[i]);
		p[i+n]=p[i]; S[i+n]=S[i];
	}
	For(i,1,n*2){
		SS[i]=SS[i-1]+S[i];
		SSS[i]=SSS[i-1]+1ll*S[i]*S[i];
	}
	For(i,1,n) ans+=1ll*S[i]*(1ll*SS[i-1]*SS[i-1]-SSS[i-1])/2;
	int p1=1;
	//printf("%c %c %c\n",p[1].be()?'Y':'N',p[2].be()?'Y':'N',cmp(p[1],p[2])?'Y':'N');
	//cout<<p[1]*p[2]<<' '<<ans<<endl;
	For(i,1,n){
		p1=max(p1,i);
		for (;p1+1!=i+n&&p[i]*p[p1+1]>=0;++p1);
		ans-=1ll*S[i]*(1ll*(SS[p1]-SS[i])*(SS[p1]-SS[i])-(SSS[p1]-SSS[i]))/2;
		
		//cout<<p1<<' '<<ans<<endl;
	}
	printf("%lld\n",ans);
}