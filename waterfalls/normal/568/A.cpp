#include <cstdio>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

#define MAXN 10000013

bool isprime[MAXN];
bool ispali[MAXN];
int p,q;

void genprime() {
    fill(isprime,isprime+MAXN,1);
    isprime[0] = isprime[1] = 0;
    for (int i=2;i<MAXN;i++) if (isprime[i]) {
        for (int j=i+i;j<MAXN;j+=i) isprime[j] = 0;
    }
}

void genpali() {
    for (int i=0;i<10;i++) ispali[i] = 1;
    for (int i=1;i<=1000;i++) { // submitted wrong code...
        stringstream bad;
        bad << i;
        string s;
        bad >> s;
        bad.clear();
        string t = s;
        reverse(t.begin(),t.end());
        string res = s+t;
        bad << res;
        int res2;
        bad >> res2;
        bad.clear();
        ispali[res2] = 1;
        for (int j=0;j<10;j++) {
            res = s+(char) (j+'0')+t;
            bad << res;
            bad >> res2;
            bad.clear();
            if (res2<MAXN) ispali[res2] = 1;
        }
    }
}

int main() {
    genprime();
    genpali();
    scanf("%d%d",&p,&q);
    int ans = 0;
    int cur1 = 0;
    int cur2 = 0;
    for (int i=1;i<MAXN;i++) {
        if (isprime[i]) cur1+=1;
        if (ispali[i]) cur2+=1;
        if (1LL*q*cur1<=1LL*p*cur2) ans = max(ans,i);
    }
    printf("%d\n",ans);

    return 0;
}