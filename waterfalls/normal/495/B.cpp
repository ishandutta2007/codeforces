#include <cstdio>
#include <vector>

using namespace std;

int a,b,ans;
vector<int> primes;
vector<int> occur;

int check(int level,int cur) {
    if (level==primes.size()) {
        if (cur>b) ans+=1;
    } else {
        for (int i=0;i<=occur[level];i++) {
            check(level+1,cur);
            cur*=primes[level];
        }
    }
}

int main() {
    scanf("%d%d",&a,&b);
    if (a==b) printf("infinity\n");
    else if (b>a) printf("0\n");
    else {
        int factor = a-b;
        for (int i=2;i*i<=a-b;i++) {
            if (factor%i==0) {
                primes.push_back(i);
                occur.push_back(0);
                while (factor%i==0) {
                    factor/=i;
                    occur[occur.size()-1]+=1;
                }
            }
        }
        if (factor>1) {
            primes.push_back(factor);
            occur.push_back(1);
        }
        ans = 0;
        check(0,1);
        printf("%d\n",ans);
    }

    return 0;
}