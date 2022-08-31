#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
#define mp make_pair
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define remax(a,b) a = max(a,b)
#define remin(a,b) a = min(a,b)
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define F first
#define S second
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define itr :: iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))

int power(int a,int b,int m = MOD){
	if(b == 0) return 1;
	if(b == 1) return a;
	int x = power(a,b/2,m)%m;
	x = (x*x)%m;
	if(b%2) return (x*a)%m;
	return x;
}

signed main(){
  int n,m;
  int perm[4] = {0,1,2,3};
  cin >> n >> m;
  int a[n+5][m+5],b[n+5][m+5],c[n+5][m+5];
  int ans = n*m+1;
  REP(i,n){
    REP(j,m){
      char c; cin >> c;
      if(c == 'A') a[i][j] = 0;
      else if(c == 'G') a[i][j] = 1;
      else if(c == 'C') a[i][j] = 2;
      else a[i][j] = 3;
    }
  }
  int cnt;
  REP(subtopewdszzzz,24){
    // -------------------------------------------------------------------------
    cnt = 0;
    REP(i,n){
      if(i%2 == 0){
        int lol1 = 0,lol2 = 0;
        REP(j,m){
          if(a[i][j] != perm[j%2]) lol1++;
          if(a[i][j] != perm[(j+1)%2]) lol2++;
        }
        if(lol1 < lol2){
          cnt += lol1;
          REP(j,m){
            b[i][j] = perm[j%2];
          }
        }
        else{
          cnt += lol2;
          REP(j,m){
            b[i][j] = perm[(j+1)%2];
          }
        }
      }
      else{
        int lol1 = 0,lol2 = 0;
        REP(j,m){
          if(a[i][j] != perm[2+(j%2)]) lol1++;
          if(a[i][j] != perm[2+((j+1)%2)]) lol2++;
        }
        if(lol1 < lol2){
          cnt += lol1;
          REP(j,m){
            b[i][j] = perm[2+(j%2)];
          }
        }
        else{
          cnt += lol2;
          REP(j,m){
            b[i][j] = perm[2+((j+1)%2)];
          }
        }
      }
    }
    if(cnt < ans){
      ans = cnt;
      REP(i,n){
        REP(j,m){
          c[i][j] = b[i][j];
        }
      }
    }
    // -------------------------------------------------------------------------
    // -------------------------------------------------------------------------
    cnt = 0;
    REP(j,m){
      if(j%2 == 0){
        int lol1 = 0,lol2 = 0;
        REP(i,n){
          if(a[i][j] != perm[i%2]) lol1++;
          if(a[i][j] != perm[(i+1)%2]) lol2++;
        }
        if(lol1 < lol2){
          cnt += lol1;
          REP(i,n){
            b[i][j] = perm[i%2];
          }
        }
        else{
          cnt += lol2;
          REP(i,n){
            b[i][j] = perm[(i+1)%2];
          }
        }
      }
      else{
        int lol1 = 0,lol2 = 0;
        REP(i,n){
          if(a[i][j] != perm[2+(i%2)]) lol1++;
          if(a[i][j] != perm[2+((i+1)%2)]) lol2++;
        }
        if(lol1 < lol2){
          cnt += lol1;
          REP(i,n){
            b[i][j] = perm[2+(i%2)];
          }
        }
        else{
          cnt += lol2;
          REP(i,n){
            b[i][j] = perm[2+((i+1)%2)];
          }
        }
      }
    }
    if(cnt < ans){
      ans = cnt;
      REP(i,n){
        REP(j,m){
          c[i][j] = b[i][j];
        }
      }
    }
    // -------------------------------------------------------------------------
    next_permutation(perm,perm+4);
  }
  REP(i,n){
    REP(j,m){
      if(c[i][j] == 0) cout << "A";
      else if(c[i][j] == 1) cout << "G";
      else if(c[i][j] == 2) cout << "C";
      else cout << "T";
    }
    cout << "\n";
  }
}