#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n,a[N],b[N];
int main(){
    int t;scanf("%i",&t);
    while(t--){
        scanf("%i",&n);
        for(int i=1;i<=n;i++)scanf("%i",&a[i]);
        for(int i=1;i<=n;i++)scanf("%i",&b[i]);
        for(int i=1;i<=n;i++)if(a[i]>b[i])swap(a[i],b[i]);
        int mx=*max_element(a+1,a+n+1),my=*max_element(b+1,b+n+1);
        printf("%i\n",mx*my);
    }
	return 0;
}