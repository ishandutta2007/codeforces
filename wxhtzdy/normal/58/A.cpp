#include <bits/stdc++.h>
using namespace std;
int main(){
    char a[200];
    scanf("%s",&a);
    int n=strlen(a);
    map<char,int> mp;
    bool h=false,e=false,l1=false,l2=false,o=false;
    for (int i=0;i<n;i++){
        if(a[i]=='h')h=true;
        if(a[i]=='e'&&h==true)e=true;
        if(a[i]=='l'&&l1==true)l2=true;
        if(a[i]=='l'&&e==true)l1=true;
        if(a[i]=='o'&&l2==true)o=true;
    }
    if(o)printf("YES");
    else printf("NO");
    return 0;
}