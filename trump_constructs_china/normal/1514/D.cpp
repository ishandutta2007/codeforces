#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i,s,t) for(int i=(s);i<=(t);++i)
#define per(i,t,s) for(int i=(t);i>=(s);--i)
#define REP(i,s,t) for(int i=(s);i<(t);++i)
#define PER(i,t,s) for(int i=(t);i>(s);--i)
#define elif else if
#define gup(x) return puts(#x), 0
namespace MyMinMax{
    template <typename T>
    inline T mn(T x, T y) {return x < y ? x : y;}
    template <typename T>
    inline T mx(T x, T y) {return x > y ? x : y;}
    template <typename T>
    inline void chmin(T &x, T y) {(x > y) && (x = y);}
    template <typename T>
    inline void chmax(T &x, T y) {(x < y) && (x = y);}
}
using namespace MyMinMax;
namespace IO{
    #define DPAIRSIZ 1 << 18
    #define getcha() (SS == TT && (TT = (SS = BB) + fread(BB, 1, DPAIRSIZ, stdin), SS == TT) ? EOF : *SS++)
    char BB[DPAIRSIZ], *SS = BB, *TT = BB;
    template <typename T>
    inline void read(T &x){
        x = 0;
        char c = getcha();
        while(c > 57 || c < 48) c = getcha();
        while(c <= 57 && c >= 48){
            x = x * 10 + c - 48;
            c = getcha();
        }
    }
    template <typename T>
    inline void read(T *bg, T *ed){while(bg != ed) read(*bg ++);}
    inline void read(char &ch){
        ch = getcha();
        while(ch <= 32) ch = getcha();
    }
    inline void read(char *s){
        char ch = getcha();
        while(ch <= 32) ch = getcha();
        while(ch > 32) *s ++ = ch, ch = getcha();
        *s = '\0';
    }
    inline void sread(char *s){
        char ch = getcha();
        while(ch < 32) ch = getcha();
        while(ch >= 32) *s ++ = ch, ch = getcha();
        *s = '\0';
    }
    inline void pread(char *&s){
        char ch = getcha();
        while(ch <= 32) ch = getcha();
        while(ch > 32) *s ++ = ch, ch = getcha();
        *s = '\0';
    }
    inline void spread(char *&s){
        char ch = getcha();
        while(ch < 32) ch = getcha();
        while(ch >= 32) *s ++ = ch, ch = getcha();
        *s = '\0';
    }
    template <typename T, typename ...Args>
    inline void read(T &x, Args &...args){read(x);read(args...);}
    char out[DPAIRSIZ], *Out = out;
    #define flush() fwrite(out, 1, Out - out, stdout)
    inline void putcha(char x) {*Out++ = x;if(Out - out >= (DPAIRSIZ)) flush(), Out = out;}
    template <typename T>
    inline void fprint(T x){
        if(x < 0) putcha(45), x = -x;
        if(x > 9) fprint(x / 10);
        putcha(x % 10 + 48);
    }
    template <typename T>
    inline void print(T x){fprint(x);putcha(10);}
    inline void print(char *ch){while(*ch != '\0') putcha(*(ch ++));putcha(10);}
    inline void put(char *ch){while(*ch != '\0') putcha(*(ch ++));}
    inline void print(const char *ch){while(*ch != '\0') putcha(*(ch ++));putcha(10);}
    inline void put(const char *ch){while(*ch != '\0') putcha(*(ch ++));}
    template <typename T, typename ...Args>
    inline void print(T x, Args ...args){fprint(x);putcha(32);print(args...);}
    template <typename ...Args>
    inline void print(const char *ch, Args ...args){while(*ch != '\0') putcha(*(ch ++));putcha(32);print(args...);}
    template <typename ...Args>
    inline void print(char *ch, Args ...args){while(*ch != '\0') putcha(*(ch ++));putcha(32);print(args...);}
    template <typename T, typename ...Args>
    inline void printl(T x, Args ...args){fprint(x);putcha(10);print(args...);}
    template <typename ...Args>
    inline void printl(const char *ch, Args ...args){while(*ch != '\0') putcha(*(ch ++));putcha(10);print(args...);}
    template <typename ...Args>
    inline void printl(char *ch, Args ...args){while(*ch != '\0') putcha(*(ch ++));putcha(10);print(args...);}
    template <typename T>
    inline void sprint(T x){fprint(x);putcha(32);}
    template <typename T, typename ...Args>
    inline void sprint(T x, Args ...args){fprint(x);putcha(32);sprint(args...);}
    template <typename T>
    inline void sprint(T *bg, T *ed){while(bg != ed) sprint(*bg ++);}
    template <typename T>
    inline void print(T *bg, T *ed){while(bg != ed) sprint(*bg ++);putcha(10);}
    template <typename T>
    inline void printl(T *bg, T *ed){while(bg != ed) print(*bg ++);}
    class AutoFlush{
        public:
            ~AutoFlush(){flush();}
    }__AutoFlush;
} // namespace IO
using namespace IO;
#define MAXN 300005
#define block 600
const int B = MAXN / block + 5;
int n, a[MAXN];
int num[B][B];
int m, bel[MAXN], lst[B];
int ans, cc[MAXN], pos[MAXN], cnt[MAXN];
int *s[MAXN], buf[MAXN], *ed = buf + sizeof(buf) / sizeof(int);
inline int *alloc(int siz){return ed -= siz;}
int main(){
    read(n);read(m);
    for (int i = 1;i <= n;i ++) read(a[i]);
    for (int i = 1;i <= n;i ++) bel[i] = (i - 1) / block + 1;
    for (int i = 1;i <= bel[n];++ i) lst[i] = mn(i * block, n);
    for (int i = bel[n];i >= 1;-- i){
        memset(cc, 0, sizeof(cc));
        for (int j = i;j <= bel[n];++ j){
            num[i][j] = num[i][j - 1];
            for (int k = lst[j - 1] + 1;k <= lst[j];++ k){
                cc[a[k]] ++;
                if(cc[a[k]] > num[i][j]) num[i][j] = cc[a[k]];
            }
        }
    }
    for (int i = 1;i <= n;++ i) s[i] = alloc(cc[i]);
    for (int i = 1;i <= n;++ i){
        pos[i] = cnt[a[i]];
        s[a[i]][cnt[a[i]] ++] = i;
    }
    while(m --){
        int l, r;read(l, r);
        ans = 0;
        if(bel[l] == bel[r]){
            for (int i = l;i <= r;++ i){
                int num = pos[i];
                while(num + ans < cnt[a[i]] && s[a[i]][num + ans] <= r) ++ ans;
            }
        }
        else{
            int L = bel[l], R = bel[r];
            ans = num[L + 1][R - 1];
            for (int i = l;bel[i] == L;++ i){
                int num = pos[i];
                while(num + ans < cnt[a[i]] && s[a[i]][num + ans] <= r) ans ++;
            }
            for (int i = r;bel[i] == R;-- i){
                int num = pos[i];
                while(num - ans >= 0 && s[a[i]][num - ans] >= l) ++ ans;
            }
        }
        const int len = (r - l + 1);
        if(ans > (len >> 1)) print(ans - (len - ans));
        else print(1);
    }
}