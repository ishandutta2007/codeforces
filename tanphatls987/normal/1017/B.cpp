#include <bits/stdc++.h>

using namespace std;


typedef pair<int,int> ii;

#define X first
#define Y second
const int N=1e3+10;
int n,a[2][2];
string s1,s2;

long long solve(){
        long long ans=0;
        for(int u1=0;u1<=1;u1++)
                for(int u2=0;u2<=1;u2++)
                        for(int u3=0;u3<=1;u3++)
                                for(int u4=0;u4<=1;u4++){
                                        if (((u1|u4)!=(u3|u4))||((u3|u2)!=(u1|u2))){
                                                ans+=1LL*a[u1][u2]*a[u3][u4];
                                        }
                                }
         return ans/2;
}
int main(){
        cin>>n>>s1>>s2;
        for(int i=0;i<n;i++)
                a[s1[i]-'0'][s2[i]-'0']++;
        cout<<solve();
}