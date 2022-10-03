#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000007
#define pb push_back

#define foreach(v,c) for(typeof(c).begin() v=(c).begin(); v!=(c).end(); v++)

int n;
int k = -1;
int p[100007];
vector<int> c[100007];
int black[100007];
long long memoopen[100007];
long long memoclosed[100007];

long long sq(long long x) {
  return x*x;
}

long long expm(long long x,long long e) {
  if (e==0) return 1;
  if (e%2==1) return (expm(x,e-1)*x)%MOD;
  return sq(expm(x,e/2))%MOD;
}

long long invm(long long x) {
  return expm(x,MOD-2);
}

void numways(int x) {
  long long opens = 0;
  long long closeds = 1;
  if (black[x]) {
    opens=1;
    closeds=0;
    foreach(v,c[x]) {
      numways(*v);
      opens*=(memoopen[*v]+memoclosed[*v]);
      opens%=MOD;
    }
    memoopen[x]=opens;
    memoclosed[x]=closeds;
    return;
  }
  foreach(v,c[x]) {
    numways(*v);
    closeds*=(memoclosed[*v]+memoopen[*v]);
    closeds%=MOD;
  }
  memoclosed[x]=closeds;
  foreach(v,c[x]) {
    opens+=(((closeds*invm(memoclosed[*v]+memoopen[*v]))%MOD)*memoopen[*v])%MOD;
  }
  opens%=MOD;
  memoopen[x]=opens;
  return;

}

int main() {

  cin >> n;
  int curr;
  for (int i = 0; i<n-1; i++) {
    cin >> curr;
    p[i+1]=curr;
    c[curr].pb(i+1);
  }
  for (int i = 0; i<n; i++)
    cin >> black[i];

  numways(0);

  cout << memoopen[0] << endl;


  return 0;
}