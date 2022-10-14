#include <bits/stdc++.h>
using namespace std;
bool Prime(int n){
    for(int i=2;i<=sqrt(n);i++)if(n%i==0)return 0;
    return 1;
}
int main(){
    int n;scanf("%i",&n);
    set<int> s;
    for(int i=2;i<=n;i++){
        if(!Prime(i))continue;
        int pw=i*i;
        while(pw<=n)s.insert(pw),pw*=i;
    }
    for(int i=2;i<=n;i++)if(Prime(i))s.insert(i);
    printf("%i\n",(int)s.size());
    for(int c:s)printf("%i ",c);
    return 0;
}