#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int S,T;
int s[200013];
int t[200013];
int m[400013];
int Z[400013];
int has[200013];
vector<int> print;

int main() {
    scanf("%d%d",&S,&T);
    for (int i=0;i<S;i++) {
        char c;
        scanf(" %c",&c);
        s[i] = c-'a';
    }
    for (int i=0;i<T;i++) {
        char c;
        scanf(" %c",&c);
        t[i] = c-'a';
    }
    for (int a=0;a<26;a++) {
        for (int b=a;b<26;b++) {
            for (int i=0;i<S;i++) m[i+T+1] = (s[i]==a) ? 1 : (s[i]==b) ? 2 : 0;
            for (int i=0;i<T;i++) m[i] = (t[i]==b) ? 1 : (t[i]==a) ? 2 : 0;
            m[T] = -1;
            int num = 0;
            for (int i=0;i<T;i++) if (t[i]==a || t[i]==b) num+=1;
            if (num==0) continue;
            int L = 0;
            int R = 0;
            for (int i=1;i<S+T+1;i++) {
                if (i>R) {
                    L = i;
                    R = i;
                    while (m[R]==m[R-i]) R+=1;
                    R-=1;
                    Z[i] = R-L+1;
                } else {
                    int k = i-L;
                    if (Z[k]>=R-i+1) {
                        L = i;
                        while (m[R]==m[R-i]) R+=1;
                        R-=1;
                        Z[i] = R-L+1;
                    } else Z[i] = Z[k];
                }
            }
            for (int i=T+1;i<S+T+1;i++) if (Z[i]==T) has[i-T-1]+=num;
        }
    }
    for (int i=0;i<S;i++) if (has[i]==T) print.push_back(i);
    printf("%d\n",print.size());
    for (int i=0;i<print.size();i++) printf("%d ",print[i]+1);
    printf("\n");

    return 0;
}