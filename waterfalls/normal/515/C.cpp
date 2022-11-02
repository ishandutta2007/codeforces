#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
char num[16];
int counts[10];

int main() {
    scanf("%d %s",&n,&num);
    for (int i=0;i<n;i++) {
        if (num[i]=='0' || num[i]=='1') continue;
        if (num[i]=='2' || num[i]=='3' || num[i]=='5' || num[i]=='7') counts[num[i]-'0']+=1;
        if (num[i]=='4') {
            counts[2]+=2;
            counts[3]+=1;
        }
        if (num[i]=='6') {
            counts[3]+=1;
            counts[5]+=1;
        }
        if (num[i]=='8') {
            counts[2]+=3;
            counts[7]+=1;
        }
        if (num[i]=='9') {
            counts[2]+=1;
            counts[3]+=2;
            counts[7]+=1;
        }
    }
    for (int i=9;i>=2;i--) for (int j=0;j<counts[i];j++) printf("%d",i);
    printf("\n");

    return 0;
}