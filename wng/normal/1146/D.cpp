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

VI aregood;
int nbg;
int a,b;

void propagate(int source,int imax){
	if (source-b>0 and !aregood[source-b]) { aregood[source-b]=1; nbg++; propagate(source-b,imax);}
	if (source+a<=imax and !aregood[source+a]) { aregood[source+a]=1; nbg++; propagate(source+a,imax);}
}

LL Sk(int k){
	return (LL)k*(k+1)/2;
}

int main(){
	int m;
	RIII(m,a,b);
	LL res=0;
	int mmax=2*max(a,b);
	int g=__gcd(a,b);
	aregood=VI(mmax+1,0);
	aregood[0]=1;
	nbg=1;
	res+=nbg;
	REPP(i,1,min(m,mmax)+1){
		if (i>=a and aregood[i-a]) {aregood[i]=1; nbg++; propagate(i,i);}
		res+=nbg;
		//cout<<i<<" "<<nbg<<endl;
	}
	if (m>mmax){
	    //cout<<nbg<<" "<<mmax<<endl;
	    assert(nbg==mmax/g+1);
	//somme de i allant de mmax+1  m de i/g + 1 
		int i=mmax+1;
		while (i%g and i<=m) {res+=(1+i/g); i++;}
		if (i<=m){
			int j=m;
			while (j>i and j%g) {res+=(1+j/g); j--;}
            res+=(1+j/g);
			//somme de k allant de i  j-1 de i/g + 1  =  g fois la somme 
			int h=i/g;
			int H=j/g;
			res+= (LL)g * (Sk(H-1)-Sk(h-1));
			res+= (LL)(H-h) * g;
		}
	}
	printf("%I64d\n",res);
}