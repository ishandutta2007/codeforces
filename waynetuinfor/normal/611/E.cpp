    #include<bits/stdc++.h>
    using namespace std;
     
    #define REP(i,a,b) for(i=a;i<b;i++)
    #define rep(i,n) REP(i,0,n)
     
    #define mygc(c) (c)=getchar()
    #define mypc(c) putchar(c)
     
    #define ll long long
    #define ull unsigned ll
     
    void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
    void reader(ll *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
    void reader(double *x){scanf("%lf",x);}
    int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}c[s]='\0';return s;}
    template <class T, class S> void reader(T *x, S *y){reader(x);reader(y);}
    template <class T, class S, class U> void reader(T *x, S *y, U *z){reader(x);reader(y);reader(z);}
    template <class T, class S, class U, class V> void reader(T *x, S *y, U *z, V *w){reader(x);reader(y);reader(z);reader(w);}
     
    void writer(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
    void writer(ll x, char c){int s=0,m=0;char f[20];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
    void writer(double x, char c){printf("%.15f",x);mypc(c);}
    void writer(const char c[]){int i;for(i=0;c[i]!='\0';i++)mypc(c[i]);}
    void writer(const char x[], char c){int i;for(i=0;x[i]!='\0';i++)mypc(x[i]);mypc(c);}
    template<class T> void writerLn(T x){writer(x,'\n');}
    template<class T, class S> void writerLn(T x, S y){writer(x,' ');writer(y,'\n');}
    template<class T, class S, class U> void writerLn(T x, S y, U z){writer(x,' ');writer(y,' ');writer(z,'\n');}
    template<class T> void writerArr(T x[], int n){int i;if(!n){mypc('\n');return;}rep(i,n-1)writer(x[i],' ');writer(x[n-1],'\n');}
     
    template<class T> inline T min(T a, T b, T c){return min(min(a,b),c);}
    template<class T> inline T min(T a, T b, T c, T d){return min(min(a,b),min(c,d));}
    template<class T> inline T max(T a, T b, T c){return max(max(a,b),c);}
    template<class T> inline T max(T a, T b, T c, T d){return max(max(a,b),max(c,d));}
     
    template<class S, class T> inline void chmin(S &a, T b){if(a>b)a=b;}
    template<class S, class T> inline void chmax(S &a, T b){if(a<b)a=b;}
     
    char memarr[17000000]; void *mem = memarr;
    #define MD 1000000007
     
    int N, X[3];
    int T[300000];
     
    int A, B, ABoC, C, AB, AC, BC, ABC;
     
    int solve(void){
      int i, j, k, res, tmp;
      int a, b, c;
     
      A = B = ABoC = C = AB = AC = BC = ABC = 0;
      rep(i,N){
        if(T[i] > X[0]+X[1]+X[2]){ return -1; }
     
        if(T[i] <= X[0]){ A++; continue; }
        if(T[i] <= X[1]){ B++; continue; }
        if(T[i] <= X[2] && T[i] <= X[0]+X[1]){ ABoC++; continue; }
        if(T[i] <= X[2]){ C++; continue; }
        if(T[i] <= X[0]+X[1]){ AB++; continue; }
        if(T[i] <= X[0]+X[2]){ AC++; continue; }
        if(T[i] <= X[1]+X[2]){ BC++; continue; }
        ABC++;
      }
     
     
      res = N;
      rep(k,ABoC+1){
        C += k;
        AB += ABoC - k;
     
        tmp = ABC;
        a = A; b = B; c = C;
     
        tmp += BC;
        a -= min(BC, a);
        
        tmp += AC;
        i = AC;
        j = min(i, b);
        b -= j; i -= j;
        j = min(i, a);
        a -= j;
     
        tmp += AB;
        i = AB;
        j = min(i, c);
        c -= j; i -= j;
        j = min(i, b);
        b -= j; i -= j;
        j = min(i, a);
        a -= j;
     
        tmp += max(c, (c+b+1)/2, (c+b+a+2)/3);
        
        res = min(res, tmp);
        
        C -= k;
        AB -= ABoC - k;
      }
     
      return res;
    }
     
     
     
     
    int dfs(int dep, int a, int b, int c){
      int i, j, k;
      int res = N+1;
      if(dep==N){
        return max(a,b,c);
      }
      rep(i,1<<3){
        k = 0;
        rep(j,3) if(i&1<<j) k+=X[j];
        if(k < T[dep]) continue;
        rep(j,3) if( (i&1<<j) && k-X[j] >= T[dep] ) break;
        if(j==3) chmin(res, dfs(dep+1, (i&1)?a+1:a, (i&2)?b+1:b, (i&4)?c+1:c));
      }
      return res;
    }
    int brute(void){
      return dfs(0, 0, 0, 0);
    }
     
     
    int main(){
      int i, res;
     
      reader(&N);
      rep(i,3) reader(X+i);
      rep(i,N) reader(T+i);
      sort(X, X+3);
     
    /*  for(;;){
        N = rand()%15 + 1;
        rep(i,3) X[i] = rand()%((i+1)*20) + 1;
        rep(i,N) T[i] = rand()%50 + 1;
        sort(X,X+3);
     
        writerLn("N", N);
        writerArr(X,3);
        writerArr(T,N);
     
        int res1, res2;
        res1 = solve();
        res2 = brute();
        if(res2==N+1) res2 = -1;
        writerLn("res", res1, res2);
        assert(res1==res2);
      }*/
     
      res = solve();
     
      writerLn(res);
     
      return 0;
    }