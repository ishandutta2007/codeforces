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
const int LIM=100005;
int A,B,ans;
void check1(){
	For(i,1,min(A+B,LIM)){
		int Ar=A/i,Al=(A+i)/(i+1); 
		int Br=B/i,Bl=(B+i)/(i+1);
		if (Ar>=Al&&Br>=Bl){
			ans+=Ar-Al+Br-Bl+1;
			if (A%(i+1)==0&&B%(i+1)==0) ans--;
			//cout<<i<<' '<<Ar<<' '<<Al<<' '<<Br<<' '<<Bl<<endl;
		}
	}
}
int main(){
	scanf("%d%d",&A,&B);
	for (int i=1,j;i<=min(A,B);i=j+1){
		j=min(A/(A/i),B/(B/i));
		int Ar=A/j,Al=(A+j)/(j+1); 
		int Br=B/j,Bl=(B+j)/(j+1);
		if (Ar>=Al&&Br>=Bl){
			ans+=Ar-Al+Br-Bl+1;
			if (A%(j+1)==0&&B%(j+1)==0) ans--;
			//cout<<i<<' '<<Ar<<' '<<Al<<' '<<Br<<' '<<Bl<<endl;
		}
	}
	printf("%d\n",ans);
	//check1();
	//printf("%d\n",ans);
}