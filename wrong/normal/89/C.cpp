#include<cstdio>
#include<vector>

using namespace std;

int I[5050][5050];
char F[5050][5050];

struct chip {
  char c;
  int L, R, U, D;
};
vector<int> X, Y;
vector<chip> C;

int calc(vector<chip> T, int c)
{
  int s = 1;
  while(true) {
    char p = F[Y[c]][X[c]];
    int n;
    if(p=='U')n=T[c].U;
    if(p=='D')n=T[c].D;
    if(p=='L')n=T[c].L;
    if(p=='R')n=T[c].R;
    if(n<0) return s;
    if(T[c].U>=0) T[T[c].U].D=T[c].D;
    if(T[c].D>=0) T[T[c].D].U=T[c].U;
    if(T[c].L>=0) T[T[c].L].R=T[c].R;
    if(T[c].R>=0) T[T[c].R].L=T[c].L;
    s++;
    c=n;
  }
}

int main()
{
  int n, m, c = 0;
  scanf("%d%d", &n, &m);
  for(int i=0; i<n; ++i) {
    scanf("%s", F[i]);
    for(int j=0; j<m; ++j) {
      if(F[i][j]!='.') {
	X.push_back(j);
	Y.push_back(i);
	I[i][j]=c++;
      }
    }
  }
  C.resize(c);
  for(int i=0; i<c; ++i) {
    int x=X[i]+1, y=Y[i];
    while(x<m && F[y][x]=='.') x++;
    if(x<m) C[i].R = I[y][x]; else C[i].R=-1;
    x=X[i]-1; y=Y[i]; 
    while(x>=0&& F[y][x]=='.') x--;
    if(x>=0) C[i].L = I[y][x]; else C[i].L=-1;
    x=X[i]; y=Y[i]+1;
    while(y<n && F[y][x]=='.') y++;
    if(y<n) C[i].D = I[y][x]; else C[i].D=-1;
    x=X[i]; y=Y[i]-1;
    while(y>=0&& F[y][x]=='.') y--;
    if(y>=0) C[i].U = I[y][x]; else C[i].U=-1;
  }
  int sol = 0, cnt = 0;
  for(int i=0; i<c; ++i) {
    int t = calc(C, i);
    if(sol < t) { sol=t; cnt=1; }
    else if(sol==t) { cnt++; }
  }
  printf("%d %d\n", sol, cnt);
  return 0;
}