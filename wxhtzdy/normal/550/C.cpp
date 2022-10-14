#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=(int)s.length();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=j;k<n;k++){
                int h=(int)(s[i]-'0');
                int h1=(int)(s[j]-'0');
                int h2=(int)(s[k]-'0');
                int num=h;
                if(i!=j)num*=10,num+=h1;
                if(j!=k)num*=10,num+=h2;
                if(num%8==0){printf("YES\n%i",num);return 0;}
            }
        }
    }
    printf("NO");
}