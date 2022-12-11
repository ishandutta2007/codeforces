#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int n,l[20];
long double X,Y,Z,xx[262222],yy[262222],zz[262222];
pair<long double,int> p[20][50005],p2[20][50005];
pair<int,int> ans;
long double res=orz;
void mt(int _l,int _r){
	long double f=max(fabs(X-(xx[_l]*zz[_l]+(n*2-xx[_r])*zz[_r])/(zz[_l]+zz[_r])),fabs(Y-(yy[_l]*zz[_l]+yy[_r]*zz[_r])/(zz[_l]+zz[_r])));
	if(f<res)res=f,ans=mp(_l,_r);
}
int main(){
	cin>>n>>X>>Y;
	Z=X/Y;
	n/=2;
	for(int _=0;_<(1<<n);++_){
		bool ok=1;
		int s=0;
		for(int i=0;i<n;++i){
			if(_&(1<<i))++s;
			else --s;
			if(s<0)ok=0;
		}
		if(!ok) continue;
		long double x=0,y=0,z=0;
		s=0;
		for(int i=0;i<n;++i){
			if(_&(1<<i)){
				z+=s+0.5;
				x+=(i+0.5)*s+(i+2.0/3.0)*0.5;
				y+=(s*0.5)*s+(s+1.0/3.0)*0.5;
				++s;
			}
			else{
				--s;
				z+=s+0.5;
				x+=(i+0.5)*s+(i+1.0/3.0)*0.5;
				y+=(s*0.5)*s+(s+1.0/3.0)*0.5;
			}
		}
		xx[_]=x/z;
		yy[_]=y/z;
		zz[_]=z;
		p[s][++l[s]]=mp(x-Z*y,_);
		p2[s][l[s]]=mp(n*2*z-x-Z*y,_);
	}
	for(int i=0;i<=n;++i){
		sort(p2[i]+1,p2[i]+l[i]+1);
		for(int j=1;j<=l[i];++j){
			int o=0,oo=0;
			long double _=-p[i][j].first-1e-5;
			for(int k=17;k>=0;--k){
				int O=o+(1<<k);
				if(O>l[i]) continue;
				if(p2[i][O].first<_)o=O;
			}
			_+=2e-5;
			for(int k=17;k>=0;--k){
				int O=oo+(1<<k);
				if(O>l[i]) continue;
				if(p2[i][O].first<_)oo=O;
			}
			for(int k=o+1;k<=oo;++k)mt(p[i][j].second,p2[i][k].second);
				
		}
	}
	for(int c=0;c<n;++c){
		if(ans.first&(1<<c))printf("(");
		else printf(")");
	}
	for(int c=n-1;c>=0;--c){
		if(ans.second&(1<<c))printf(")");
		else printf("(");
	}
	printf("\n");
    return 0;
}