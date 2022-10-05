#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool is_black(int x,int y){
	return (bool)((x+y)%2);
}
struct rec{
	ll x,y,xx,yy;
	ll width(){
		return (xx-x+1);
	}
	ll height(){
		return (yy-y+1);
	}
	rec(){x=-1ll;y=-1ll;xx=-1ll;yy=-1ll;}
	rec(ll a,ll b,ll aa,ll bb){
		x=a,y=b,xx=aa,yy=bb;
	}
	rec operator &(rec r){
		rec rc1=*this,rc2=r;
		rec res;
    	if(rc1.xx>=rc2.x&&
			rc2.xx>=rc1.x&&
        	rc1.yy>=rc2.y&&
        	rc2.yy>=rc1.y)
        		return(rec(max(rc1.x,rc2.x),max(rc1.y,rc2.y),
				min(rc1.xx,rc2.xx),min(rc1.yy,rc2.yy)));
    	else
        	return res;
	}
	ll count_black(){
		if((!is_black(x,y)&&!is_black(xx,yy))&&(xx-x+1)*(yy-y+1)%2)	
			return max(0ll,((xx-x+1)*(yy-y+1)-1)/2);
		else return max(0ll,((xx-x+1)*(yy-y+1)+1)/2);
	}
};
void solve(){
	ll n,m;
	cin>>n>>m;
	rec a,b;
	cin>>a.x>>a.y>>a.xx>>a.yy>>b.x>>b.y>>b.xx>>b.yy;
	rec o=a&b;
	ll bk=rec(1,1,m,n).count_black();
	bk-=a.count_black()-o.count_black();
	bk+=(b.width()*b.height()-b.count_black());
	cout<<(m*n-bk)<<" "<<bk<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}//