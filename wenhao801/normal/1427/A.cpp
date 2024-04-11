#include <iostream>
#include<algorithm>
using namespace std;
 
int T, a[55], N;
int main() {
    cin >>T;
    while(T--) {
        cin>>N; int sum=0;
        for(int i=1;i<=N;++i)cin>>a[i], sum+=a[i];
        if(sum == 0) puts("NO");
        else {
            if(sum>0) {
                sort(a+1,a+N+1,greater<int>());
            } else{
                sort(a+1,a+N+1);
            }puts("YES");
            for(int i=1;i<=N;++i)cout<<a[i]<< ' ';
        
            cout<<endl;
        }
    }
    return 0;
}