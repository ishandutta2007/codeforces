#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;

int a[2005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    if(0) {

    } else if(n==1) {
        puts("0");
    } else {
        int idx = 2333;
        cout<<n+1<<endl;
        for(int i=n;i>=1;--i) {
            idx--;
            int num = 2333+idx-a[i]%2333;
            for(int j=1;j<=i;++j) a[j]+=num;
            cout<<1<<" "<<i<<" "<<num<<endl;
        }
        for(int i=1;i<=n;++i) a[i]%=2333;
        cout<<2<<" "<<n<<" "<<2333<<endl;
    }
}