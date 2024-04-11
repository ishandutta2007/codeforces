#include <bits/stdc++.h>
typedef long long LL;
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second

using namespace std;

double dist(pair<double,double> a,pair<double,double>  b){
	return pow(pow((a.F-b.F),2)+pow(a.S-b.S,2),0.5);
}

int curpiv=-1;
PII pins={0,1};
pair<double,double> locpiv={0.0,0.0};
pair<double,double> locnonpiv={0.0,0.0};
vector<pair<double,double>> coords;
vector<double> distc;
pair<double,double> ctr0={0.0,0.0};


pair<double,double> operator-(const pair<double,double> a,const pair<double,double> b){
	return {a.F-b.F,a.S-b.S};
}
pair<double,double> operator+(const pair<double,double> a,const pair<double,double> b){
	return {a.F+b.F,a.S+b.S};
}

double area(pair<double,double> a,pair<double,double> b,pair<double,double> c){
	return 0.5*(a.F*b.S-a.F*c.S+b.F*c.S-b.F*a.S+c.F*a.S-c.F*b.S);
}

pair<double,double> centregrav(pair<double,double> a,pair<double,double> b,pair<double,double> c){
	return {(a.F+b.F+c.F)/3,(a.S+b.S+c.S)/3};
}

void printc(pair<double,double> c){
	printf("%.8f %.8f\n",c.F,c.S);
}

pair<double,double> locate(int tl,int pivot, pair<double,double> locpivot){
	pair<double,double> v1=ctr0-coords[pivot];
	pair<double,double> lb=coords[tl]-coords[pivot];
	double angle=atan2(-v1.F,-v1.S);//mouais
//	cout<<"angle "<<angle<<" "<<cos(angle)<<" "<<sin(angle)<<endl;
	//	pair<double,double> cn={locpivot.F,locpivot.S-distc[pivot]};
	//C'est 
	pair<double,double> rotated={lb.F*cos(angle)-lb.S*sin(angle),lb.S*cos(angle)+lb.F*sin(angle)};
//	printc(lb);
//	printc(rotated);
//	cout<<endl;
	return locpivot+rotated;
} 



int main(){
	int n,q;
	RII(n,q);
	REP(i,n){
			int x,y;
			RII(x,y);
			coords.PB({double(x),double(y)});
		}
		//Well looks like my formula for the center of gravity of a triangle
		//was wrong. But i can iterate though triangles 0,i,i+1
	double ta=0.0;
	REPP(i,2,n){
		double a=area(coords[0],coords[i-1],coords[i]);
		pair<double,double> cg=centregrav(coords[0],coords[i-1],coords[i]);
	//	printc(cg);
		double nta=ta+a;
		ctr0={(cg.F*a+ctr0.F*ta)/nta,(cg.S*a+ctr0.S*ta)/nta};
		ta=nta;
	//	cout<<ta<<endl;
	//	printc(ctr0);
	}
//	printc(ctr0);
	//rotation
	curpiv=-1;
	REP(i,q){
			int tq;
			RI(tq);
			if (tq==2){
				int p;
				RI(p);
				if (!~curpiv){
						printc(coords[p-1]);
					}
				else {
					printc(locate(p-1,curpiv,locpiv));
				}
			}
			else {
				int ol,ne;
				RII(ol,ne);
				if (!~curpiv){
						if (ol==1) { curpiv=1; locpiv=coords[1]; pins={1,ne-1};}
						else {curpiv=0; locpiv=coords[0]; pins={0,ne-1};}
					}
				else {
					if (ol-1!=pins.F) {pins={pins.F,ne-1};}
					else {curpiv=pins.S; locpiv=locnonpiv; pins={pins.S,ne-1};}
				}
				locnonpiv=locate(ne-1,curpiv,locpiv);
			}
		}
	
}