#include <bits/stdc++.h>
using namespace std;
int n,l1,l2,a[110];
int main(void){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf ("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%1d",&a[i]);
        if(a[i]&&!l1)l1=i;
        else if (a[i]&&!l2)l2=i;
    }
    for (int i=l2+1;i<=n;i++)if (a[i]&&i-l2==l2-l1)l1=l2,l2=i;
    else if(a[i])return !printf ("NO");
    printf ("YES");
}