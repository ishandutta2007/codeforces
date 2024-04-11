#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int n;
char arr[3010][3010];
char brr[3010][3010];

int tl;
char srr[3010], trr[3010];

void pung() {
    puts("NO");
    exit(0);
}

int pi[3010];
void fail() {
    int i, j;
    pi[0] = -1;
    for (i=1;i<tl;i++) {
        j = i-1;
        while(j&&srr[pi[j]]!=srr[i-1]) j = pi[j];
        pi[i] = pi[j]+1;
    }
}

int mat(int idx) {
    int i = 0, j = 0;
    int n = strlen(arr[idx]), m = tl;
    while(i<n&&j<m) {
        if (arr[idx][i]==srr[j]) {
            i++; j++;
            if (j==m) return i-m;
        }
        else if (j) {
            j = pi[j];
        }
        else {
            i++; j = 0;
        }
    }
    return -1;
}

int sl[3010];
int el[3010];
int len[3010];
int main() {
    int i, j, fl = 0;

    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%s",arr[i]);
        len[i] = strlen(arr[i]);
    }
    for (i=0;i<n;i++)scanf("%s",brr[i]);
    for (i=0;i<n;i++) {
        if (strcmp(arr[i],brr[i])==0) {
            sl[i] = el[i] = -1;
            continue;
        }
        int s, e;
        for (s=0;arr[i][s]==brr[i][s];s++);
        sl[i] = s;
        for (e=strlen(arr[i])-1;arr[i][e]==brr[i][e];e--);
        el[i] = e;
        if (!fl) {
            for (j=s;j<=e;j++) srr[j-s]=arr[i][j];
            for (j=s;j<=e;j++) trr[j-s]=brr[i][j];
            tl = e-s+1;
            fl = 1;
        }
        else {
            if (tl!=e-s+1) pung();
            for (j=s;j<=e;j++) if (srr[j-s]!=arr[i][j]) pung();
            for (j=s;j<=e;j++) if (trr[j-s]!=brr[i][j]) pung();
        }
    }
    while(1) {
        bool ed = 0;
        char tmp = 'a';
        bool ff = 0;
        for (i=0;i<n;i++) {
            if (sl[i]<0) continue;
            if (sl[i]==0) {
                ed = 1;
                break;
            }
            if (!ff) {
                tmp = arr[i][sl[i]-1];
                ff = 1;
            }
            else {
                if (tmp!=arr[i][sl[i]-1]) {
                    ed = 1;
                    break;
                }
            }
        }
        if (ed) break;
        for (i=0;i<n;i++) {
            if (sl[i]<0) continue;
            sl[i]--;
        }
        tl++;
    }
    while(1) {
        bool ed = 0;
        char tmp = 'a';
        bool ff = 0;
        for (i=0;i<n;i++) {
            if (el[i]<0) continue;
            if (el[i]==len[i]-1) {
                ed = 1;
                break;
            }
            if (!ff) {
                tmp = arr[i][el[i]+1];
                ff = 1;
            }
            else {
                if (tmp!=arr[i][el[i]+1]) {
                    ed = 1;
                    break;
                }
            }
        }
        if (ed) break;
        for (i=0;i<n;i++) {
            if (el[i]<0) continue;
            el[i]++;
        }
        tl++;
    }
    for (i=0;i<n;i++) {
        if (sl[i]<0) continue;
        for (j=0;j<tl;j++) srr[j] = arr[i][j+sl[i]];
        for (j=0;j<tl;j++) trr[j] = brr[i][j+sl[i]];
        break;
    }
    fail();
    for (i=0;i<n;i++) {
        if (mat(i)!=sl[i]) pung();
    }
    puts("YES");
    printf("%s\n%s\n",srr,trr);

    return 0;
}