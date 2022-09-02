#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define PB push_back
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int P=1e9+7;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
int R,p1,p2,p3,p4;
map<pair<int,int>,array<int,105> >mp;
array<int,105>operator+(const array<int,105>&A,const array<int,105>&B){
	array<int,105>C;
	rep(i,0,104)C[i]=ad(A[i],B[i]);
	return C;
}
array<int,105>operator-(const array<int,105>&A,const array<int,105>&B){
	array<int,105>C;
	rep(i,0,104)C[i]=su(A[i],B[i]);
	return C;
}
array<int,105>operator*(const array<int,105>&A,const int&k){
	array<int,105>C;
	rep(i,0,104)C[i]=mu(A[i],k);
	return C;
}
vector<array<int,105> >f;
int main(){
	scanf("%d%d%d%d%d",&R,&p1,&p2,&p3,&p4);
	int I=po(ad(p1,ad(p2,ad(p3,p4))),P-2);
	p1=mu(p1,I),p2=mu(p2,I),p3=mu(p3,I),p4=mu(p4,I);
	rep(x,-R-1,R+1)rep(y,-R-1,R+1){
		if(x*x+y*y<=R*R){
			if((x-1)*(x-1)+y*y>R*R){
				mp[{x,y}].at(y+R)=1;
			}else{
				mp[{x,y}]=(mp[{x-1,y}]-mp[{x-2,y}]*p1-mp[{x-1,y-1}]*p2-mp[{x-1,y+1}]*p4);
				mp[{x,y}].at(R*2+1)=su(mp[{x,y}].at(R*2+1),1);
				mp[{x,y}]=mp[{x,y}]*po(p3,P-2);
			}
			/*D("mp[{%d,%d}]=",x,y);
			rep(i,0,R*2+1)D("%d ",mp[{x,y}][i]);
			D("\n");*/
		}else{
			if((x-1)*(x-1)+y*y<=R*R){
				//D("HA %d %d\n",x,y);
				array<int,105>cur=(mp[{x-1,y}]-mp[{x-2,y}]*p1-mp[{x-1,y-1}]*p2-mp[{x-1,y+1}]*p4);
				cur.at(R*2+1)=su(cur.at(R*2+1),1);
				cur=cur*po(p3,P-2);
				f.PB(cur);
			}
		}
	}
	assert(SZ(f)==R*2+1);
	//rep(i,0,R*2){rep(j,0,R*2+1)D("%d ",f[i][j]);D("\n");}
	rep(i,0,SZ(f)-1){
		rep(j,i,SZ(f)-1)if(f[j][i]){
			swap(f[i],f[j]);
			break;
		}
		assert(f[i][i]);
		rep(j,0,SZ(f)-1)if(j!=i){
			int t=mu(f[j][i],po(f[i][i],P-2));
			f[j]=f[j]-f[i]*t;
		}
	}
	array<int,105>ans;
	rep(i,0,SZ(f)-1){
		ans[i]=mu(su(0,f[i][R*2+1]),po(f[i][i],P-2));
	}
	ans[R*2+1]=1;
	auto cur=mp[{0,0}];
	int res=0;
	rep(i,0,104)res=ad(res,mu(ans[i],cur[i]));
	printf("%d\n",res);
	return 0;
}