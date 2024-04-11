#include <cstdio>
#include <string>

using namespace std;

int n,l;
char word[21];
string s[50];
long long fact[21];
long long cantTell[1048576];

int main() {
    fact[0] = 1;
    for (int i=1;i<=20;i++) fact[i] = i*fact[i-1];
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        scanf(" %s",&word);
        s[i] = string(word);
    }
    l = s[0].size();
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            int same = 0;
            for (int k=0;k<l;k++) if (s[i][k]==s[j][k]) same|=1<<k;
            cantTell[same]|=((long long) 1)<<i;
            cantTell[same]|=((long long) 1)<<j;
        }
    }
    for (int i=(1<<l)-1;i>0;i--) for (int j=0;j<l;j++) if (i&(1<<j)) cantTell[i&(~(1<<j))]|=cantTell[i];
    double ans = 0;
    for (int i=1;i<(1<<l);i++) {
        int bits = 0;
        for (int j=0;j<n;j++) if (cantTell[i]&(((long long) 1)<<j)) bits+=1;
        int mbits = 0;
        for (int j=0;j<l;j++) if (i&(((long long) 1)<<j)) mbits+=1;
        ans+=(double) bits/n*fact[mbits]/fact[l]*fact[l-mbits];
    }
    printf("%1.12f\n",ans+(n>1 ? 1 : 0));

    return 0;
}