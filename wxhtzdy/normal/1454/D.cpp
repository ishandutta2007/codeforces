#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n){
    for(long long i=2;i<=sqrt(n);i++){
        if(n%i==0)return 0;
    }
    return 1;
}
vector<pair<long long,long long>> all;
void factorize(long long n)
{
    int count = 0;

    // count the number of times 2 divides
    while (!(n % 2)) {
        n >>= 1; // equivalent to n=n/2;
        count++;
    }

    // if 2 divides it
    if (count)
        all.push_back({2,count});//cout << 2 << "  " << count << endl;

    // check for all the possible numbers that can
    // divide it
    for (long long i = 3; i <= sqrt(n); i += 2) {
        count = 0;
        while (n % i == 0) {
            count++;
            n = n / i;
        }
        if (count)
            all.push_back({i,count});//cout << i << "  " << count << endl;
    }

    // if n at the end is a prime number.
    if (n > 2)
        all.push_back({n,1});//cout << n << "  " << 1 << endl;
}
bool cmp(pair<long long,long long> x,pair<long long,long long> y){
    if(x.second!=y.second)return x.second>y.second;
    return x.first<y.first;
}
int main(){
    /*const int N=100050;
    int div[N];
    for(int i=0;i<N;i++)div[i]=i;
    for(int i=2;i<N;i++){
        if(div[i]!=i)continue;
        for(int j=i+i;j<N;j+=i)if(div[j]==j)div[j]=i;
    }*/
    int t;
    scanf("%i",&t);
    while(t--){
        long long n;
        scanf("%lld",&n);
        if(isPrime(n)){
            printf("1\n%lld\n",n);
            continue;
        }
        /*vector<long long> v;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                v.push_back(i);
                n/=i;
                break;
            }
        }*/
        factorize(n);
        sort(all.begin(),all.end(),cmp);
        vector<long long> ans;
        //for(auto c:all)printf("%lld %lld\n",c.first,c.second);
        for(int i=0;i<all[0].second-1;i++)ans.push_back(all[0].first);
        long long ost=all[0].first;
        for(int i=1;i<(int)all.size();i++)for(int j=0;j<all[i].second;j++)ost*=all[i].first;
        ans.push_back(ost);
        printf("%i\n",(int)ans.size());
        for(auto c:ans)printf("%lld ",c);
        printf("\n");
        all.clear();
    }
}