#include <bits/stdc++.h>
using namespace std;
const int N=100050;
int a[N];
int main(){
    int n;scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&a[i]);
    for(int i=1;i<=n;i++)while(a[i]%2==0)a[i]/=2;
    for(int i=1;i<=n;i++)while(a[i]%3==0)a[i]/=3;
    set<int> s(a+1,a+n+1);
    if((int)s.size()==1)printf("Yes");
    else printf("No");
}