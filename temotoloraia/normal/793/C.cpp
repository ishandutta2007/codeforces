#include <bits/stdc++.h>
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int MOD=1e9+7,N=1005;
const double INF=1e8;
int n;
double X1,X2,Y1,Y2;
double r,c,u,v;
double t1,t2;
double M1,M2=INF;
int main()
{
	cin>>n>>X1>>Y1>>X2>>Y2;
	for (int i=1;i<=n;i++){
		//cin>>r>>c>>u>>v;
		scanf("%lf%lf%lf%lf",&r,&c,&u,&v);
		t1=0;
		t2=INF;
		if (u>0){
			t1=MAX(t1,(X1-r)/u);
			t2=MIN(t2,(X2-r)/u);
		}
		if (u<0){
			t1=MAX(t1,(X2-r)/u);
			t2=MIN(t2,(X1-r)/u);
		}
		if (u==0){
			if (X1>=r || r>=X2){
				t1=INF;
				t2=0;
			}
		}
		if (v>0){
			t1=MAX(t1,(Y1-c)/v);
			t2=MIN(t2,(Y2-c)/v);
		}
		if (v<0){
			t1=MAX(t1,(Y2-c)/v);
			t2=MIN(t2,(Y1-c)/v);
		}
		if (v==0){
			if (Y1>=c || c>=Y2){
				t1=INF;
				t2=0;
			}
		}
		//cout<<t1<<" "<<t2<<endl;
		M1=MAX(M1,t1);
		M2=MIN(M2,t2);
	}
	if (M1>=M2)cout<<-1<<endl;
	else
	printf("%.10lf\n",M1);
    return 0;
}