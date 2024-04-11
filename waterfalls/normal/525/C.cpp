#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int num[1000013];
bool num2[1000013];

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        int l;
        scanf("%d",&l);
        num[l]+=1;
    }
    long long ans = 0;
    int prev = -1;
    for (int i=1000000;i>0;i--) {
        if (prev!=-1 && num[i]+num2[i]>=2) {
            if (num2[i]==0) num[i]-=2;
            else num[i]-=1, num2[i] = 0;
            ans+=(long long) i*prev;
            prev = -1;
        }
        ans+=(long long) i*i*((num[i]+num2[i])/4);
        if (num[i]>=4 && num[i]%4==0 && num2[i]) num2[i]-=1, num[i]+=1;
        num[i]%=4;
        if (num[i]==3 && num2[i]==1) num[i] = 0, num2[i] = 0;
        if (num[i]%2==1 && num2[i]==0) num2[i-1]+=1,num[i]-=1;
        if (num[i]==2 && num2[i]==1) num2[i-1]+=1,num[i]-=1;
        if (num[i]+num2[i]==2) prev = i;
    }
    printf("%I64d\n",ans);

    return 0;
}