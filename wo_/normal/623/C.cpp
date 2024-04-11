#include<cstdio>
#include<utility>
#include<cmath>
#include<iostream>
#include<algorithm>

using namespace std;

typedef pair<long long,long long> P;

const int inf = 1e9;

long long mi_l[100100],ma_l[100100];
long long mi_r[100100],ma_r[100100];

P ps[100100];
int N;

void flip(){
	for(int i=1;i<=N;i++){
		ps[i].first*=-1;
	}
}

void init(){
	sort(ps+1,ps+N+1);
	mi_l[0] = inf;
	ma_l[0] = -inf;
	mi_r[N + 1] = inf;
	ma_r[N + 1] = -inf;
	
	for(int i=1;i<=N;i++){
		mi_l[i]=min(mi_l[i-1],ps[i].second);
		ma_l[i]=max(ma_l[i-1],ps[i].second);
	}
	for(int i=N;i>=1;i--){
		mi_r[i]=min(mi_r[i+1],ps[i].second);
		ma_r[i]=max(ma_r[i+1],ps[i].second);
	}
}

long long trivial(){
	int dx=ps[N].first-ps[1].first;
	int dy=ma_l[N]-mi_l[N];
	int d=min(dx,dy);
	return (long long)d*d;
}

bool check(long long D,bool debug=false){
	long long tmp=sqrt(D);
	long long dx=tmp-2;
	for(int d=-2;d<=2;d++){
		long long a=tmp+d;
		if(a*a<=D) dx=a;
	}
	for(int i=1;i<=N;i++){
		if(ps[i].first>0) break;
		long long x=ps[i].first;
		long long nx=min(x+dx,-x);
		int j=lower_bound(ps+1,ps+N+1,P(nx,inf))-ps;
		if(i==1&&j==N+1) return true;
		long long my=inf,My=-inf;
		my=min(my,mi_l[i-1]);
		My=max(My,ma_l[i-1]);
		my=min(my,mi_r[j]);
		My=max(My,ma_r[j]);
		long long cand1=(long long)(My-my)*(My-my);
		long long cand2=x*x+my*my;
		long long cand3=x*x+My*My;
		if(debug){
			printf("%d %d\n",i,j);
			printf("%d %d %d %d\n",(int)x,(int)nx,(int)my,(int)My);
		}
		if(cand1<=D&&cand2<=D&&cand3<=D) return true;
	}
	return false;
}

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ps[i+1]=P(x,y);
	}
	long long lb=-1;
	init();
	long long ub=trivial();
	while(ub-lb>1){
		long long mid=(ub+lb)/2;
		bool flg=check(mid);
		if(flg) ub=mid;
		else lb=mid;
	}
	flip();
	init();
	lb=-1;
	while(ub-lb>1){
		long long mid=(ub+lb)/2;
		bool flg=check(mid);
		if(flg) ub=mid;
		else lb=mid;
	}
	cout<<ub<<"\n";
	return 0;
}