// author: xay5421
// created: Tue Mar 16 15:05:56 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=1505;
int n,lim,col[N][N],ans[N];
deque<pair<int,int> >RD[2][N],R,D[N];
void shift(deque<pair<int,int> >&v){for(auto&x:v)++x.Y;}
deque<pair<int,int> >shifted(deque<pair<int,int> >v){shift(v);return v;}
void put(deque<pair<int,int> >&v,int x){
	shift(v);
	for(auto it=v.begin();it!=v.end();){
		if(it->X==x)v.erase(it);
		else it++;
	}
	v.push_front(make_pair(x,0));
	if(SZ(v)>lim)v.resize(lim);
}
bool pd[N*N];
deque<pair<int,int> >mer(const deque<pair<int,int> >&k1,const deque<pair<int,int> >&k2){
	deque<pair<int,int> >k3;
	int i=0,j=0;
	while(i<SZ(k1)||j<SZ(k2)){
		if(i<SZ(k1)&&(j>=SZ(k2)||k1[i].Y<k2[j].Y)){
			if(!pd[k1[i].X]){
				k3.push_back(k1[i]);
				pd[k1[i].X]=1;
			}
			++i;
		}else{
			if(!pd[k2[j].X]){
				k3.push_back(k2[j]);
				pd[k2[j].X]=1;
			}
			++j;
		}
	}
	for(const auto&x:k1)pd[x.X]=0;
	for(const auto&x:k2)pd[x.X]=0;
	if(SZ(k3)>lim)k3.resize(lim);
	return k3;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d",&n,&lim),++lim;
	rep(i,1,n)rep(j,1,n)scanf("%d",&col[i][j]);
	per(i,n,1){
		rep(j,1,n)RD[i&1][j].clear();
		R.clear();
		per(j,n,1){
			/*put(R,col[i][j]);
			put(D[j],col[i][j]);
			RD*[i&1][j]=mer(shifted(RD[(i+1)&1][j+1]),mer(R,D[j]));*/
			put(RD[i&1][j],col[i][j]);
			RD[i&1][j]=mer(mer(mer(RD[i&1][j],shifted(RD[(i+1)&1][j+1])),shifted(RD[(i+1)&1][j])),shifted(RD[i&1][j+1]));
			int maxx=min(n-i+1,n-j+1);
			if(SZ(RD[i&1][j])>=lim)++ans[min(maxx,RD[i&1][j].back().Y)];
			else ++ans[maxx];
		}
	}
	per(i,n,1)ans[i]+=ans[i+1];
	rep(i,1,n)printf("%d\n",ans[i]);
	return 0;
}