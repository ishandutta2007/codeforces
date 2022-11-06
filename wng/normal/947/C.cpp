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

//ok je fais un btree de mon s

struct node {
	node* c[2];
	int n[2];
	int key;
	};

 node * newNode(){
	node * n = new node;
	n->c[1]=NULL;
	n->c[0]=NULL;
	n->n[0]=0;
	n->n[1]=0;
	return n;
}

const int pmax=30;
void insert(int q, node* bt){
	int k=1<<(pmax-1);
	node *cn=bt;
	while (k) {
			int numi=(k&q)?1:0;
			if (!(cn->c[numi])) {
				cn->c[numi]=newNode(); 
				}
			(cn->n[numi])++;
			cn=cn->c[numi];
			//cout<<numi<<" "<<k<<endl;
			k>>=1;
		}
}

int remove(int q,node* bt){
	int res=0;
	int k=1<<(pmax-1);
	node *cn=bt;
	while (k) {
			int numi=(k&q)?1:0;
			//cout<<numi<<" "<<k<<endl;
			if (!cn->n[numi]) {
				res+=k;
				numi=1-numi;
				}
			//cout<<numi<<" "<<k<<endl;
			(cn->n[numi])--;
			cn=cn->c[numi];
			k>>=1;
		}
	return res;
}

int main(){
	int n;
	RI(n);
	VI a(n);
	VI p(n);
	REP(i,n){RI(a[i]);}
	node * bt=newNode();
	//cout<<bt<<endl;
	REP(i,n){RI(p[i]);	
		//create btree of s
		insert(p[i],bt);
		}
	//cout<<bt<<endl;
	
	//Remove A optimally
	REP(i,n){
		printf("%d ",remove(a[i],bt));
	}
	return 0;
}