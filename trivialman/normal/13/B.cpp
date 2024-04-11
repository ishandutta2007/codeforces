#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
//#define N 200010// 
#define eps 1e-7
#define MOD 998244353
#define LL long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define CL(x) memset(x,0,sizeof(x))

LL t,x1,x2,x3,x4,x5,x6,y1,y2,y3,y4,y5,y6;

bool common(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
	if(x1==x3&&y1==y3||x1==x4&&y1==y4||x2==x3&&y2==y3||x2==x4&&y2==y4)return true;else return false;
}
bool check(double x1,double y1,double x2,double y2,double x3,double y3){
	double k=0,b=0,l1=0,l2=0;
	if(x1!=x2){k=(y1-y2)/(x1-x2);b=y1-k*x1;}
	
	if(x1==x2){if(x3!=x1)return false;}
	else if(abs(k*x3+b-y3)>eps)return false;
	
	//if(t>3)printf("k=%llf b=%llf\n",k1,b1);
	if((x3-x1)*(x3-x2)>0||x1==x2&&(y3-y1)*(y3-y2)>0)return false;
	else{
		if(x1!=x2)l1=abs(x3-x1),l2=abs(x3-x2);
		else l1=abs(y3-y1),l2=abs(y3-y2);
		//if(t>3)printf("l1=%llf l2=%llf\n",l1,l2);
		if(l1*4<l2||l2*4<l1)return false;
	}
	return true;
}

int main(){
	for(cin>>t;t;--t){
		bool flag=true;
		
		cin>>x1>>y1>>x2>>y2;
		cin>>x3>>y3>>x4>>y4;
		cin>>x5>>y5>>x6>>y6;
		if(common(x1,y1,x2,y2,x5,y5,x6,y6)){
			swap(x3,x5);swap(x4,x6);swap(y3,y5);swap(y4,y6);
		}else if(common(x3,y3,x4,y4,x5,y5,x6,y6)){
			swap(x1,x5);swap(x2,x6);swap(y1,y5);swap(y2,y6);
		}
		if(x1==x4&&y1==y4){swap(x3,x4);swap(y3,y4);}
		if(x2==x3&&y2==y3){swap(x1,x2);swap(y1,y2);}
		if(x2==x4&&y2==y4){
			swap(x1,x2);swap(y1,y2);
			swap(x3,x4);swap(y3,y4);
		}
		
		/*cout<<"after common point, flag="<<flag<<endl;
		cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
		cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<endl;
		cout<<x5<<" "<<y5<<" "<<x6<<" "<<y6<<endl;*/ 
		//cal angle:
		double dx1=x2-x1,dy1=y2-y1,dx2=x4-x3,dy2=y4-y3;
		double prodc=dx1*dx2+dy1*dy2;
		if(prodc<0.0||abs(prodc-sqrt(dx1*dx1+dy1*dy1)*sqrt(dx2*dx2+dy2*dy2))<eps)flag=false;
		//cout<<"after angle, flag="<<flag<<endl;
		
		if(!(check(x1,y1,x2,y2,x5,y5)&&check(x3,y3,x4,y4,x6,y6))&&
			!(check(x1,y1,x2,y2,x6,y6)&&check(x3,y3,x4,y4,x5,y5)))flag=false;
		cout<<(flag?"YES":"NO")<<endl;
	}
	return 0;
}