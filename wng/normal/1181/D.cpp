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


VI st(1<<19,0);
int n,m,q;

void add(int city){
	int ii=city;
	while (ii<=m){
		st[ii]++;
		ii+=ii&-ii;
	}
}

int nbcbefore(int w){	
	int res=0;
	int ii=w;
	while (ii>0){
		res+=st[ii];
		ii-=ii&-ii;
	}
	return res;
}

int main(){
	//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    RIII(n,m,q);
    VI a(n);
    VI b(m+1,0);
    int mbi=0;
    REP(i,n){
		RI(a[i]);
		b[a[i]]++;
		mbi=max(mbi,b[a[i]]);
	}
	map<int,VI> gars;
	REPP(i,1,m+1){
		gars[b[i]].PB(i);
	}
	auto it=gars.begin();
	auto itt=gars.begin();
	itt++;
	int nbb=0;
	LL charn=n;
	LL maxx=(LL)1e18+100000;
	map<LL,int> charntogarsindex;
	while (it!=gars.end()){
		int nbc=nbb+it->S.size();
		int nba=nbc+(itt!=gars.end())?itt->S.size():0;
		LL nc=(itt!=gars.end())?(charn+(LL)nbc*(itt->F-it->F)):maxx;
		charntogarsindex[nc]=it->F; //charntogarsindex[x] contient les mecs  rajouter jusqu' l'anne x
		
	    //cout<<"it "<<it->F<<" "<<it->S.size()<<" "<<nc<<" "<<nbb<<" "<<nbc<<endl;
	    it++;
		if (itt!=gars.end())  itt++;
		charn=nc;
		nbb=nbc;
	}
	vector<pair<LL,int>> qs(q);
	REP(i,q){
		LL x;
		scanf("%I64d",&x);
		qs[i]={x,i};
	}
	sort(qs.begin(),qs.end());
	auto cq=qs.begin();
	vector<pair<int,LL>> res(q);
	auto cc=charntogarsindex.begin();
	LL prevlim=n;
	nbb=0;
	/*for (auto j:gars){
	    cout<<j.F<<" : ";	
    	    for (auto jj:j.S){
    	    cout<<jj<<" ";
    	    cout<<endl;
    	}
	}
	for (auto j:charntogarsindex){
	    cout<<j.F<<" -> "<<j.S<<endl;
	}*/
	LL maxrelou=(LL)mbi*m;
	while (cq!=qs.end() and cc!=charntogarsindex.end()){
		//ajout des gars au bst
		LL lim=cc->F;
		for (auto g:gars[cc->S]){
			add(g);
		//	cout<<"adding "<<g<<" "<<cc->S<<endl;
			nbb++;
		}
	//	cout<<nbb<<" "<<cq->F<<" "<<lim<<" "<<prevlim<<endl;
		cc++;
		while (cq!=qs.end() and cq->F<=lim and cq->F<=maxrelou){
			LL y=cq->F;
			int w=((y-prevlim)-1)%nbb;
			//trouver le plus petit index j tel que strictement polus que w mec apres j
			int tt=1<<19;
			int c=0;
			while (tt){
				if (c+tt<=m and nbcbefore(c+tt)<=w) c+=tt;
				tt>>=1;
			}
			c++;
			res[cq->S]={c,cq->F};
		//	cout<<cq->F<<" "<<cq->S<<" "<<c<<" k"<<endl;
			cq++;
		}
		prevlim=lim;
	}
	while (cq!=qs.end()){
	    res[cq->S] = {((cq->F-maxrelou)-1)%m+1,m};
	    cq++;
	}
	
	if (m==4899204 ) cout<<maxrelou<<endl;
	REP(i,q){
		if (m!=4899204 ) printf("%d\n",res[i].F);
		else printf("%I64d : %d\n",res[i].S,res[i].F);
	}
	// maintenir un BST du nb de gars <=  un certain index pour la priode de ref
	// itrer through les requtes,  chaque chgt de periode de ref tu rajoutes un truc au tree;
}