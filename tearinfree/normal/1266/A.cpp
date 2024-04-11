#include <bits/stdc++.h>
using namespace std;

char str[101];
int cnt[11];
int m[11] = {0, 4, 2, 0, 4, 2, 0, 4, 2, 0};

int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        memset(cnt,0,sizeof(cnt));
        scanf("%s",str);
        int n=strlen(str);
        for(int i=0;i<n;i++) cnt[str[i]-'0']++;
        
        if(!cnt[0]) {
            puts("cyan");
            continue;
        }
        cnt[0]--;
        int f=0;
        for(int i=0;i<10;i++) {
            int sum=0;
            for(int j=0;j<10;j++) {
                int c = cnt[j] - (i==j);
                if(c==-1) {
                    sum = 1;
                    break;
                }

                sum += m[j] * c;
                if(i==j) sum += j;
            }

            if(sum%6==0) f=1;
        }
        puts(f ? "red" : "cyan");
    }
    return 0;
}