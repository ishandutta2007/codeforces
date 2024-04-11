#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define siup(x) (x[c[i]][d[i]]-x[a[i]-1][d[i]]-x[c[i]][b[i]-1]+x[a[i]-1][b[i]-1])
#define PB push_back
#define MP make_pair
#define sz(v) (in((v).size()))
#define forn(i,n) for(in i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define fors(i,s) for(auto i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
typedef vector<in> VI;
typedef vector<VI> VVI;
VVI mar;
in n,m,k;
void swip(VVI& v){
  for(in i=1;i<n;++i){
    for(in j=1;j<m;++j){
      v[i][j]+=v[i-1][j]+v[i][j-1]-v[i-1][j-1];
    }
  }
}
void unswip(VVI& v){
  for(in i=n-1;i>=1;--i){
    for(in j=m-1;j>=1;--j){
      v[i][j]-=v[i-1][j]+v[i][j-1]-v[i-1][j-1];
    }
  }
}
VI a,b,c,d,e;
VVI smallmaincnt,totfac,totfacmainlarge,totfacmainsmall,totfacsmall,totfaclarge,totsmallmain,totlargemain,totsmallsum,totlargesum,totdistmain,totsmallmainfac,totlargemainfac,smallthere,largethere;
VVI fct;
const in asz=26;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  scanf("%lld%lld%lld",&n,&m,&k);
  char ts[1009];
  mar.resize(n+2,VI(m+2));
  forn(z,n){
    scanf("%s",ts);
    for(in j=1;j<=m;++j){
      mar[z+1][j]=ts[j-1]-'a';
    }
  }
  n+=2;
  m+=2;
  a=b=c=d=e=VI(k);
  char tcar;
  forn(i,k){
    scanf("%lld%lld%lld%lld %c",&a[i],&b[i],&c[i],&d[i],&tcar);
    e[i]=tcar-'a';
  }
  smallmaincnt=totfac=totfacmainlarge=totfacmainsmall=totfacsmall=totfaclarge=totsmallmain=totlargemain=totsmallsum=totlargesum=totdistmain=totsmallmainfac=totlargemainfac=smallthere=largethere=fct=VVI(n,VI(m));
  forn(i,n){
    forn(j,m){
      totlargemain[i][j]=mar[i][j];
    }
  }
  forn(let,asz){
    forn(i,k){
      if(e[i]!=let)
	continue;
      ++fct[a[i]][b[i]];
      --fct[c[i]+1][b[i]];
      --fct[a[i]][d[i]+1];
      ++fct[c[i]+1][d[i]+1];
    }
    swip(fct);
    for(in i=1;i<n;++i){
      for(in j=1;j<m;++j){
	if(mar[i][j]<let)
	  totdistmain[i][j]+=(let-mar[i][j])*fct[i][j];
	else
	  totdistmain[i][j]+=(mar[i][j]-let)*fct[i][j];
      }
    }
    forn(i,n){
      forn(j,m){
	largethere[i][j]+=let*fct[i][j];
	totfac[i][j]+=fct[i][j];
	fct[i][j]=0;
	if(mar[i][j]==let){
	  totlargemain[i][j]-=let;
	  totsmallmain[i][j]+=let;
	}
      }
    }
  }
  for(in i=1;i<n-1;++i){
    for(in j=1;j<m-1;++j){
      totfacmainlarge[i][j]=totfaclarge[i][j]=totfac[i][j];
    }
  }
  swip(totfaclarge);
  swip(totfacmainlarge);
  swip(largethere);
  swip(totdistmain);
  in sumdistallmain=totdistmain[n-1][m-1];
  forn(i,n){
    forn(j,m){
      totlargemain[i][j]=mar[i][j];
      totsmallmain[i][j]=0;
      totlargemainfac[i][j]=mar[i][j]*totfac[i][j];
    }
  }
  swip(totlargemainfac);
  in bst=1e18;
  forn(let,asz){
    swip(totlargemain);
    swip(totsmallmain);
    forn(i,k){
      if(e[i]!=let)
	continue;
      in csum=0;
      csum+=e[i]*(2*siup(smallmaincnt)-(d[i]-b[i]+1)*(c[i]-a[i]+1));
      csum-=siup(totsmallmain);
      csum+=siup(totlargemain);
      csum*=k;
      csum+=sumdistallmain;
      csum-=(siup(totfacmainsmall)-siup(totfacmainlarge))*e[i];
      csum+=siup(totsmallmainfac);
      csum-=siup(totlargemainfac);
      csum-=siup(totdistmain);
      csum+=(siup(totfacsmall)-siup(totfaclarge))*e[i];
      csum-=siup(smallthere);
      csum+=siup(largethere);
      bst=min(bst,csum);
      /*
dist(here,main)
dist(there,main)
-distin(here,main)
-distin(there,main)
distin(here,there)
       */
    }
    unswip(totlargemain);
    unswip(totsmallmain);
    forn(i,k){
      if(e[i]!=let)
	continue;
      ++fct[a[i]][b[i]];
      --fct[c[i]+1][b[i]];
      --fct[a[i]][d[i]+1];
      ++fct[c[i]+1][d[i]+1];
    }
    swip(fct);
    unswip(smallthere);
    unswip(largethere);
    unswip(totfacsmall);
    unswip(totfaclarge);
    unswip(totfacmainlarge);
    unswip(totfacmainsmall);
    unswip(smallmaincnt);
    forn(i,n){
      forn(j,m){
	totfacsmall[i][j]+=fct[i][j];
	totfaclarge[i][j]-=fct[i][j];
	smallthere[i][j]+=fct[i][j]*let;
	largethere[i][j]-=fct[i][j]*let;
	if(mar[i][j]==let){
	  smallmaincnt[i][j]+=1;
	  totfacmainlarge[i][j]-=totfac[i][j];
	  totfacmainsmall[i][j]+=totfac[i][j];
	  totlargemain[i][j]-=let;
	  totsmallmain[i][j]+=let;
	}
      }
    }
    swip(smallmaincnt);
    swip(smallthere);
    swip(largethere);
    swip(totfacsmall);
    swip(totfaclarge);
    swip(totfacmainlarge);
    swip(totfacmainsmall);
    unswip(totsmallmainfac);
    unswip(totlargemainfac);
    forn(i,n){
      forn(j,m){
	if(mar[i][j]==let){
	  totsmallmainfac[i][j]+=totfac[i][j]*let;
	  totlargemainfac[i][j]-=totfac[i][j]*let;
	}
	fct[i][j]=0;
      }
    }
    swip(totsmallmainfac);
    swip(totlargemainfac);
  }
  cout<<bst<<endl;
  return 0;
}