#include<cstdio>
#include<algorithm>

using namespace std;
typedef long long int lint;

int maxdigit(lint n){
    int ans=0;
    while(n>0){
        int curr=n%10;
        ans=max(curr,ans);
        n/=10;
    }
    return ans;
}

lint n;

int main(){
    scanf("%lld",&n);
    lint cnt=0;
    while(n>0){
        n-=maxdigit(n);
        cnt++;
    }
    printf("%lld\n",cnt);
    return 0;
}