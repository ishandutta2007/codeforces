#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define VI vector<int>
#define ULL unsigned long long
#define mem(a) memset(a,0,sizeof(a))
#define range(a) a.begin(), a.end()

using namespace std;

long long n,q;
int main(){
    cin>>n;
    q=sqrt(n);
    for (int i=2;i<=q;++i){
        if (n%i==0){
            while (n%i==0) n/=i;
            if (n>1){
                printf("1");
                return 0;
            }
            else{
                printf("%d",i);
                return 0;
            }
        }
    }
    printf("%lld",n);
    return 0;
}