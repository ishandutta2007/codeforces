//*
#include<stdio.h>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
#define MN 100000
using namespace std;

int N,M;

struct POINT{
	double x,y;
	POINT(){}
	POINT(double a_,double b_){
		x=a_,y=b_;
	}
};


struct LINE{
	double a,b,c;
	int index;
	LINE(){}
	LINE(double a_,double b_,double c_,int index_){
		a=a_,b=b_,c=c_,index=index_;
	}
};

bool chk(LINE A,LINE B){
	if(A.a*B.b==B.a*A.b)return false;
	return true;
}

POINT inter(LINE A,LINE B){
	double a,b,c,d,e,f;
	a=A.a,b=A.b,c=A.c;
	d=B.a,e=B.b,f=B.c;
	return POINT(-(c*e-b*f)/(a*e-b*d),-(c*d-a*f)/(b*d-a*e));
}

int rb(){
	return rand()*5+rand()%5;
}

vector<LINE> L;
vector<pair<int,int> > ans;

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++){
		double a,b,c;
		scanf("%lf%lf%lf",&a,&b,&c);
		L.push_back(LINE(a,b,c,i+1));
	}
	while(!L.empty()){
		if(L.size()<=M){
			ans.push_back(make_pair(L[L.size()-1].index,-1));
			L.pop_back();
			M--;
			continue;
		}
		int tn=0;
		POINT p;
		for(tn=0;tn<400;tn++){
			int p1,p2;
			p1=rb()%L.size(),p2=rb()%L.size();
			if(!chk(L[p1],L[p2]))continue;
			p=inter(L[p1],L[p2]);
			int cnt=0;
			for(auto &l:L){
				double v=l.a*p.x+l.b*p.y+l.c;
				if(-1e-8<v && v<1e-8)cnt++;
			}
			if(M*cnt>=L.size()){
				ans.push_back(make_pair(L[p1].index,L[p2].index));
				break;
			}
		}
		if(tn==400){
			puts("NO");
			return 0;
		}
		for(int i=L.size()-1;i>=0;i--){
			auto l=L[i];
			double v=l.a*p.x+l.b*p.y+l.c;
			if(-1e-8<v && v<1e-8){
				swap(L[i],L[L.size()-1]);
				L.pop_back();
			}
		}
		M--;
	}
	puts("YES");
	printf("%d\n",ans.size());
	for(auto p:ans){
		printf("%d %d\n",p.first,p.second);
	}
	return 0;
}
//*/