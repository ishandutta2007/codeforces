#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int len;
char s[100013];
int Z[100013];

int main() {
    scanf(" %s",&s);
    len = strlen(s);
    s[len] = '#';
    int L = 0;
    int R = 0;
    for (int i=1;i<len;i++) {
        if (i>R) {
            L = i;
            R = i;
            while (s[R]==s[R-i]) R+=1;
            R-=1;
            Z[i] = R-L+1;
        } else {
            int k = i-L;
            if (Z[k]>=R-i+1) {
                L = i;
                while (s[R]==s[R-i]) R+=1;
                R-=1;
                Z[i] = R-L+1;
            } else Z[i] = Z[k];
        }
    }
    int k = 1;
    int nums[len];
    fill(nums,nums+len,0);
    for (int i=1;i<len;i++) {
        if (Z[i]==len-i) k+=1;
        nums[Z[i]]+=1;
    }
    for (int i=len-2;i>0;i--) nums[i]+=nums[i+1];
    printf("%d\n",k);
    for (int i=len-1;i>0;i--) if (Z[i]==len-i) printf("%d %d\n",Z[i],nums[Z[i]]+1);
    printf("%d %d\n",len,1);

    return 0;
}