#include <bits/stdc++.h>

using namespace std;

const string day[7]={"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
const int re[3]={28, 31, 30};

int convert(string s){
    int ans=0;
    while (day[ans]!=s) ans++;
    return ans;
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int v1=convert(s1),v2=convert(s2);
    for(int i=0;i<=2;i++)
        if ((v1+re[i])%7==v2) {
            printf("YES");
            return 0;
        }
    printf("NO");
}