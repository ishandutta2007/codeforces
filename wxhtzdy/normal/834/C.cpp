#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int tt;scanf("%i",&tt);
    while(tt--){
        int a,b;scanf("%i%i",&a,&b);
        ll p=(ll)a*b;
        ll c=round(cbrt(p));
        if(c*c*c==p&&a%c==0&&b%c==0)printf("Yes\n");
        else printf("No\n");
    }
	return 0;
}