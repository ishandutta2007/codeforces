#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

long long C,Hr,Hb,Wr,Wb;

int main() {
    scanf("%I64d%I64d%I64d%I64d%I64d",&C,&Hr,&Hb,&Wr,&Wb);
    if (Wb<Wr) {
        swap(Wb,Wr);
        swap(Hb,Hr);
    }
    long long ans = 0;
    if (Wb>1000) {
        for (long long i=0;Wb*i<=C;i++) {
            ans = max(ans,Hb*i+(C-Wb*i)/Wr*Hr);
        }
    } else {
        if (Hr*Wb<Hb*Wr) {
            swap(Wb,Wr);
            swap(Hb,Hr);
        }
        long long num = C/Wr;
        for (long long i=0;i<=min(10000LL,num);i++) {
            ans = max(ans,(num-i)*Hr+(C-(num-i)*Wr)/Wb*Hb);
        }
    }
    printf("%I64d\n",ans);

    return 0;
}