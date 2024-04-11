#include <bits/stdc++.h>
using namespace std;
#define REP(i,n)	for(int i=0;i<n;i++)
#define Output(x)	cout<<#x<<"="<<x<<endl;
const int M=555;
int g[110][110],n,m;
int main(){
	cin>>n>>m;
	vector<int> A,B;
	REP(i,n)	REP(j,m)	cin>>g[i][j];
	int best=-1;
	REP(x,M){
		vector<int> a(n),b(m);
		a[0]=x;
		REP(j,m)	b[j]=g[0][j]-x;
		REP(i,n)	a[i]=g[i][0]-b[0];
		bool ok=true;
		REP(i,n)	ok=ok and (a[i]>=0);
		REP(i,m)	ok=ok and (b[i]>=0);
		REP(i,n)	REP(j,m)	
		ok=ok and (a[i]+b[j]==g[i][j]);
		if(ok){
			int total=accumulate(a.begin(),a.end(),0)+
			accumulate(b.begin(),b.end(),0);
			if(best==-1||total<best){
				best=total;
				A=a;B=b;
			}
		}
	}
	cout<<best<<endl;
	if(best!=-1){
		REP(i,n)	REP(j,A[i])	cout<<"row "<<i+1<<endl;
		REP(j,m)	REP(i,B[j])	cout<<"col "<<j+1<<endl;
	}
}