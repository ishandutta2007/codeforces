#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int A,B,q;
char a[200013];
char b[200013];
unsigned long long a64[64][200130/64];
unsigned long long b64[64][200130/64];
unsigned long long a642[200013];
unsigned long long b642[200013];
int cnt[65536];

int main() {
    for (int i=0;i<65536;i++) cnt[i] = __builtin_popcount(i);
    scanf(" %s %s%d",&a,&b,&q);
    A = strlen(a); B = strlen(b);
    for (int i=A-1;i>=0;i--) a642[i] = (a642[i+1]<<1)+a[i]-'0';
    for (int i=B-1;i>=0;i--) b642[i] = (b642[i+1]<<1)+b[i]-'0';
    for (int i=0;i<A;i++) a64[i&63][i>>6] = a642[i];
    for (int i=0;i<B;i++) b64[i&63][i>>6] = b642[i];
    for (int i=0;i<q;i++) {
        int p1,p2,len;
        scanf("%d%d%d",&p1,&p2,&len);
        int ans = 0;
        int num = len>>6;
        for (int j=0;j<num;j++) {
            unsigned long long what = a64[p1&63][(p1>>6)+j]^b64[p2&63][(p2>>6)+j];
            ans+=cnt[what&0xFFFF]+cnt[(what>>16)&0xFFFF]+cnt[(what>>32)&0xFFFF]+cnt[what>>48];
        }
        for (int j=len-(len&63);j<len;j++) ans+=(a[p1+j]^b[p2+j])&1;
        printf("%d\n",ans);
    }

    return 0;
}