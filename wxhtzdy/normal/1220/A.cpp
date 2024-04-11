#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%i",&n);
    char a[n];
    scanf("%s",&a);
    int cnt1=0,cnt0=0;
    for(int i=0;i<n;i++){
        char c=a[i];
        if(c=='z')cnt0++;
        if(c=='n')cnt1++;
    }
    while(cnt1--)printf("1 ");
    while(cnt0--)printf("0 ");
}