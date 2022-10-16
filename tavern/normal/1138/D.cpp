/*----------------by syr----------------*/
/*

         iii                  ii
     rBQBBBBBBE       BBR iBBBBQBBL     XBBBBBBQBBBBB
   iBBQJ    7BBB      BBsSBBr   BBQ      i      cBBB
  rBBU       iBBw     BBBQi     HBBi           KBBi
  BBH         BB5    iBBB       isL          wBB5
 GBB         iBBi    6BB                   iBBB
 BBQ         BQB     BBD                  QBBi
 BBB        BQB     iQBi                1BBv
 sBBg     wBBB      QBB               iBBB
  7BBBBBBBBBi       BBR              wBBBBBBBBBBBBB
     irvi           ii               ii    i i iii
                i5U
               BBB
               BB7
              1BB
      iPBBBBBKBBR    JBR1       rQBO   BR  UBQP  iBBQi
    7BBBGs7sXBBBi     QBBr     gBBE   rBB BB2BB7HBZQBB
   QBBi      sBQ       BBB   iBBB     SQBBR  BBBB  cBQ
  gBQ        BBg        BBB KBBi      MBBH   BBB   BBs
 iBBv       iBBi         QBBBL        BBR   pBB   iBB
 pBB        BBB         iBBBB        iBB    BBL   KBB
 MBB       BBBR        BBB JBBi      DBR   iBQ    BBL
 GBB     7BBBB2      PBBH   BBBi     BQr   DBB   iBB
  BQBXwgBBP BB7    1BBB      BBQ7   1BB    BBc   BBB
   2BBBBw   BB    EBBS        QBBi  HBa   iBB    BB7
*/
#include<bits/stdc++.h>

using namespace std;

#define PH push
#define MP make_pair
#define PB push_back
#define fst first
#define snd second
#define FOR(i,x,y) for(int i=(x);i<(y);++i)
#define REP(i,x,y) for(int i=(x);i<=(y);++i)
#define x0 x0123456789
#define y0 y0123456789
#define x1 x1234567890
#define y1 y1234567890
#define x2 x2345678901
#define y2 y2345678901
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF=1e9+7;
const int maxn=5e5+5;

int n,m;
int z[maxn],cnt[2];
char s[maxn],t[maxn],ans[maxn];

void zMatch(){
	z[0]=m;
	int l=0,r=0;
	FOR(i,1,m){
		if(i<=r) z[i]=min(r-i+1,z[i-l]);
		for(int &j=z[i];i+j<m&&t[i+j]==t[j];++j);
		if(i+z[i]-1>r) l=i,r=i+z[i]-1;
	}
	return;
}

int main(){
	scanf("%s",s);
	scanf("%s",t);
	n=strlen(s);
	m=strlen(t);
	zMatch();
	int pos=m;
	FOR(i,1,m) if(i+z[i]==m){
		pos=i;break;
	}
	FOR(i,0,n) s[i]-='0';
	FOR(i,0,n) t[i]-='0';
	FOR(i,0,n) if(s[i]) ++cnt[1]; else ++cnt[0];
	int itr=0,flg=0;
	FOR(i,0,n){
		//printf("i=%d itr=%d pos=%d\n",i,itr,pos);
		if(cnt[t[itr]]) ans[i]=t[itr]+'0',--cnt[t[itr]];
		else ans[i]=(t[itr]^1)+'0',--cnt[t[itr]^1];
		++flg;
		++itr;
		if(flg==pos) flg=0,itr=0;
	}
	printf("%s\n",ans);
	return 0;
}